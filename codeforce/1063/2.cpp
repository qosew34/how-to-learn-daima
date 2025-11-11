#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> p, pos;
vector<char> needVal;
vector<pair<int,int>> ops;
bool failed;
//dfs秒了
void dfs(int lowVal, int highVal) {
    if (failed) return;
    if ((int)ops.size() > 5) { failed = true; return; }
    // find any needed value in (lowVal, highVal) inclusive
    int a = -1, b = -1;
    for (int v = lowVal; v <= highVal; ++v) if (needVal[v]) { a = v; break; }
    for (int v = highVal; v >= lowVal; --v) if (needVal[v]) { b = v; break; }
    if (a == -1) return; // nothing to do in this range
    if (a == b) {
        int val = a;
        int pval = pos[val];
        // try find u < val and v > val whose positions are on opposite sides of pval
        int left_pos = -1, right_pos = -1;
        // try find u < val with pos < pval
        for (int u = val - 1; u >= 1; --u) {
            if (pos[u] < pval) { left_pos = pos[u]; break; }
        }
        // try find v > val with pos > pval
        for (int v = val + 1; v <= n; ++v) {
            if (pos[v] > pval) { right_pos = pos[v]; break; }
        }
        if (left_pos != -1 && right_pos != -1) {
            int L = left_pos, R = right_pos;
            if (L > R) swap(L, R);
            ops.emplace_back(L, R);
            needVal[val] = 0;
            return;
        }
        // try opposite sides: u < val with pos > pval and v > val with pos < pval
        left_pos = -1; right_pos = -1;
        for (int u = val - 1; u >= 1; --u) {
            if (pos[u] > pval) { left_pos = pos[u]; break; }
        }
        for (int v = val + 1; v <= n; ++v) {
            if (pos[v] < pval) { right_pos = pos[v]; break; }
        }
        if (left_pos != -1 && right_pos != -1) {
            int L = right_pos, R = left_pos;
            if (L > R) swap(L, R);
            ops.emplace_back(L, R);
            needVal[val] = 0;
            return;
        }
        // If above failed, as a fallback try any u<val and v>val irrespective of needVal,
        // searching positions that enclose pval.
        left_pos = -1; right_pos = -1;
        for (int u = val - 1; u >= 1; --u) {
            if (pos[u] < pval) { left_pos = pos[u]; break; }
        }
        for (int v = val + 1; v <= n; ++v) {
            if (pos[v] > pval) { right_pos = pos[v]; break; }
        }
        if (left_pos != -1 && right_pos != -1) {
            int L = left_pos, R = right_pos;
            if (L > R) swap(L, R);
            ops.emplace_back(L, R);
            needVal[val] = 0;
            return;
        }
        // other orientation
        left_pos = -1; right_pos = -1;
        for (int u = val - 1; u >= 1; --u) {
            if (pos[u] > pval) { left_pos = pos[u]; break; }
        }
        for (int v = val + 1; v <= n; ++v) {
            if (pos[v] < pval) { right_pos = pos[v]; break; }
        }
        if (left_pos != -1 && right_pos != -1) {
            int L = right_pos, R = left_pos;
            if (L > R) swap(L, R);
            ops.emplace_back(L, R);
            needVal[val] = 0;
            return;
        }
        // cannot enclose this single value -> fail
        failed = true;
        return;
    } else {
        // a < b: take endpoints at values a and b
        int L = pos[a], R = pos[b];
        if (L > R) swap(L, R);
        ops.emplace_back(L, R);
        // remove all needed values v in (a,b) whose positions lie strictly between L and R
        for (int v = a + 1; v <= b - 1; ++v) {
            if (needVal[v]) {
                int pv = pos[v];
                if (pv > L && pv < R) needVal[v] = 0;
            }
        }
        // Note: a and b themselves are not removed by this op (strict inequality)
        // Recurse on left and right value subranges to cover remaining needed values
        dfs(lowVal, a);
        dfs(b, highVal);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        cin >> n;
        p.assign(n+1, 0);
        pos.assign(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            cin >> p[i];
            pos[p[i]] = i;
        }
        string x; cin >> x;
        needVal.assign(n+1, 0);
        int needCount = 0;
        for (int i = 1; i <= n; ++i) {
            if (x[i-1] == '1') {
                needVal[p[i]] = 1;
                ++needCount;
            }
        }
        if (needCount == 0) {
            cout << 0 << '\n';
            continue;
        }
        ops.clear();
        failed = false;
        // find overall value range that might contain needed values
        int minV = 1, maxV = n;
        // call dfs on full value range
        dfs(1, n);
        // after dfs, check if all needed cleared and operations <= 5 and not failed
        bool ok = !failed && ((int)ops.size() <= 5);
        for (int v = 1; v <= n; ++v) if (needVal[v]) { ok = false; break; }
        if (!ok) {
            cout << -1 << '\n';
        } else {
            cout << ops.size() << '\n';
            for (auto &pr : ops) cout << pr.first << ' ' << pr.second << '\n';
        }
    }
    return 0;
}
