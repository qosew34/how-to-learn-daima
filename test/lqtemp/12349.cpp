#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;cin>>n>>m;
    vector<string> dp(n),vdp(n);
    for(int i = 0 ; i < n ; i++){
        string temp = "";
        string temp2 = "";
        for(int j = 0 ; j < m ; j++){
            char t ;cin>>t;
            temp+=t;
            if(t=='0') temp2+='1';
            else temp2+='0';
        }
        dp[i] = temp;
        vdp[i] = temp2;
    }
    vector<int> change(n,0),notchange(n,0);
    //除了最后一行外，每一行的int都是计算加上上一行后的最大值
    for(int i = 0 ; i < n ; i++){
        int total = 0;
        for(int j = 0 ; j < m ; j++){
            char cur = dp[i][j];
            int count = 0;
            if(j==0){
                char a = 
            }
            else if(j==m-1){
                
            }
            else{

            }
        }
    }

}