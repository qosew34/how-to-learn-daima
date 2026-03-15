#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        // planes[i] = {Ti, Di, Li}
        vector<array<long long, 3>> planes(n);
        for (int i = 0; i < n; i++) {
            cin >> planes[i][0] >> planes[i][1] >> planes[i][2];
        }

        // 初始全 0 状态字符串
        string zero(n, '0');

        unordered_map<string, long long> best;
        best.max_load_factor(0.7f);

        queue<pair<string, long long>> q;

        best[zero] = 0;
        q.push({zero, 0});

        bool can = false;

        while (!q.empty() && !can) {
            auto [state, end_time] = q.front();
            q.pop();

            auto it = best.find(state);
            if (it == best.end() || it->second != end_time) continue;

            bool all_done = true;
            for (int i = 0; i < n; i++) {
                if (state[i] == '0') { all_done = false; break; }
            }
            if (all_done) {
                can = true;
                break;
            }

            // 尝试安排下一架没降落的飞机 i
            for (int i = 0; i < n; i++) {
                if (state[i] == '1') continue;

                long long Ti = planes[i][0];
                long long Di = planes[i][1];
                long long Li = planes[i][2];

                long long r = Ti;         // 最早开始
                long long s = Ti + Di;    // 最晚开始
                long long start = max(end_time, r);

                if (start > s) continue; 

                long long new_end = start + Li;

                string next = state;
                next[i] = '1';

                auto it2 = best.find(next);
                if (it2 == best.end() || new_end < it2->second) {
                    best[next] = new_end;
                    q.push({next, new_end});
                }
            }
        }

        cout << (can ? "YES\n" : "NO\n");
    }
    return 0;
}