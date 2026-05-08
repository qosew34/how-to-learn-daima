#include <bits/stdc++.h>
using namespace std;

int main(){
    int m,n;cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<int> cnt(n+1,0);
    int ans = 0;
    while(m--){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        cnt[u]++;
        cnt[v]++;
    }
}