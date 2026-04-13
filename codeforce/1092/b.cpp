#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n + 2, 0); // 1-indexed, with sentinels a[0]=a[n+1]=0
        for (int i = 1; i <= n; i++) cin >> a[i];

        int p;
        cin >> p; // k=1 in this version

        int x = a[p];
        vector<int> b(n + 2, 0);
        for (int i = 1; i <= n; i++) b[i] = a[i] ^ x;

        int cntL = 0, cntR = 0;
        for (int i = 1; i <= p; i++) {
            if (b[i] != b[i - 1]) cntL++;
        }
        for (int i = p + 1; i <= n + 1; i++) {
            if (b[i] != b[i - 1]) cntR++;
        }

        cout << max(cntL, cntR) << '\n';
    }

    return 0;
}