#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;

    vector<int> best(10, 0); 
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        x = abs(x);

        int last = x % 10;
        while (x >= 10) x /= 10;   
        int first = x;

        int cand = best[first] + 1; 
        best[last] = max(best[last], cand);
    }
    //记录末位数字最长长度
    int ans = 0;
    for (int d = 0; d < 10; d++) ans = max(ans, best[d]);

    cout << n - ans << "\n";
}