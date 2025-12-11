#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> ans;
int dfs(int cur){
    if(ans[cur]!=-1) return ans[cur];
    int b = cur;
    ans[cur]=cur;
    for(int a :adj[cur]){
        b = max(dfs(a),b);
    }
    ans[cur]=b;
    return b;
}
int main(){
    int n;cin>>n;int m ;cin>>m;
    adj.resize(n+1);
    ans.resize(n+1,-1);
    for(int i = 0 ; i < m ; i++){
        int v,u;cin>>u>>v;
        adj[u].push_back(v);
    }
    for(int i = n ; i >=1 ; i--){
        if(ans[i]==-1)dfs(i);
    }
    for(int i = 1 ; i <=n ; i++){
        cout<<ans[i]<<" ";
    }
}
/*#include <bits/stdc++.h>
using namespace std;

// 非递归 Kosaraju + DAG 上 DP，求每个点能到达的最大编号点

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<vector<int>> adj(n+1), radj(n+1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }

    // 1) 非递归获取所有节点的完成次序（出口时间顺序）
    vector<char> vis(n+1, 0);
    vector<int> order; order.reserve(n);
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        // stack of (node, next_index)
        vector<pair<int,int>> st;
        st.emplace_back(i, 0);
        vis[i] = 1;
        while (!st.empty()) {
            auto &pr = st.back();
            int u = pr.first;
            int &idx = pr.second;
            if (idx < (int)adj[u].size()) {
                int v = adj[u][idx++];
                if (!vis[v]) {
                    vis[v] = 1;
                    st.emplace_back(v, 0);
                }
            } else {
                order.push_back(u);
                st.pop_back();
            }
        }
    }

    // 2) 逆序遍历 order，在反图上把节点归入 SCC（使用非递归栈）
    vector<int> comp(n+1, -1);
    int cid = 0;
    for (int t = (int)order.size() - 1; t >= 0; --t) {
        int node = order[t];
        if (comp[node] != -1) continue;
        // flood fill on radj
        stack<int> st;
        st.push(node);
        comp[node] = cid;
        while (!st.empty()) {
            int u = st.top(); st.pop();
            for (int v : radj[u]) {
                if (comp[v] == -1) {
                    comp[v] = cid;
                    st.push(v);
                }
            }
        }
        ++cid;
    }

    // 3) 计算每个 SCC 内最大的原编号
    vector<int> comp_max(cid, 0);
    for (int i = 1; i <= n; ++i) {
        comp_max[comp[i]] = max(comp_max[comp[i]], i);
    }

    // 4) 构造缩点图（DAG），去重边
    vector<vector<int>> cadj(cid);
    for (int u = 1; u <= n; ++u) {
        for (int v : adj[u]) {
            int cu = comp[u], cv = comp[v];
            if (cu != cv) cadj[cu].push_back(cv);
        }
    }
    for (int i = 0; i < cid; ++i) {
        auto &vec = cadj[i];
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
    }

    // 5) 在 DAG 上拓扑排序（Kahn），得到一个拓扑序列
    vector<int> indeg(cid, 0);
    for (int u = 0; u < cid; ++u) {
        for (int v : cadj[u]) indeg[v]++;
    }
    queue<int> q;
    for (int i = 0; i < cid; ++i) if (indeg[i] == 0) q.push(i);
    vector<int> topo; topo.reserve(cid);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (int v : cadj[u]) {
            if (--indeg[v] == 0) q.push(v);
        }
    }

    // 6) 反向遍历拓扑序列，向上合并每个 SCC 能到达的最大编号
    vector<int> comp_ans = comp_max;
    for (int ti = (int)topo.size() - 1; ti >= 0; --ti) {
        int u = topo[ti];
        for (int v : cadj[u]) {
            comp_ans[u] = max(comp_ans[u], comp_ans[v]);
        }
    }

    // 7) 输出每个原节点的答案
    for (int i = 1; i <= n; ++i) {
        if (i > 1) cout << ' ';
        cout << comp_ans[comp[i]];
    }
    cout << '\n';
    return 0;
}*/