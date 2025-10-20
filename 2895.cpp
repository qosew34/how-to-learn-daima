#include<bits/stdc++.h>
using namespace std;


int main(){
    int m;
    vector<vector<int>> farm(302,vector<int>(302,1002));
    vector<vector<int>> visited(302,vector<int>(302,false));
    visited[0][0]=true;
    cin>>m;
    for(int i=0;i<m;i++){
        int x,y,t;
        cin>>x>>y>>t;
        if(x>0) farm[x-1][y]=min(t,farm[x-1][y]);
        if(y>0) farm[x][y-1]=min(t,farm[x][y-1]);
        if(x<300) farm[x+1][y]=min(t,farm[x+1][y]);
        if(y<300) farm[x][y+1]=min(t,farm[x][y+1]);//卧槽这里写错了
        farm[x][y] = min(t, farm[x][y]);//我草忘了
    }
    if (farm[0][0] == 0) {
    cout << -1;
    return 0;
}//这个也忘了
//tuple可以放一大把数字
    queue<tuple<int,int,int>> q;
    q.push({0,0,0});
    while(!q.empty()){
        auto [nx,ny,nt] =q.front();q.pop();
        if(farm[nx][ny]==1002){
            cout<<nt;
            return 0;
        }
//你妈的这傻逼能走出去
        int leftx,rightx,upy,downy;//妈的左右写反了
        if(true)  {
            upy=ny+1;
            if(farm[nx][upy]>nt+1&&!visited[nx][upy]){
                q.push({nx,upy,nt+1});
                visited[nx][upy]=true;
        }
        }
        if(ny-1>=0)  {
            downy=ny-1;
            if(farm[nx][downy]>nt+1&&!visited[nx][downy]){
                q.push({nx,downy,nt+1});
                visited[nx][downy]=true;
        }
        }
        if(true)  {
            leftx=nx+1;
            if(farm[leftx][ny]>nt+1&&!visited[leftx][ny]){
                q.push({leftx,ny,nt+1});
                visited[leftx][ny]=true;
        }
        }
        if(nx-1>=0)  {
            rightx=nx-1;
            if(farm[rightx][ny]>nt+1&&!visited[rightx][ny]){
                q.push({rightx,ny,nt+1});
                visited[rightx][ny]=true;
        }
        }

    }
    cout<<-1;
}
//盯着dfs寻思了半天，一看是bfs，我真是操了
