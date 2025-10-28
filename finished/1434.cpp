#include <bits/stdc++.h>
using namespace std;

int main(){
    int r ; int c ;
    cin >> r >> c ;
    vector<vector<int>> slide(r,vector<int>(c));
    for ( int i = 0 ; i < r ; i++){
        for ( int j = 0 ; j < c ; j++){
            int temp ; cin >> temp ;
            slide[i][j] = temp;
            
        }
    }

    //一定从最高点开始滑雪最长吗？好像不是
    //longestslide是用来记录当前格子最远能走几步到
    //呃，从最高点开始，走一步记录一下，把这步塞进去
    //嗯，然后再扫0的格子
    //好想用bfs，但我觉得是错的
    //哦对的对的，用两个？vector
    vector<vector<int>> pre(r,vector<int>(c,1));
    vector<vector<int>> cur(r,vector<int>(c,0));
    int dx[4] = { -1 , 0 , 1 , 0 };
    int dy[4] = { 0 , 1 , 0 , -1 };
    //如果slide中一个数小于旁边的数字，那么cur中这个数就=max(prev+1,cur)
    while(pre!=cur){
        for(int i=0;i<r;i++) fill(cur[i].begin(),cur[i].end(),0);
            for ( int i = 0 ; i < r ; i++){
                for ( int j = 0 ; j < c ; j++){
                    for(int k=0;k<4;k++){
                        int nx=i+dx[k]; int ny=j+dy[k];
                        if(nx>=r||ny>=c||nx<0||ny<0){
                            continue;
                        }
                        if(slide[nx][ny]>slide[i][j]){
                            cur[i][j]=max(cur[i][j],pre[nx][ny]+1);
                        }
                    }
            }
        }
    pre.swap(cur);
    }
    int max_=0;
        for ( int i = 0 ; i < r ; i++){
        for ( int j = 0 ; j < c ; j++){
            if(cur[i][j]>max_) max_=cur[i][j];
        }
    }
    cout<<max_+1;
}//对咯
//看看ai写的
/*#include <bits/stdc++.h>
using namespace std;
int R, C;
vector<vector<int>> a, memo;
int dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};

int dfs(int i, int j){
    if (memo[i][j] != 0) return memo[i][j];
    int best = 1;
    for(int k=0;k<4;k++){
        int ni = i + dx[k], nj = j + dy[k];
        if (ni>=0 && ni<R && nj>=0 && nj<C && a[ni][nj] < a[i][j]){
            best = max(best, 1 + dfs(ni, nj));
        }
    }
    memo[i][j] = best;
    return best;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (!(cin >> R >> C)) return 0;
    a.assign(R, vector<int>(C));
    for(int i=0;i<R;i++) for(int j=0;j<C;j++) cin >> a[i][j];
    memo.assign(R, vector<int>(C, 0));
    int ans = 0;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            ans = max(ans, dfs(i,j));
        }
    }
    cout << ans << "\n";




    #include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int R,C;
    if (!(cin >> R >> C)) return 0;
    vector<vector<int>> a(R, vector<int>(C));
    vector<pair<int,int>> cells;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin >> a[i][j];
            cells.emplace_back(i,j);
        }
    }
    sort(cells.begin(), cells.end(), [&](const pair<int,int>& p1, const pair<int,int>& p2){
        return a[p1.first][p1.second] > a[p2.first][p2.second]; // 降序
    });
    vector<vector<int>> dp(R, vector<int>(C, 1));
    int dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};
    int ans = 1;
    for(auto &p : cells){
        int i = p.first, j = p.second;
        for(int k=0;k<4;k++){
            int ni = i + dx[k], nj = j + dy[k];
            if(ni>=0 && ni<R && nj>=0 && nj<C && a[ni][nj] < a[i][j]){
                dp[i][j] = max(dp[i][j], dp[ni][nj] + 1);
            }
        }
        ans = max(ans, dp[i][j]);
    }
    cout << ans << "\n";
    return 0;
}
}*/