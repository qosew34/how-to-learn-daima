#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    for(int i = 0 ; i < t ; i++){
        int a,b;cin>>a>>b;
        int h = max(a,b);
        int l = min(a,b);
        if(h>3*l+1){
            cout<<"NO"<<endl;
            continue;
        }
        bool white = (a>=b);
        cout<<"YES"<<endl;
        int x = 500;
        int y = 
    }
}