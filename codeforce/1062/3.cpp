#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    for(int i=0;i<t;i++){
        int n;
        int temp;
        cin>>n;
        vector<int> num;
        int odd=0;
        cin>>temp;num.push_back(temp);
        odd=temp%2;
        int out=0;
        for(int i=0;i<n-1;i++){
            cin>>temp;num.push_back(temp);
            if(odd!=temp%2) out=1;
        }
        if(out!=0){
            sort(num.begin(),num.end());
        }
        for(int i=0;i<n;i++){
            cout<<num[i]<<" ";
        }
        cout<<endl;    
    }
}