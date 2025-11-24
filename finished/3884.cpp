#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::vector;
using std::endl;
using std::max;
using std::min;
int main(){
    int n;cin >> n ;
    vector<vector<int>> adj(n+1);
    vector<int> l(n+1,0),r(n+1,0), parent(n+1, 0);
    for(int i = 0 ; i < n-1 ; i++ ){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        if(l[a]==0)l[a]=b;
        else r[a]=b;
        parent[b]=a;
    }
    int x,y; cin>>x>>y;
    vector<int> depth(n+1, 0);
    std::queue<int> q;
    depth[1] = 1;
    q.push(1);
    int maxDepth = 1;
    vector<int> cnt(n+2,0);
    cnt[1] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v: adj[u]) {
            if (depth[v] == 0) {
                depth[v] = depth[u] + 1;
                parent[v] = u;
                q.push(v);
                if ((int)cnt.size() <= depth[v]) cnt.resize(depth[v]+1, 0);
                cnt[depth[v]]++;
                maxDepth = max(maxDepth, depth[v]);
            }
        }
    }
    int width = 0;
    for (int d = 1; d <= maxDepth; ++d) width = max(width, cnt[d]);
    int a = x, b = y;
    while (depth[a] > depth[b]) a = parent[a];
    while (depth[b] > depth[a]) b = parent[b];
    while (a != b) {
        a = parent[a];
        b = parent[b];
    }
    int lca = a;
    cout<<maxDepth<<endl<<width<<endl<<2*depth[x]+depth[y]-3*depth[lca];
}