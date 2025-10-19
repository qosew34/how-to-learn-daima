#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,k;cin>>n>>k;
        string s;
        int protect=0;
        for(int j=0;j<s.size();j++){
            bool set=true;
            for(int j=max(1,j-k+1);j<k;j++){
                if(s[j]=1){
                    set=false;
                }
            }
            if((s[j]==1)&&set) protect++;
        }
        cout<<protect<<endl;
    }
}