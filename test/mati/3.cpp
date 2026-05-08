#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    vector<long long> xs(n),ys(n);
    for(int i = 0 ; i < n ; i++){
        cin>>xs[i]>>ys[i];
    }
    if(n==0){
        cout<<0<<endl;
        return 0;
    }
    long long ans = 1e16;
    for(int i = 0 ; i < n ; i++){
        long long temp = 0;
        for(int j = 0 ; j < n ; j++){
            if(i==j) continue;
            temp = max(temp,abs(xs[i]-xs[j])+abs(ys[i]-ys[j]));
        }
        ans = min(ans,temp);
    }
    cout<<ans<<endl;
    
    
}