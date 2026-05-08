#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int x,y;cin>>x>>y;
        int count = 0;
        if(x%2!=0) count++;
        if(y%2!=0) count++;
        if(count<=1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}