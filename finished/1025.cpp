//1433写不出来，学一下1433的标签
//体验了一下隔壁超算的入门测试，妈的好难好难好难
#include <bits/stdc++.h>
using namespace std;

int total = 0;

void divide(int sum, int k, int prev) {
    if (k == 1) {
        if (sum >= prev) total++;
        return;
    }
    for (int i = prev; i <= sum - (k - 1) * prev; i++) {
        divide(sum - i, k - 1, i);
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    divide(n, k, 1); // 从1开始
    cout << total << endl;
}
