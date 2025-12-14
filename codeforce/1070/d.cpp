#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> road;
vector<long long>point;
int ans = 0;
vector<bool>visited;
void dfs(int i,long long p,long long pp,long long l){
    if(visited[i]) return;
    visited[i]=true;
    if(pp==-1&&p!=-1) ans++;
    else if(pp+p==point[i]) ans+=l-2;
    ans%=998244353;
    for(auto a : road[i]){
        dfs(a,point[i],p,l+1);
    }
}
int main(){
    int t;cin>>t;
    while(t--){
        road.clear();point.clear();ans=0;visited.clear();
        int n,m;cin>>n>>m;
        road.resize(n+1);
        point.resize(n+1);
        visited.resize(n+1,false);
        for(int i = 1 ; i <= n ; i++) cin>>point[i];
        for(int i = 0 ; i < m ; i++){
            int a , b ;cin>>a>>b;
            road[a].push_back(b);
        }
        //dfs?
        for(int i = 0 ; i <= n ; i++){
            dfs(i,-1,-1,0);
        }
        cout<<ans<<endl;
    }
}
/*#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<long long> a(n + 1);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        vector<vector<int>> g(n + 1);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            // keep edges as given (1-based)
            g[u].push_back(v);
        }

        long long ans = 0;
        long long maxA = 0;
        for (int i = 1; i <= n; ++i) maxA = max(maxA, a[i]);

        // For every directed edge u->v, treat (u,v) as the first two nodes (length 2)
        // and try to extend while keeping path simple.
        vector<char> visited(n + 1);
        function<void(int,long long,long long,vector<char>&)> extend;
        extend = [&](int cur, long long p, long long q, vector<char> &vis) {
            // compute target = p + q safely and prune if too large
            __int128 s128 = (__int128)p + (__int128)q;
            if (s128 > (__int128)maxA) return;
            long long target = (long long)s128;
            for (int w : g[cur]) {
                if (vis[w]) continue;
                if (a[w] != target) continue;
                // valid extension
                vis[w] = 1;
                ans = (ans + 1) % MOD; // count new path ending at w
                extend(w, q, a[w], vis);
                vis[w] = 0;
            }
        };

        for (int u = 1; u <= n; ++u) {
            for (int v : g[u]) {
                if (u == v) continue; // path must be simple (no repeated vertex)
                // start a new path [u, v]
                fill(visited.begin(), visited.end(), 0);
                visited[u] = 1;
                visited[v] = 1;
                ans = (ans + 1) % MOD; // count the length-2 path [u,v]
                extend(v, a[u], a[v], visited);
            }
        }

        cout << ans % MOD << '\n';
    }
    return 0;
}*/