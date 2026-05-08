#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> ele(n);
        for(int i = 0 ; i < n ; i++) cin>>ele[i];
        for(int i = 0 ; i < n ; i++){
            if(ele[i]%2==0&&ele[i]%6!=0) cout<<ele[i]<<" ";
        }
                for(int i = 0 ; i < n ; i++){
            if(ele[i]%2!=0&&ele[i]%3!=0) cout<<ele[i]<<" ";
        }
        for(int i = 0 ; i < n ; i++){
            if(ele[i]%3==0&&ele[i]%6!=0) cout<<ele[i]<<" ";
        }
        for(int i = 0 ; i < n ; i++){
            if(ele[i]%6==0) cout<<ele[i]<<" ";
        }
        cout<<endl;
    }
}