/*#include <bits/stdc++.h>
using namespace std;

int xmove[8]={-2,-2,-1,-1,1,1,2,2};
int ymove[8]={-1,1,-2,2,-2,2,-1,1};
int n,m,x,y;
vector<int> horsex;
vector<int> horsey;
void move(int current,vector<vector<int>> &chess){
    if(current>n*m){
        return;
    }
    for(int i=0;i<8;i++){
        int newx=horsex[current]+xmove[i];
        int newy=horsey[current]+ymove[i];
        if(newx>0&&newx<=n&&newy>0&&newy<=m){
            if(chess[newx][newy]==-1){
                chess[newx][newy]+=n*m;
        }
        chess[newx][newy]=min(chess[newx][newy],chess[horsex[current]][horsey[current]]+1);
        horsex.push_back(newx);
        horsey.push_back(newy);
        move(current+1,chess);
        horsex.pop_back();
        horsey.pop_back();
    }
}
}
int main(){
    cin>>n>>m>>x>>y;
    horsex.push_back(x);
    horsey.push_back(y);
    vector<vector<int>> chess(n+1,vector<int>(m+1,-1));
    chess[x][y]=0;
    int current=0;
    move(current,chess);
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            cout<<chess[i][j]<<" ";
        }
        cout<<endl;
    }
}刚学了dps，就试一试吧
很显然，错啦！全都tle!
    */
   #include <bits/stdc++.h>
using namespace std;

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<vector<int>> dist(n + 1, vector<int>(m + 1, -1));
    queue<pair<int, int>> q;//只许一段入另一端出
    q.push({x, y});
    dist[x][y] = 0;
    while (!q.empty()) {
        auto [cx, cy] = q.front(); q.pop();
        for (int i = 0; i < 8; ++i) {
            int nx = cx + dx[i], ny = cy + dy[i];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[cx][cy] + 1;
                q.push({ nx, ny});
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
} 