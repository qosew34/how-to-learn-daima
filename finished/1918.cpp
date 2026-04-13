#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    unordered_map<int,int> mp;
    for(int i = 0 ; i < n ; i++){
        int temp;cin>>temp;mp[temp] = i;
    }
    int q;cin>>q;
    while(q--){
        int want;cin>>want;
        if(mp.count(want)) cout<<mp[want]+1<<endl;
        else cout<<0<<endl;
    }

}