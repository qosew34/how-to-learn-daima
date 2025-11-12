#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    if (!(cin >> N)) return 0;
    cin >> M;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    for (int k = 0; k < M; ++k) {
        if (!next_permutation(a.begin(), a.end())) {
            // 按题意不会发生超出范围的情况，但若出现则停止
            break;
        }
    }

    for (int i = 0; i < N; ++i) {
        if (i) cout << ' ';
        cout << a[i];
    }
    cout << '\n';
    return 0;
}