#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    vector<int> ns(T);
    int Nmax = 0;
    for (int i = 0; i < T; i++) {
        cin >> ns[i];
        Nmax = max(Nmax, ns[i]);
    }

    const int cost[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    const int INF = 1e9;

    vector<int> dp(Nmax + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= Nmax; i++) {
        for (int d = 0; d <= 9; d++) {
            if (i >= cost[d] && dp[i - cost[d]] != INF) {
                dp[i] = min(dp[i], dp[i - cost[d]] + 1);
            }
        }
    }

    for (int n : ns) {
        if (n < 2 || dp[n] == INF) {
            cout << -1 << "\n";
            continue;
        }

        string ans;
        int rem = n;
        while (rem > 0) {
            int start = ans.empty() ? 1 : 0;
            bool picked = false;
            for (int d = start; d <= 9; d++) {
                if (rem >= cost[d] && dp[rem] == dp[rem - cost[d]] + 1) {
                    ans.push_back(char('0' + d));
                    rem -= cost[d];
                    picked = true;
                    break;
                }
            }
            if (!picked) {
                ans = "-1";
                break;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}