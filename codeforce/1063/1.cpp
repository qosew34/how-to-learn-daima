#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    for(int j=0;j<t;j++){
        int n;cin>>n;
        int temp;
        vector<int>pre;
        for(int i = 0;i<n;i++){
            cin>>temp;
            pre.push_back(temp);
        }
        int p=pre.size();
        sort(pre.begin(),pre.end());
        bool f=true;
        for(int i=0;i<p;i++){
            if(i%2==1){
                if(pre[i]!=pre[i+1]) f=false;
            }
        }
        if(f) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}