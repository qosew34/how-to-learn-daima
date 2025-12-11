#include <bits/stdc++.h>
using namespace std;

int main(){
    int k,m,n;cin>>k>>n>>m;
    vector<int> farm(n+1,0);
    vector<vector<int>> road(n+1);
    vector<bool> mutual_road(n+1,false);
    for(int i = 0 ; i < k ; i++){
        int temp;cin>>temp;
        farm[temp]++;
    }
    for(int i = 0 ; i < m ; i++){
        int u,v;cin>>u>>v;
        road[u].push_back(v);
    }
    bool first = true;
    for(int i = 1 ; i <= n ; i++){
        if(farm[i]>0){
            if(first){
                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    int a = q.front();q.pop();
                    if(mutual_road[a]) continue;
                    mutual_road[a]=true;
                    for(auto b : road[a]) q.push(b);
                }
                first = false;
            }
            else{
                    vector<bool> temp_mr(n+1,false);
                    queue<int> q;
                    q.push(i);
                    while(!q.empty()){
                        int a = q.front();q.pop();
                        if(temp_mr[a]) continue;
                        temp_mr[a]=true;
                        for(auto b : road[a]) q.push(b);
                    }
                    for(int j = 1 ; j <= n ; j++) mutual_road[j]=mutual_road[j]&&temp_mr[j];
            }
        }
    }
    int ans = 0;
    for(int i =1 ; i <= n ; i++) if(mutual_road[i]) ans++;
    cout<<ans<<endl;
}