#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    long long ans = 0;
    vector<long long> cnt(k, 0);
    cnt[0] = 1;                 

    int pres = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        pres = (pres + x) % k;
        ans += cnt[pres];       
        cnt[pres]++;
    }

    cout << ans << "\n";
}