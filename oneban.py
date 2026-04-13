import akshare as ak
import pandas as pd
from datetime import datetime, timedelta

# =========================
# 参数设置
# =========================
# 近三个月
end_date = datetime.today()
start_date = end_date - timedelta(days=90)

start_str = start_date.strftime("%Y%m%d")
end_str = end_date.strftime("%Y%m%d")

print(f"数据区间: {start_str} - {end_str}")

# =========================
# 获取股票列表（主板 + 非ST）
# =========================
stock_list = ak.stock_info_a_code_name()

def is_main_board(code):
    # 沪主板：600/601/603/605
    # 深主板：000/001
    return (
        code.startswith("600") or
        code.startswith("601") or
        code.startswith("603") or
        code.startswith("605") or
        code.startswith("000") or
        code.startswith("001")
    )

def is_not_st(name):
    return ("ST" not in name) and ("*ST" not in name)

stock_list = stock_list[
    stock_list["code"].apply(is_main_board) &
    stock_list["name"].apply(is_not_st)
].reset_index(drop=True)

print(f"筛选后股票数量: {len(stock_list)}")

# =========================
# 核心筛选逻辑
# =========================
result = []

for idx, row in stock_list.iterrows():
    code = row["code"]
    name = row["name"]

    try:
        df = ak.stock_zh_a_hist(
            symbol=code,
            period="daily",
            start_date=start_str,
            end_date=end_str,
            adjust="qfq"
        )

        if df is None or len(df) < 5:
            continue

        # 重命名列（AKShare返回中文列）
        df.rename(columns={
            "日期": "date",
            "开盘": "open",
            "收盘": "close",
            "最高": "high",
            "最低": "low",
            "成交量": "volume"
        }, inplace=True)

        # 排序
        df.sort_values("date", inplace=True)
        df.reset_index(drop=True, inplace=True)

        # 前一日收盘
        df["prev_close"] = df["close"].shift(1)

        # 涨停价（主板10%）
        df["limit_up"] = df["prev_close"] * 1.1

        # 判断一字涨停
        df["one_word"] = (
            (df["open"] == df["high"]) &
            (df["high"] == df["low"]) &
            (df["low"] == df["close"]) &
            (df["close"] >= df["limit_up"] * 0.995)  # 容忍误差
        )

        # 查找满足条件的日期
        for i in range(len(df) - 1):
            if df.loc[i, "one_word"] and not df.loc[i + 1, "one_word"]:
                result.append({
                    "code": code,
                    "name": name,
                    "one_word_date": df.loc[i, "date"],
                    "next_date": df.loc[i + 1, "date"],
                    "next_open": df.loc[i + 1, "open"],
                    "next_close": df.loc[i + 1, "close"]
                })
                break

    except Exception as e:
        print(f"{code} 出错: {e}")
        continue

# =========================
# 输出结果
# =========================
result_df = pd.DataFrame(result)

print("\n筛选结果：")
print(result_df)

# 保存为CSV
result_df.to_csv("one_word_limit_up.csv", index=False, encoding="utf-8-sig")

print("\n已保存为 one_word_limit_up.csv")