#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<int> nums(n);
    for(int i = 0 ; i < n ; i++) cin>>nums[i];
    vector<int> pres(n+1,0);
    for(int i = 1 ; i <= n ; i++ ) pres[i] = pres[i-1] + nums[i-1];
    int m;cin>>m;
    while(m--){
        int l,r;cin>>l>>r;
        cout<<pres[r]-pres[l-1]<<endl;
    }
}