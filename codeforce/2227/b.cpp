#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;string s;cin>>n>>s;
        int countl = 0;
        for(auto a : s) if(a=='(') countl++;
        if(countl*2==s.size()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}