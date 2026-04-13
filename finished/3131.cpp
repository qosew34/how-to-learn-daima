#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long pref = 0;
    vector<int> first(7, -1);
    first[0] = 0;

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        pref += x;

        int r = (int)(pref % 7);
        if (r < 0) r += 7;

        if (first[r] == -1) first[r] = i;
        else ans = max(ans, i - first[r]);
    }

    cout << ans;
    return 0;
}