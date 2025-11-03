#include <bits/stdc++.h>
using namespace std;
//一定要认真读题！！！！！
int main(){
    long long n,c;
    cin>>n>>c;
    long long temp;
    vector<int> scale;
    for(int i=0;i<n;i++){
        cin>>temp;
        if(temp>c) continue;
        scale.push_back(temp);
    }
    if(scale.empty()) {
        cout<<0;
        return 0;
    }
        sort(scale.begin(), scale.end());
    long long sum = 0;
    for (int i = (int)scale.size() - 1; i >= 0; --i) {
        if (scale[i] <= c - sum) sum += scale[i];
    }
    cout<<sum;
}
/*#include <bits/stdc++.h>
using namespace std;

// DFS 回溯求最大可放质量和（在不超过容量 c 的前提下）
// 输入保证 n <= 1000, 且砝码质量在 32-bit int 范围。
// 先过滤掉单个 > c 的砝码，排序后从大到小 DFS，使用前缀和剪枝。

long long best = 0;
vector<long long> a;      // 升序的可用砝码
vector<long long> pref;   // pref[i] = sum of a[0..i]

void dfs(int i, long long cur, long long c) {
    if (i < 0) {
        if (cur > best) best = cur;
        return;
    }
    // 上界剪枝：当前 cur + sum(a[0..i]) <= best 则无法超越 best，剪枝
    long long can_max = cur + pref[i];
    if (can_max <= best) return;

    // 优先尝试选取 a[i]（有助于更快提升 best，增强剪枝效果）
    if (a[i] <= c - cur) {
        dfs(i - 1, cur + a[i], c);
    }
    // 再尝试不选 a[i]
    dfs(i - 1, cur, c);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long c;
    if (!(cin >> n >> c)) return 0;

    vector<long long> input;
    input.reserve(n);
    for (int i = 0; i < n; ++i) {
        long long x; cin >> x;
        input.push_back(x);
    }

    sort(input.begin(), input.end()); // 升序（题目保证非减，但为了稳健我们排序）
    // 过滤掉单个 > c 的砝码
    for (long long v : input) {
        if (v <= c) a.push_back(v);
    }

    if (a.empty()) {
        cout << 0 << '\n';
        return 0;
    }

    int m = (int)a.size();
    pref.assign(m, 0);
    pref[0] = a[0];
    for (int i = 1; i < m; ++i) pref[i] = pref[i-1] + a[i];

    best = 0;
    // 从最大下标开始 DFS（即从大的砝码向小的尝试）
    dfs(m - 1, 0LL, c);

    cout << best << '\n';
    return 0;
}*/









/*
int main(){
    int n,c;
    cin>>n>>c;
    int temp;
    vector<int> scale(c+1,0);//好像用bool也行欸
    for(int i=0;i<n;i++){
        cin>>temp;
        if(temp>c) break;
        scale[temp]=1;
        if(i>0){
            for(int j=0;j<i;j++){
                if(scale[j]+scale[i]<=c){
                    scale[j+i]=1;
                }
            }
        }
    }
    for(int i=c;i>=0;i--){
        if(scale[i]>0){
            cout<<i+1<<endl;
            return 0;
        }
    }
    cout<<0;return 0;
}*/