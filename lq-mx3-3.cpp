#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==0){cout<<d/b;return 0;}
    if(b==0){cout<<c/a;return 0;}
    int m=c/a;
    int n=d/b;
    if(m>n){cout<<n;}else{cout<<m;}
}