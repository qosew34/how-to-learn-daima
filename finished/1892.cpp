#include <bits/stdc++.h>
using namespace std;

vector<int>parent;
int find(int x){
    while(parent[x]!=x){
        x=find(parent[x]);
    }
    return x;
}
void unite(int x,int y){
    int fx = find(x);
    int fy = find(y);
    parent[fx]=fy;
}
int main(){
    int n,m;cin>>n>>m;
    parent.resize(n+1,0);
    for(int i = 0 ; i <= n ; i++)parent[i]=i;
    vector<vector<int>> adj(n+1);
    for(int i = 0 ; i < m ; i++){
        char a;int b,c;
        cin>>a>>b>>c;
        if(a=='F') unite(b,c);
        else if(a=='E'){
            adj[b].push_back(c);
            adj[c].push_back(b);
        }
    }
    for(int i = 1 ; i < n+1 ; i++){
        for(auto a :adj[i]){
            for(auto b : adj[a]) if(b!=i) unite(b,i);
        }
    }
    vector<int> pre_p;
    int ans =0;
    for(int i = 1 ; i <= n ; i++){
        int a = find(i);
        if(find(pre_p.begin(),pre_p.end(),a)!=pre_p.end()) continue;
        pre_p.push_back(a);
        ans++;
    }
    cout<<ans;
}