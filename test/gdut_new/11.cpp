#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;cin>>n>>m;
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        double p,q,w;
        cin>>p>>q>>w;
        int a =floor((m*p+q-1)/q);
        if(w>=a) continue;
        else ans+=a-w; 
    }
    cout<<ans<<endl;
}