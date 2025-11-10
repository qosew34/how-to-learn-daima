#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;vector<int> pre;cin>>n;
        for(int j=0;j<n;j++){
            int temp;cin>>temp;
            pre.push_back(temp);
        }
        bool o=false;
        for(int j=0;j<n;j++){
            if(o) break;
            if(j>0){
                for(int k=0;k<j;k++){
                    int t=(pre[j])%pre[k];
                    if(t%2==0){
                        o=true;
                        cout<<pre[k]<<" "<<pre[j]<<endl;
                        break;
                    }
                }
            }
        }
        if(!o) cout<<-1<<endl;
    }
}
