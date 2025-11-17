/*#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::vector;
using std::pair;
using std::max;
using std::array;
vector<int> happy;
vector<int> l,r,has_parent;
vector<array<int,2>> dp;

void dfs(int u){
    if(u == -1){
        return ;
    }
    if(l[u]!=-1) dfs(l[u]);
    if(r[u]!=-1) dfs(r[u]);
    int take = happy[u];
    if(l[u]!=-1) take+=dp[l[u]][0];//选u，左右子树选不在
    if(r[u]!=-1) take+=dp[r[u]][0];
    dp[u][1]=take;
    int not_take = 0;
    if (l[u] != -1) not_take += max(dp[l[u]][0], dp[l[u]][1]);
    if (r[u] != -1) not_take += max(dp[r[u]][0], dp[r[u]][1]);
    dp[u][0] = not_take;
}


int main(){
    int n;
    cin >> n;
    happy.assign(n+1,0);
    l.assign(n+1,-1);
    r.assign(n+1,-1);
    has_parent.assign(n+1, 0);
    dp.assign(n+1,{0,0});
    for(int i = 1 ; i <= n ; i++){
        int temp;
        cin >> temp;
        happy[i] = temp;
    }

    for(int i = 1 ; i < n ; i++){
        int a , b ;
        cin >> a >> b;
        if(l[b]==-1) l[b]=a;
        else r[b]=a;
        has_parent[a]=1;
    }
    int root = -1;
    for(int i = 1 ; i <=n ; i++){
        if(!has_parent[i]){
            root = i;
            break;
        }
    }
    dfs(root);
    cout<<max(dp[root][0],dp[root][1]);

}*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    if (n <= 0) {
        cout << 0 << "\n";
        return 0;
    }

    vector<ll> happy(n+1);
    for (int i = 1; i <= n; ++i) cin >> happy[i];

    vector<vector<int>> g(n+1);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        if (a >= 1 && a <= n && b >= 1 && b <= n) {
            g[a].push_back(b);
            g[b].push_back(a);
        }
    }

    vector<char> done(n+1, 0);    // 标记该节点是否已完成后序处理
    vector<ll> dp0(n+1, 0), dp1(n+1, 0);

    ll total = 0;
    // 对每个连通块分别做一次根化后的后序 DP（以防输入非连通，虽然树通常是连通的）
    for (int start = 1; start <= n; ++start) {
        if (done[start]) continue;

        // 用显式栈做后序遍历：元素为 (u, parent, postFlag)
        struct Item { int u, p; bool post; };
        vector<Item> stk;
        stk.push_back({start, 0, false});

        while (!stk.empty()) {
            Item it = stk.back(); stk.pop_back();
            int u = it.u, p = it.p;
            if (!it.post) {
                // 进入节点：先压入后序标记，再压入子节点
                stk.push_back({u, p, true});
                for (int v : g[u]) {
                    if (v == p) continue;
                    stk.push_back({v, u, false});
                }
            } else {
                // 后序位置：计算 dp
                ll take = happy[u];
                ll not_take = 0;
                for (int v : g[u]) {
                    if (v == p) continue;
                    take += dp0[v];
                    not_take += max(dp0[v], dp1[v]);
                }
                dp1[u] = take;
                dp0[u] = not_take;
                done[u] = 1;
            }
        }

        total += max(dp0[start], dp1[start]);
    }

    cout << total << "\n";
    return 0;
}