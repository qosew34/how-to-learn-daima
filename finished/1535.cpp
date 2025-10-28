#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, t;
    if (!(cin >> n >> m >> t)) return 0;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) cin >> grid[i];

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    // 如果输入是 1-based，需要转换为 0-based。若题目已经是 0-based，请去掉下面两行的减一。
    --x1; --y1; --x2; --y2;

    // 边界 / 障碍检查
    if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= m || x2 < 0 || x2 >= n || y2 < 0 || y2 >= m) {
        cout << 0 << '\n';
        return 0;
    }
    if (grid[x1][y1] == '*' || grid[x2][y2] == '*') {
        cout << 0 << '\n';
        return 0;
    }

    // 先用曼哈顿距离与奇偶性快速剪枝
    int dist = abs(x1 - x2) + abs(y1 - y2);
    if (dist > t || (dist % 2) != (t % 2)) {
        cout << 0 << '\n';
        return 0;
    }

    // 使用 long long 存路径数（若题目要求模数，请在累加时取模）
    vector<vector<long long>> dp(n, vector<long long>(m, 0));
    vector<vector<long long>> ndp(n, vector<long long>(m, 0));
    dp[x1][y1] = 1;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    for (int step = 1; step <= t; ++step) {
        for (int i = 0; i < n; ++i) fill(ndp[i].begin(), ndp[i].end(), 0);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (dp[i][j] == 0) continue;
                long long ways = dp[i][j];
                for (int k = 0; k < 4; ++k) {
                    int ni = i + dx[k], nj = j + dy[k];
                    if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                    if (grid[ni][nj] == '*') continue;
                    ndp[ni][nj] += ways;

                }
            }
        }
        dp.swap(ndp);
    }

    cout << dp[x2][y2] << '\n';
    return 0;
}//有些小错误，懒得改了，让ai改