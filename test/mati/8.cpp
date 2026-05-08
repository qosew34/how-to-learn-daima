#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<int > vs(256,0);
    for(int i = 0 ; i < 256 ; i++){
        vs[i] = (i%16)*16+i/16;
    }
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        int temp;cin>>temp;
        ans+=vs[temp];
    }
    cout<<ans<<endl;
}