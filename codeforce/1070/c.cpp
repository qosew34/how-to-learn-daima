#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n; cin >> n;
        vector<int> odds, evens;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            if (x & 1) odds.push_back(x);
            else evens.push_back(x);
        }
        sort(odds.begin(), odds.end(), greater<int>());
        sort(evens.begin(), evens.end(), greater<int>());

        int O = (int)odds.size();
        int E = (int)evens.size();

        // prefix sums for evens (prefixE[t] = sum of top t evens)
        vector<ll> prefE(E+1, 0);
        for (int i = 1; i <= E; ++i) prefE[i] = prefE[i-1] + evens[i-1];

        // if no odd at all, every answer is 0
        if (O == 0) {
            for (int k = 1; k <= n; ++k) {
                cout << 0 << (k==n?'\n':' ');
            }
            continue;
        }

        ll bestOdd = odds[0]; // we always want the largest odd in the final segment for value

        // compute answer for each k = 1..n
        for (int k = 1; k <= n; ++k) {
            ll ans = 0;
            // largest possible t (number of evens in final segment)
            int max_t = min(E, k-1);
            bool found = false;
            for (int t = max_t; t >= 0; --t) {
                int s = 1 + t;
                if (s > k) continue;
                int r = k - s; // number of coins placed before the final segment
                // remaining coins after reserving final segment:
                int rem_odds = O - 1;
                int rem_evens = E - t;
                bool feasible = false;
                if (r == 0) {
                    // no earlier picks, fine
                    feasible = true;
                } else {
                    // need to pick r coins from remaining with an even number of odds
                    // let x = number of odds used in the r picks.
                    // constraints: 0 <= x <= min(r, rem_odds)
                    // and r - x <= rem_evens  -> x >= r - rem_evens
                    int low = max(0, r - rem_evens);
                    int high = min(r, rem_odds);
                    if (low <= high) {
                        // exists an even x in [low, high]?
                        if (low % 2 == 0) feasible = true;
                        else if (low + 1 <= high) feasible = true;
                    }
                }
                if (feasible) {
                    ans = bestOdd + prefE[t];
                    found = true;
                    break;
                }
            }
            if (!found) ans = 0;
            cout << ans << (k==n?'\n':' ');
        }
    }
    return 0;
}