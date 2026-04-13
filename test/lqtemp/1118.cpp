#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long sum;
    cin >> n >> sum;

    vector<long long> coef(n, 0);
    vector<vector<long long>> C(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++) C[i][j] = C[i-1][j-1] + C[i-1][j];
    }
    for (int pos = 0; pos < n; pos++) coef[pos] = C[n-1][pos];

    vector<int> p(n);
    iota(p.begin(), p.end(), 1); // 1..n

    do {
        long long s = 0;
        for (int pos = 0; pos < n; pos++) {
            s += coef[pos] * p[pos];
        }
        if (s == sum) {
            for (int i = 0; i < n; i++) {
                cout << p[i] << (i + 1 == n ? '\n' : ' ');
            }
            return 0;
        }
    } while (next_permutation(p.begin(), p.end()));

    return 0;
}