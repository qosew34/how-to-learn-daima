#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, q;
    cin >> n >> k >> q;

    const int MAXX = 200000;               
    vector<int> diff(MAXX + 2, 0);
    vector<int> pref(MAXX + 2, 0);

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        diff[l] += 1;
        if (r + 1 <= MAXX) diff[r + 1] -= 1;
    }

    int active = 0;
    for (int x = 1; x <= MAXX; x++) {
        active += diff[x];
        pref[x] = pref[x - 1] + (active >= k ? 1 : 0);
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << pref[b] - pref[a - 1] << "\n";   // [a,b] 记得减 a-1
    }
    return 0;
}