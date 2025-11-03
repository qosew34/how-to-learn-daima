#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int d, g;
    if (!(cin >> d >> g)) return 0;
    vector<int> prev(d, -1);
    prev[0] = 10;
    int pre_time = 0;
    vector<tuple<int,int,int>> rubbish;
    for (int i = 0; i < g; ++i) {
        int t, f, h;
        cin >> t >> f >> h;
        rubbish.emplace_back(t, f, h);
    }
    sort(rubbish.begin(), rubbish.end());
    const int INF_NEG = -1;

    // 初始化 best_survive 为初始状态能活到的绝对时间
    long long best_survive = -1;
    for (int i = 0; i < d; ++i) {
        if (prev[i] != INF_NEG) best_survive = max(best_survive, (long long)pre_time + prev[i]);
    }

    for (auto &tp : rubbish) {
        int t, f, h;
        tie(t, f, h) = tp;
        int dt = t - pre_time;
        vector<int> next(d, INF_NEG);
        for (int i = 0; i < d; ++i) {
            if (prev[i] == INF_NEG) continue;
            int remaining = prev[i] - dt;
            if (remaining < 0) continue; // 在到达该时间点之前会饿死，不能继续该状态
            // 不动（既不吃也不堆）
            if (next[i] < remaining) {
                next[i] = remaining;
                best_survive = max(best_survive, (long long)t + remaining);
            }
            // 吃掉当前这件垃圾（停在同一高度）
            int val_eat = remaining + f;
            if (next[i] < val_eat) {
                next[i] = val_eat;
                best_survive = max(best_survive, (long long)t + val_eat);
            }
            // 堆放这件垃圾（不消耗时间）
            int nh = i + h;
            if (nh >= d) {
                // 立即逃出，输出当前事件时间
                cout << t << '\n';
                return 0;
            } else {
                if (next[nh] < remaining) {
                    next[nh] = remaining;
                    best_survive = max(best_survive, (long long)t + remaining);
                }
            }
        }
        prev.swap(next);
        pre_time = t;
    }

    // 遍历完所有垃圾仍未逃出，输出最晚存活时间（绝对时间点）
    if (best_survive >= 0) cout << best_survive << '\n';
    return 0;
}