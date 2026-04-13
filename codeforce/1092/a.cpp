#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        long long S = 0;
        for(int i = 0 ; i < n ; i++){
            int x;cin>>x;
            S += x;
        }

        int s = S % 2;
        int nk = (1LL * n * k) % 2;

        if(s == 1 || (s ^ 1 ^ nk) == 1)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}