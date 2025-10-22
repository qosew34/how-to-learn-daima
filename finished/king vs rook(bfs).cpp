#include <bits/stdc++.h>
using namespace std;

int rook;
vector<int> rx, ry;
queue<pair<int,int>> q;
vector<vector<int>> board(9, vector<int>(9, 0)); // 棋盘

void judge(int x, int y) {
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int nx = x + i, ny = y + j;
            if (nx < 0 || ny < 0 || nx >= 9 || ny >= 9) continue;

            if (board[nx][ny] == 2) { // 吃掉车
                board[nx][ny] = 0;
                for (int k = 0; k < 9; k++) {
                    board[nx][k]++;
                    board[k][ny]++;
                }
                rook--;
            }

            if (board[nx][ny] == 0) {
                q.push({nx, ny});
                board[nx][ny] = 1;
            }
        }
    }
}

// -1 不可达, 1 走过, 0 可达, 2 车
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int sx, sy;
        cin >> sx >> sy;

        rook = n;
        rx.clear();
        ry.clear();
        board.assign(9, vector<int>(9, 0));

        // 边界设置为不可达
        for (int k = 0; k < 9; k++) {
            board[0][k] = board[k][0] = -1000;
        }

        for (int j = 0; j < n; j++) {
            int x, y;
            cin >> x >> y;
            rx.push_back(x);
            ry.push_back(y);
            board[x][y] = 2; // 车的位置
        }

        board[sx][sy] = 1;
        while (!q.empty()) q.pop();
        q.push({sx, sy});

        while (!q.empty()) {
            auto [tx, ty] = q.front(); q.pop();
            judge(tx, ty);
            if (rook == 0) {
                cout << "YES\n";
                goto next_case;
            }
        }
        cout << "NO\n";
        next_case:;
    }
    return 0;
}
