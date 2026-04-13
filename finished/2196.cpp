#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> count(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> count[i];

    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int temp; cin >> temp;
            if (temp == 1) adj[i].push_back(j);
        }
    }

    vector<pair<int, vector<int>>> dp(n + 1);
    for (int i = 1; i <= n; i++) dp[i] = {count[i], {i}};

    int ans = dp[1].first, loc = 1;

    for (int i = 1; i <= n; i++) {
        if (dp[i].first > ans) { ans = dp[i].first; loc = i; }

        for (int a : adj[i]) {
            if (dp[i].first + count[a] > dp[a].first) {
                dp[a].first = dp[i].first + count[a];
                dp[a].second = dp[i].second;
                dp[a].second.push_back(a);

                if (dp[a].first > ans) {
                    ans = dp[a].first;
                    loc = a;
                }
            }
        }
    }

    for (int x : dp[loc].second) cout << x << " ";
    cout << "\n" << ans << "\n";
}