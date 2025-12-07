#include <bits/stdc++.h>

void dfs(int i , std :: vector<bool> &c , std :: vector<std :: vector<int>> &adj ){
    if(c[i]==true) return;
    c[i]=true;
    for(auto a:adj[i]){
        dfs(a,c,adj);
    }
}

int main(){
    int n,m;
    while(std :: cin >> n >> m && n!=0){
        std :: vector<std :: vector<int>> adj(n+1);
        std :: vector<bool> can_be_arrived(n+1,false);
        for(int i = 0 ; i < m ; i++){
            int a , b ;
            std :: cin >> a >> b ;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int ans = 0;
        dfs(1,can_be_arrived,adj);
        for(int i = 1 ; i < n+1 ;  i++ ){
            if(can_be_arrived[i]) continue;
            else{
                dfs(i,can_be_arrived,adj);
                ans++;
            }
        }
        std :: cout<<ans<<std :: endl;
    }

}