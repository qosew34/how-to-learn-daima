#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;

        ll run_len = 0;
        ll prev = -1;
        bool blocked = false;

        for (ll i = 1; i <= n; i++) {
            ll a;
            cin >> a;

            if (i == 1 || a != prev) {
                run_len = 1;
            } else {
                run_len++;
            }
            prev = a;

            if (run_len >= m) blocked = true;
        }

        cout << (blocked ? "NO" : "YES") << '\n';
    }

    return 0;
}