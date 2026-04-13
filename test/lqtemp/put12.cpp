#include <bits/stdc++.h>
using namespace std;

static const int W = 8;
static const int H = 8;

using ull = unsigned long long;

void dfs_fill_row(int pos, int curMask, int nextMask, ull ways,
                  vector<ull> &dpNext) {
    // 找到本行从 pos 开始的第一个未占用格
    while (pos < W && (curMask & (1 << pos))) pos++;

    if (pos == W) {
        // 本行填完了，累加到下一行状态
        dpNext[nextMask] += ways;
        return;
    }

    // 尝试放横牌：占用 pos 和 pos+1（都必须空）
    if (pos + 1 < W && !(curMask & (1 << (pos + 1)))) {
        int newMask = curMask | (1 << pos) | (1 << (pos + 1));
        dfs_fill_row(pos + 2, newMask, nextMask, ways, dpNext);
    }

    // 尝试放竖牌：占用 pos（本行）和下一行的 pos
    // 竖牌意味着下一行该列被占用 => nextMask 置 1
    int newMask = curMask | (1 << pos);
    dfs_fill_row(pos + 1, newMask, nextMask | (1 << pos), ways, dpNext);
}

int main() {
    vector<ull> dp(1 << W, 0), dpNext(1 << W, 0);
    dp[0] = 1;

    for (int r = 0; r < H; r++) {
        fill(dpNext.begin(), dpNext.end(), 0);

        for (int mask = 0; mask < (1 << W); mask++) {
            ull ways = dp[mask];
            if (!ways) continue;

            // curMask 表示本行已被占用的位置（来自上一行的竖牌）
            int curMask = mask;

            // 在最后一行不允许再放竖牌，所以需要特判：这里把 dfs 写成总是允许竖牌，
            // 但我们在最后一行时，要求 nextMask 最终必须为 0 且不能放竖牌。
            // 更简单：最后一行时，禁止竖牌。
            if (r == H - 1) {
                // 最后一行只能用横牌把 0 填满，因此 nextMask 必须为 0
                function<void(int,int,ull)> dfsLast = [&](int pos, int cm, ull w){
                    while (pos < W && (cm & (1<<pos))) pos++;
                    if (pos == W) { dpNext[0] += w; return; }
                    if (pos + 1 < W && !(cm & (1<<(pos+1)))) {
                        int nm = cm | (1<<pos) | (1<<(pos+1));
                        dfsLast(pos+2, nm, w);
                    }
                };
                dfsLast(0, curMask, ways);
            } else {
                dfs_fill_row(0, curMask, 0, ways, dpNext);
            }
        }

        dp.swap(dpNext);
    }

    cout << dp[0] << "\n"; // 12988816544064
    return 0;
}