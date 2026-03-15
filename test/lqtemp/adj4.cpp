#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> ncount(n+1, 0), mcount(m+1, 0);
    vector<vector<int>> adjn(n+1), adjm(m+1);
    for(int i = 0; i < n; i++) cin >> ncount[i+1];
    for(int i = 0; i < m; i++) cin >> mcount[i+1];
    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adjn[u].push_back(v);
        adjn[v].push_back(u);
    }
    for(int i = 0; i < m-1; i++) {
        int u, v; cin >> u >> v;
        adjm[u].push_back(v);
        adjm[v].push_back(u);
    }

    if(ncount[1] != mcount[1]) {
        cout << 0 << endl;
        return 0;
    }

    int ans = 1;
    queue<vector<int>> q;  
    q.push({1, 1, 1});
    vector<vector<bool>> visited(n+1, vector<bool>(m+1, false));
    visited[1][1] = true;

    while(!q.empty()) {
        auto a = q.front(); q.pop();
        ans = max(ans, a[0]);
        int nnode = a[1], mnode = a[2];

        for(int i = 0; i < adjn[nnode].size(); i++) {
            int nn = adjn[nnode][i];
            for(int j = 0; j < adjm[mnode].size(); j++) {
                int mm = adjm[mnode][j];
                if(!visited[nn][mm] && ncount[nn] == mcount[mm]) {
                    visited[nn][mm] = true;
                    q.push({a[0]+1, nn, mm});
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}