#include <bits/stdc++.h>
using namespace std;

int b[5][5];
long long ans = 0;

inline bool badRow(int r) {
    int v = b[r][0];
    for (int c = 1; c < 5; c++) if (b[r][c] != v) return false;
    return true;
}

inline bool badCol(int c) {
    int v = b[0][c];
    for (int r = 1; r < 5; r++) if (b[r][c] != v) return false;
    return true;
}

inline bool badDiagMain() {
    int v = b[0][0];
    for (int i = 1; i < 5; i++) if (b[i][i] != v) return false;
    return true;
}

inline bool badDiagAnti() {
    int v = b[0][4];
    for (int i = 1; i < 5; i++) if (b[i][4 - i] != v) return false;
    return true;
}

void dfs(int idx, int ones, int zeros) {
    // 数量剪枝
    if (ones > 13) return;
    if (ones + (25 - idx) < 13) return; // 剩下全填1也不够13

    if (idx == 25) {
        if (ones == 13) ans++;
        return;
    }

    int r = idx / 5;
    int c = idx % 5;

    // 尝试填 0 和 1
    for (int v = 0; v <= 1; v++) {
        b[r][c] = v;

        // 成线剪枝：只在刚填满时检查
        if (c == 4 && badRow(r)) continue;
        if (r == 4 && badCol(c)) continue;
        if (idx == 24 && badDiagMain()) continue;
        if (idx == 20 && badDiagAnti()) continue;

        if (v == 1) dfs(idx + 1, ones + 1, zeros);
        else        dfs(idx + 1, ones, zeros + 1);
    }
}

int main() {
    dfs(0, 0, 0);
    cout << ans << "\n";
    return 0;
}