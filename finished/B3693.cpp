#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    cin >> t;
    while (t--) {
        int n, m, q;
        cin >> n >> m >> q;

        vector<vector<ull>> a(n, vector<ull>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];

        vector<vector<ull>> pre(n + 1, vector<ull>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                pre[i][j] = a[i - 1][j - 1]
                          + pre[i - 1][j]
                          + pre[i][j - 1]
                          - pre[i - 1][j - 1];
            }
        }

        ull ans = 0;
        for (int i = 0; i < q; i++) {
            int u, v, x, y;
            cin >> u >> v >> x >> y; 
            ull s = pre[x][y]
                  - pre[u - 1][y]
                  - pre[x][v - 1]
                  + pre[u - 1][v - 1];

            ans ^= s;
        }

        cout << ans << endl;
    }
}