#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
  int n,qs;cin>>n>>qs;
  vector<int> types(n+1);
  for(int i = 0 ; i < n ; i++) cin>>types[i+1];
  vector<vector<int>> adj(n+1);
  for(int i = 0 ; i < n-1 ; i++){
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  while(qs){
    qs--;
    int s,t;cin>>s>>t;
    //c够少 使用string压缩状态
    string cir(20,'0');
    cir[types[s]]='0';
    queue<pair<int,string>> q;
    q.push({s,cir});
    vector<bool>visited(n+1,false);
    while(!q.empty()){
      int loc = q.front().first;
      string bought = q.front().second;
            q.pop();
      if(visited[loc]) continue;
      else visited[loc] = true;

      bought[types[loc]] = '1';
      if(loc==t){
        int ans = 0;
        for(auto a : bought) ans+=(a-'0');
        cout<<ans<<endl;
        break;
      }
      for(int i = 0 ; i < adj[loc].size() ; i++){
        q.push({adj[loc][i],bought});
      }
    }
  }
  // 请在此输入您的代码
  return 0;
}