#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    if (k == 0) {
        cout << 0 << endl;
        return 0;
    }
    vector<long long> woods(n);
    long long total_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> woods[i];
        total_sum += woods[i];
    }
    if (total_sum < k) {  // 无法切k段
        cout << 0 << endl;
        return 0;
    }
    long long low = 1;
    long long high = total_sum / k;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long total = 0;
        for (int j = 0; j < n; j++) {
            total += woods[j] / mid;
            if (total >= k) break;  // 优化：早停
        }
        if (total >= k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << high << endl;
    return 0;
}