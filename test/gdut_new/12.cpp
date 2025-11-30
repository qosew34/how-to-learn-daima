#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    for(int z = 0 ; z < t ; z++){
        int n ;cin>>n;
        vector<vector<int>> adj(n+1);
        for(int i = 0 ; i < n-1 ; i++){
            int a,b;cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int m = -1;int ans = 0;
        for(int i = 1; i <= n ; i++){
            int cur = 0;
            for(auto a:adj[i]){
                cur+=adj[a].size()-1;
            }
            if(cur>m){
                m=cur;ans=i;
            }
        }
        cout<<ans<<" "<<m<<endl;
    }
}