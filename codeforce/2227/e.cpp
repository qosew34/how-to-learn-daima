#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n);
        for(int i = 0 ; i < n ; i++) cin>>a[i];
        long long sum = 0;
        for(int i=1;i<=n;i++) sum += a[i];

        long long keep = 0;
        long long mx = 0;

        for(int i=n;i>=1;i--){  
            keep += min(a[i], mx);
            mx = max(mx, a[i]);
        }

        long long ans = sum - keep;
        cout<<ans<<endl;
    }
}