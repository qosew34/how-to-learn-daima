#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int64 MOD = 1000000007;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if(!(cin>>t)) return 0;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int64,int64>> ops(n);
        for(int i=0;i<n;++i){
            cin>>ops[i].first>>ops[i].second;
        }
        // comparator: put u before v if (a_v * b_u + b_v) > (a_u * b_v + b_u)
        sort(ops.begin(), ops.end(), [](const pair<int64,int64>& u, const pair<int64,int64>& v){
            __int128 a_u = u.first, b_u = u.second;
            __int128 a_v = v.first, b_v = v.second;
            return (a_v * b_u + b_v) > (a_u * b_v + b_u);
        });
        int64 x = 0;
        for(auto &op : ops){
            int64 a = op.first % MOD;
            int64 b = op.second % MOD;
            __int128 prod = (__int128)a * x + b;
            x = (int64)(prod % MOD);
        }
        cout << (x%MOD+MOD)%MOD << "\n";
    }
    return 0;
}