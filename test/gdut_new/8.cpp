#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<int>energy;energy.push_back(0);
    for(int i = 0 ; i < n ; i++){
        int temp;cin>>temp;
        energy.push_back(temp);
    }
    vector<pair<int,int>> ans(n+1,{0,-1});//第一位是1，第二位是2
    ans[0]={0,0};
    for(int i=1;i<n+1;i++){
        if (i-1>=0&&ans[i-1].second!=-1) {
            ans[i].first=max(ans[i].first,ans[i-1].second+energy[i]);
        }
        if (i>=2) {
            int prev = max(ans[i-2].first, ans[i-2].second);
            if (prev!=-1) ans[i].second=max(ans[i].second,prev+energy[i]);
        } 
    }
    cout<<max(ans[n].first,ans[n].second)<<endl;
}