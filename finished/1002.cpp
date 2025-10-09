/*棋盘上 A 点有一个过河卒，需要走到目标 B 点。卒行走的规则：可以向下、或者向右。同时在棋盘上 C 点有一个对方的马，该马所在的点和所有跳跃一步可达的点称为对方马的控制点。因此称之为“马拦过河卒”。

棋盘用坐标表示，A 点 (0,0)、B 点 (n,m)，同样马的位置坐标是需要给出的。*/
/*#include <bits/stdc++.h>
using namespace std;
long long factorial(int x){
    long long shu=1;
    for (int i=1;i<=x;i++){
    shu*=i;
    
    }
    return shu;
}
int main(){
int a,b,m,n;
cin>>a>>b>>n>>m;
long long qian1=0,qian2=0;


if (m-3>=0){
    qian1+=factorial(m+n-3)/(factorial(m-3)*factorial(n));
}
if (n-3>=0){
    qian2+=factorial(m+n-3)/(factorial(n-3)*factorial(m));
}

if (a>=n+3){
    qian2*=factorial(a+b-m-n-3)/((factorial(a-n-3)*factorial(b-m)));
}
if (b>=m+3){
    qian1*=factorial(a+b-m-n-3)/((factorial(b-m-3)*factorial(a-n)));
}

long long sb=qian1+qian2;
if(a<m||b<n){
    sb=0;
}
cout<<sb<<endl;
return 0;
}
以上为错误示范
*/
/*
#include <bits/stdc++.h>
using namespace std;
int main(){
int max,may,mux,muy;
cin>>mux>>muy>>max>>may;
    vector<vector<int>> zb(mux + 1, vector<int>(muy + 1, 0));
     zb[0][0]=1;
for (int i=0;i<=mux;i++){
    for (int j=0;j<=muy;j++){
    if (i==max-1&&j==may-2||i==max-1&&j==may+2||i==max-2&&j==may-1||i==max-2&&j==may+1||
        i==max+2&&j==may-1||i==max+2&&j==may+1||i==max+1&&j==may-2||i==max+1&&j==may+2||j==may&&i==max){
        continue;
        }
    
    if (i>0) zb[i][j]+=zb[i-1][j];
    if (j>0) zb[i][j]+=zb[i][j-1];

    

    }
}
cout<<zb[mux][muy]<<endl;
return 0;

}
这一版也有错，忽略了max-1 may-2越界，但我不想写了，交给ai
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int mux, muy, max, may;
    cin >> mux >> muy >> max >> may;

    // 标记障碍点
    vector<vector<bool>> block(mux + 1, vector<bool>(muy + 1, false));
    int dx[9] = {0, -2, -2, -1, -1, 1, 1, 2, 2};
    int dy[9] = {0, -1, 1, -2, 2, -2, 2, -1, 1};

    for (int k = 0; k < 9; k++) {
        int x = max + dx[k];
        int y = may + dy[k];
        if (x >= 0 && x <= mux && y >= 0 && y <= muy) {
            block[x][y] = true; // 马和它能走到的点
        }
    }

    // DP 数组
    vector<vector<long long>> dp(mux + 1, vector<long long>(muy + 1, 0));
    dp[0][0] = block[0][0] ? 0 : 1; // 如果起点是障碍，直接 0

    for (int i = 0; i <= mux; i++) {
        for (int j = 0; j <= muy; j++) {
            if (block[i][j]) continue; // 障碍点不能走
            if (i > 0) dp[i][j] += dp[i - 1][j];
            if (j > 0) dp[i][j] += dp[i][j - 1];
        }
    }

    cout << dp[mux][muy] << endl;
    return 0;
}
                                        


