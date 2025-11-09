/*#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> maze(n, vector<int>(m));
    vector<vector<int>> cur(n, vector<int>(m, 1001));
    int temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>temp;
            maze[i][j]=temp;
        }
    }
    //他写的bfs我就用bfs了
    //为什么会有二分？
    //我知道了，我要找出每一步的最小值
    //那我就得用tuple了
    queue<tuple<int,int,int>> q;
    for(int i=0;i<n;i++){
        q.push({i,0,0});
        cur[i][0]=0;
    }
    while(!q.empty()){
        auto [x,y,pre_max]=q.front();q.pop();
        int new_max=pre_max;
        if(y-1>=0&&(cur[x][y-1]==1001||cur[x][y-1]>pre_max)){
            new_max=max(maze[x][y-1],pre_max);
            cur[x][y-1]=new_max;
            q.push({x,y-1,new_max});
        }
        if(y+1<m&&(cur[x][y+1]==1001||cur[x][y+1]>pre_max)){
            new_max=max(maze[x][y+1],pre_max);
            cur[x][y+1]=new_max;
            q.push({x,y+1,new_max});
        }
        if(x+1<n&&(cur[x+1][y]==1001||cur[x+1][y]>pre_max)){
            new_max=max(maze[x+1][y],pre_max);
            cur[x+1][y]=new_max;
            q.push({x+1,y,new_max});
        }
        if(x-1>=0&&(cur[x-1][y]==1001||cur[x-1][y]>pre_max)){
            new_max=max(maze[x-1][y],pre_max);
            cur[x-1][y]=new_max;
            q.push({x-1,y,new_max});
        }
    }
    int ans=1001;
    for(int i=0;i<m;i++){
        ans=max(ans,cur[n-1][i]);
    }
    cout<<ans;
}
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<vector<int>> p(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> p[i][j];

    const int INF = 1e9;
    vector<vector<int>> dist(n, vector<int>(m, INF));
    // priority queue of (cost, x, y), where cost = minimal possible maximum along path to (x,y)
    using T = tuple<int,int,int>;
    priority_queue<T, vector<T>, greater<T>> pq;//按照优先级弹出的队列，取决于比较器

    // initialize with all top-row entrances (row 0) with cost 0
    for (int j = 0; j < m; ++j) {
        dist[0][j] = 0;
        pq.emplace(0, 0, j);
    }

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (!pq.empty()) {
        auto [cost, x, y] = pq.top(); pq.pop();
        if (cost != dist[x][y]) continue;
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            int ncost = max(cost, p[nx][ny]);
            if (ncost < dist[nx][ny]) {
                dist[nx][ny] = ncost;//更好的走到这里的路
                pq.emplace(ncost, nx, ny);
            }
        }
    }

    int ans = 0;
    for (int j = 0; j < m; ++j) {
        ans = max(ans, dist[n-1][j]);
    }
    cout << ans << "\n";
    return 0;
}
