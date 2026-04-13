#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,c;
    cin>>n>>c;
    map<long long,int>mp;
    for(int i = 0 ; i < n ; i++){
        long long temp;cin>>temp;mp[temp]++;
    }
    long long ans = 0;
    for(auto[num,count]:mp){
        if(mp.count(num+c)&&c!=0) ans+=mp[num]*mp[num+c];
    }
    cout<<ans<<endl;
}