#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;cin>>n>>m;
    vector<int> t;
    vector<int> pusher;
    for(int i = 0 ; i < n ; i++){
        int temp;cin>>temp;t.push_back(temp);
        if(temp==0) pusher.push_back(i);
    }
    vector<vector<pair<int,int>> adj(n);
    for(int i = 0 ; i < m ; i++){
        int a,b,c;
        cin>>a>>b>>c;a--;b--;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    vector<int> time(2147483647);
    for(int i = 0 ; i < n ; i++){
        if(find(pusher.begin(),pusher.end(),i)!=pusher.end()){
            time[i]=0;
            continue;
        }
        for(auto a :pusher){
            time[i] = min(time,t[i]+a^i);
        }
    }
}