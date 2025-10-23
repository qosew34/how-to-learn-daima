#include <bits/stdc++.h>
using namespace std;

int main() {
    int L, N, K;
    cin >> L >> N >> K;
    vector<int> pos(N);
    for (int i = 0; i < N; i++) cin >> pos[i];
    
    // 确保包含起点和终点
    pos.insert(pos.begin(), 0);
    pos.push_back(L);
    N = pos.size();
    
    vector<int> dist;
    int maxDist = 0;
    for (int i = 1; i < N; i++) {
        int d = pos[i] - pos[i - 1];
        dist.push_back(d);
        maxDist = max(maxDist, d);
    }

    int left = 1, right = maxDist;
    while (left < right) {
        int mid = (left + right) / 2;
        int need = 0;
        for (int d : dist) {
            need += (d - 1) / mid; // 计算这段需要插入多少新路标
        }
        if (need > K)
            left = mid + 1; // mid 太小，间距太紧，插不完
        else
            right = mid; // mid 可行，尝试更小
    }
    cout << left << endl;
}
