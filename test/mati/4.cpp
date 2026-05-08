#include<bits/stdc++.h>
using namespace std;

long long mod = 998244353;
long long qpow(int x){
    if(x==0 )return 1;
    long long cur = 2;
    long long ans = 1;
    while(x>0){
        if(x&1) ans = (ans*cur)%mod;
        cur = (cur*cur)%mod;
        x = x >> 1;
    }
    return ans;
}
int dfs(int&count,int depth,int pre,int cur,vector<vector<int>> & adj){
    long long  min_d = mod;
    for(auto a : adj[cur]){
        if(a==pre) continue;
        min_d = min(dfs(count,depth+1,pre,cur,adj),min_d);
    }
    if(min_d == -1) return -1;
    if(min_d == mod){
        if(depth%2==1) return depth;
        else return -1;
    }
    if(depth%2==1){
        count+=
    } 
}
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<vector<int>> adj(n+1);
        for(int i = 0 ; i < n - 1 ; i++){
            int u,v;cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int count = 0;
        int can = dfs(count,0,-1,1,adj);
        if(can==-1){
            cout<<0<<endl;
        }
        else cout<<qpow(count)<<endl;
    }
}