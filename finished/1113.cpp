#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<int> things(n+1);
    vector<vector<int>> preparations(n+1);
    vector<int> ans(n+1);
    for(int i = 1 ; i <= n ; i++){
        int a;cin>>a;cin>>a;things[i]=a;
        while(cin>>a&&a!=0){
            preparations[i].push_back(a);
        }
    }
    int m = 0;
    for(int i = 1 ; i <= n ; i++){
        if(preparations[i].empty()) ans[i] = things[i];
        else {
            int b = 0;
            for(auto c : preparations[i]){
                b=max(b,ans[c]);
            }
            ans[i]=b+things[i];
        }
        m = max(m,ans[i]);
    }
    cout<<m<<endl;
}