#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;cin>>s;
    int a,b;cin>>a>>b;
    s.erase(s.size()-b,b);
    s.erase(0,a);
    cout<<s<<endl;
}