#include <bits/stdc++.h>
using std::cin;
using std::vector;
using std::cout;
using ll =long long;
using std::min;
int main(){
    //构建无向图
    int n; cin >> n;
    vector<int> w(n+1);
    vector<vector<int>> g(n+1);
    for (int i = 1; i <= n; ++i) {
        int u, v;
        cin >> w[i] >> u >> v;
        if (u != 0) {
            g[i].push_back(u);
            g[u].push_back(i);
        }
        if (v != 0) {
            g[i].push_back(v);
            g[v].push_back(i);
        }
    }
    vector<int> parent(n+1,0),order(n);
    vector<int> depth(n+1,0);
    parent[1]=0;
    depth[1]=0;
    vector<int> stk;
    stk.push_back(1);
    while(!stk.empty()){
        int u = stk.back();stk.pop_back();
        order.push_back(u);
        for(int v:g[u]){
            if(v!=parent[u]){
                parent[v]=u;
                depth[v]=depth[u]+1;
                stk.push_back(v);
            }
        }
    }
    ll totalW = 0;
    ll initialDist = 0;
    for (int i = 1; i <= n; ++i) {
        totalW += w[i];
        initialDist += w[i] * (ll)depth[i];
    }
    vector<int> sub(n+1,0);
    for (int u : order) sub[u] = w[u];
    for (int i = (int)order.size() - 1; i >= 0; --i) {
        int u = order[i];
        if (parent[u]) sub[parent[u]] += sub[u];
    }

    vector<ll> res(n+1, 0);
    res[1] = initialDist;
    for (int u : order) {
        for (int v : g[u]) if (v != parent[u]) {
            res[v] = res[u] + (totalW - 2 * sub[v]);
        }
    }

    ll ans = LLONG_MAX;
    for (int i = 1; i <= n; ++i) ans = min(ans, res[i]);
    cout << ans;
}