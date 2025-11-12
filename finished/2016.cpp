#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    if (!(cin >> n)) return 0;
    vector<long long> t(n);
    vector<vector<int>> boats(n);
    const int MAXX = 100000;
    
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> t[i] >> k;
        boats[i].reserve(k);
        for (int j = 0; j < k; ++j) {
            int x;
            cin >> x;
            boats[i].push_back(x);
        }
        // 去重每艘船内的国籍（只需知道该船是否含有某国）
        sort(boats[i].begin(), boats[i].end());
        boats[i].erase(unique(boats[i].begin(), boats[i].end()), boats[i].end());
    }
    
    vector<int> cnt(MAXX + 5, 0); // cnt[c] = 窗口内有多少艘船包含国家 c
    int distinct = 0;
    int l = 0;
    const long long WINDOW = 86400LL;
    
    for (int i = 0; i < n; ++i) {
        // 加入第 i 艘船
        for (int x : boats[i]) {
            if (cnt[x] == 0) ++distinct;
            ++cnt[x];
        }
        while (l <= i && t[l] <= t[i] - WINDOW) {
            for (int x : boats[l]) {
                --cnt[x];
                if (cnt[x] == 0) --distinct;
            }
            ++l;
        }
        cout << distinct << '\n';
    }
    return 0;
}