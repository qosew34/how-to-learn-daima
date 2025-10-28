#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(a==c&&b==d&&b==c){
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }
}