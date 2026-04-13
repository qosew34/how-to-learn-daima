#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<int> f(25,0); // 每个bit的最长长度
    
    while(n--){
        int x;cin>>x;
        
        vector<int> bits;
        for(int i = 0; i < 25; i++){
            if(x >> i & 1) bits.push_back(i);
        }
        
        int best = 0;
        for(int b : bits){
            best = max(best, f[b]);
        }
        
        int cur = best + 1;
        
        for(int b : bits){
            f[b] = max(f[b], cur);
        }
    }
    
    int ans = 0;
    for(auto v : f) ans = max(ans, v);
    
    cout<<ans<<endl;
}