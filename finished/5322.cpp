#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
int main(){
    int s,n,m;cin>>s>>n>>m;
    vector<vector<int>> man(n,vector<int>(s));
    //第0行是第一个城堡的可能值
    for(int i=0;i<s;i++){
        for(int j=0 ; j<n ; j++){
            int temp;
            cin>>temp;
            man[j][i]=temp;
        }
    }
    for(int i=0;i<n;i++){
        sort(man[i].begin(),man[i].end());
    }
    const int64 NEG = LLONG_MIN / 4;
    vector<int64> dp(m + 1, NEG);
    dp[0] = 0;

    // 对每座城堡做“多重选择”：
    // 对第 i 座城堡，可选择在该城堡投入使得能战胜 t (0..s) 个对手：
    // 若 t>0 则需要的兵力为 w = 2 * man[i][t-1] + 1，得到的分数为 (i+1) * t
    for (int i = 0; i < n; ++i) {
        vector<int64> ndp(m + 1, NEG);
        for (int cap = 0; cap <= m; ++cap) {
            if (dp[cap] == NEG) continue;
            // 选 t = 0 .. s 对手被占领的数量
            // t = 0 表示该城堡不投入额外兵力（或者投入 0），收益 0，重量 0
            for (int t = 0; t <= s; ++t) {
                int w = 0;
                if (t > 0) w = 2 * man[i][t - 1] + 1;
                if (cap + w > m) break; // man[i] 已排序，t 增大后 w 单调不减，可提前退出
                int64 val = dp[cap] + int64(i + 1) * t;
                ndp[cap + w] = max(ndp[cap + w], val);
            }
        }
        dp.swap(ndp);
    }

    int64 ans = 0;
    for (int cap = 0; cap <= m; ++cap) if (dp[cap] != NEG) ans = max(ans, dp[cap]);
    cout << ans << '\n';
    return 0;
}



    /*
    //横代表人数 竖代表城堡 格子里代表分数
    //希望不要mle
    //对于第i列，我要遍历第城堡第i行所有值，找出合适的分数
    vector<vector<int>> c(n,vector<int>(m+1,-1));
    //行是城堡数，列是士兵数
    int temp=0;
    for(int j=0;j<m+1;j++){
        //第一行手动填，遍历放所有人头的可能
        while(temp<s&&j>2*man[0][temp]){
            temp++;
        }
        c[0][j]=temp;
        //第1个城堡放j个人能得到多少分
    }
    //获得i+1分*n
    for(int i=1;i<n;i++){
        temp=0;
        for(int j=0;j<=m;j++){
            //筛选出放m个人多少分，然后再给合适的格子加上这个分
            while(temp<s&&j>2*man[i][temp]){
                temp++;
            }
            int prev=0;
            while(j+prev<=m){
                if(c[i-1][prev]==-1) {prev++;continue;}
                c[i][prev+j]=max(c[i][prev+j],c[i-1][prev]+temp*(i+1));
                prev++;
            }
        }
    }
    int score=0;
    for(int j=0;j<m+1;j++){
        score=max(score,c[n-1][j]);
    }
    cout<<score;
}*/