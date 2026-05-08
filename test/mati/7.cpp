#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<long long>> ws(m,vector<long long>(26,0));
    for(int i = 0 ; i < n ; i ++){
        string s;cin>>s;
        for(int j = 0 ; j < m ; j++){
            ws[j][s[j]-'a']++;
        }
    }
    long long ans = 0;
    for(int i = 0 ; i < m ; i++){
        long long c = n;
        for(int j = 0 ; j < 26 ; j++){
            if(c==0) break;
            else{
                c-=ws[i][j];
                ans+=c*ws[i][j];
            }
        }
    }
    cout<<ans<<endl;
}