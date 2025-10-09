/*算特别大的数
法一：用python
法二：vector模拟*/
/*

#include <bits/stdc++.h>
#include <gmp.h> 
using namespace std;
 void factorial(mpz_t result,int x){
    mpz_t shu;/*声明
    mpz_init(shu);/*初始化
    mpz_set_ui(shu,0);/*设置
    for (int i=1;i<=x;i++){
    mpz_mul_ui(shu,shu,i);/*(result,乘数1，乘数2)
    
    }
}
int main(){
    mpz_t n;
    mpz_t sb,temp;
    mpz_init(sb);
    mpz_set_ui(sb,0);
    cin>>n;
    mpz_t i;
    mpz_init(i);
for( mpz_set_ui(i,0);i<=n;i++){
factorial(temp,i);
mpz_add(sb,sb,temp);
}
gmp_printf("%Z\n", sb);
return 0;
}
放弃了，mpz_t太难用了*/
/*
#include <bits/stdc++.h>
#include <gmp.h>
#include <iostream>  // 确保 cin/cout 可用

using namespace std;

void factorial(mpz_t result, int x) {  // void，返回类型改为 void，原地计算
    mpz_set_ui(result, 1);  // 起始值为 1（0! = 1）
    for (int i = 1; i <= x; ++i) {
        mpz_mul_ui(result, result, i);  // result *= i
    }
}

int main() {
    mpz_t n, sb, temp;  // 声明
    mpz_inits(n, sb, temp, NULL);  // 批量初始化
    
    mpz_set_ui(sb, 0);  // sb = 0
    
    // GMP 输入：读取 n（int 范围足够，但用 mpz_t 通用）
    gmp_scanf("%Zd", n);  // 从 stdin 读取 n（如输入 5）
    
    // 转换为 int（假设 n 小；大 n 用 mpz 循环，但复杂）
    int max_n;
    if (mpz_cmp_ui(n, INT_MAX) > 0) {
        // 错误处理：n 太大
        gmp_printf("n too large\n");
        mpz_clears(n, sb, temp, NULL);
        return 1;
    }
    max_n = mpz_get_ui(n);  // 获取 int 值
    
    for (int i = 1; i <= max_n; ++i) {  // 用 int 循环，简单高效
        factorial(temp, i);     // 计算 i! 到 temp
        mpz_add(sb, sb, temp);  // sb += temp
    }
    
    gmp_printf("%Zd\n", sb);  // %Zd 输出十进制，并换行
    
    mpz_clears(n, sb, temp, NULL);  // 清理内存
    return 0;
}

/*也可以这样*/
#include <bits/stdc++.h>
using namespace std;

// 大整数类（简化版，只需加法和乘小整数）
class BigInt {
public:
    vector<int> digits;  // 低位先存

    BigInt() { digits = {0}; }
    BigInt(long long x) {
        if (x == 0) digits = {0};
        while (x > 0) {
            digits.push_back(x % 10);
            x /= 10;
        }
    }

    // 加法：this += other
    void add(const BigInt& other) {
        int carry = 0, i = 0;
        while (i < digits.size() || i < other.digits.size() || carry) {
            if (i == digits.size()) digits.push_back(0);
            int sum = carry + digits[i];
            if (i < other.digits.size()) sum += other.digits[i];
            digits[i] = sum % 10;
            carry = sum / 10;
            ++i;
        }
    }

    // 乘小整数（unsigned long long k，通常 k=i <=n）
    void mul(unsigned long long k) {
        unsigned long long carry = 0;
        for (size_t i = 0; i < digits.size() || carry; ++i) {
            if (i == digits.size()) digits.push_back(0);
            unsigned long long prod = digits[i] * k + carry;
            digits[i] = prod % 10;
            carry = prod / 10;
        }
    }

    // 输出
    string toString() const {
        if (digits.empty() || (digits.size() == 1 && digits[0] == 0)) return "0";
        string s;
        for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
            s += '0' + *it;
        }
        return s;
    }
};

// 阶乘函数：计算 x! 到 result
void factorial(BigInt& result, int x) {
    result = BigInt(1);  // 1!
    for (int i = 2; i <= x; ++i) {  // 从 2 开始乘
        result.mul(i);
    }
}

int main() {
    int n;
    cin >> n;
    BigInt sum(0);  // 总和

    for (int i = 1; i <= n; ++i) {
        BigInt fact;
        factorial(fact, i);
        sum.add(fact);
    }

    cout << sum.toString() << endl;
    return 0;
}