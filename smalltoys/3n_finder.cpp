/*你有一个 n x 3 的网格图 grid ，你需要用 红，黄，绿 三种颜色之一给每一个格子上色，且确保相邻格子颜色不同（也就是有相同水平边或者垂直边的格子颜色不同）。

给你网格图的行数 n 。

请你返回给 grid 涂色的方案数。由于答案可能会非常大，请你返回答案对 10^9 + 7 取余的结果。

 */
#include <bits/stdc++.h>
using namespace std;
int n;
vector<string> rowStates; // 3位字符串, 表示一行

// 检查上一行和当前行是否每列不同色
bool valid(const string& a, const string& b) {
    for (int i=0; i<3; ++i)
        if (a[i]==b[i]) return false;
    return true;
}

void dfs(int row, vector<string>& rows, int& total) {
    if (row == rows.size()) {
        total++;
        return;
    }
    for (const auto& state : rowStates) {
        if (row == 0 || valid(state, rows[row-1])) {
            rows[row] = state;
            dfs(row + 1, rows, total);
        }
    }
}

int main() {
    cin >> n;
    // 生成所有合法的单行染色方式
    vector<char> color = {'r','y','g'};
    for (char c1 : color)
        for (char c2 : color) if (c2 != c1)
            for (char c3 : color) if (c3 != c2 && c3 != c1)
                rowStates.push_back({c1,c2,c3});

    for(int rows=1; rows<=n; ++rows) {
        vector<string> grid(rows);
        int total = 0;
        dfs(0, grid, total);
        cout << "行数 " << rows << " : 方案总数 " << total << endl;
    }
    return 0;
}