#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t>0){
        t--;int n;cin>>n;
        int temp;cin>>temp;int pre=temp;
        int ans = 0;
        for(int i = 1 ; i < n ; i++){
            cin>>temp;if(temp<pre) ans++;
            else pre =temp;
        }
        cout<<ans<<endl;
    }
}