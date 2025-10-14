#include <bits/stdc++.h>
using namespace std;

int main() {
    string num;
    int n;
    getline(cin, num);
    vector<int> bignum;
    for (int i = 0; i < num.size(); i++) {
        bignum.push_back(num[i]);
    }
    cin >> n;
    int k0 = 0;
    int removals = min(n, (int)bignum.size()); 
    for (int j = 0; j < removals; j++) {
        bool removed = false;
        for (int k = max(k0 - 1, 0); k < (int)bignum.size() - 1; k++) {
            if (bignum[k] > bignum[k + 1]) {
                bignum.erase(bignum.begin() + k);
                k0 = k;  // 更新 k0 为移除位置
                removed = true;
                break;
            }
        }
        if (!removed && !bignum.empty()) {
            // 未找到降序对，从末尾移除
            bignum.pop_back();
            k0 = bignum.size();
        }
    }
    for (int l = 0; l < (int)bignum.size(); l++) {
        
            cout << (char)bignum[l];
        
    }
    return 0;
}