#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int ans = 0;
    for(int i = 0 ; i < s.size() ; i++){
        ans+=s[i]-'0';
    }
    while(ans>=10){
        string s0 = to_string(ans);
        ans = 0;
        for(int i = 0 ; i < s0.size() ; i++){
        ans+=s0[i]-'0';
    }
    }
    cout<<ans<<endl;
}