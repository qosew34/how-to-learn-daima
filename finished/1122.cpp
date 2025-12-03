#include<bits/stdc++.h>
int ans = -2147483648;
std :: vector<std :: vector<int>> adj;
std :: vector<int> flower;
int dfs(int cur,int pre){
    int m_cur=flower[cur];
    for (auto a :adj[cur]){
        if(a!=pre){
            m_cur+=std :: max(dfs(a,cur),0);
        }
    }
    ans = std :: max(ans,m_cur);
    return m_cur;
}
int main(){
    int n;
    std :: cin >> n;
    flower.resize(n+1,0);
    adj.resize(n+1);
    for(int i = 1 ; i < n + 1 ; i++){
        std :: cin >> flower[i];
    }
    for(int i = 0 ; i < n - 1 ; i++){
        int a , b ; 
        std :: cin >> a >> b ;
        adj[b].push_back(a);
        adj[a].push_back(b);
    }
    dfs(1,0);
    std :: cout<<ans;
}