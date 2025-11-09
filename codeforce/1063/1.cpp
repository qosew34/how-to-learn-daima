#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    for(int i=0;i<t;i++){
        int n;cin>>n;
        int max=-2147483647;int min =2147483640;
        for(int j=0;j<n;j++){
            int temp;
            cin>>temp;
            if(temp>max) max=temp;
            if(temp<min) min=temp;
        }
        int x;cin>>x;
        if(x<=max&&x>=min) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}