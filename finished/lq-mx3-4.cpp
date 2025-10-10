#include <bits/stdc++.h>
using namespace std;
//字典序是会自动对此，不存在的补0，a>0
int main(){
    string T;
    cin>>T;
    string t=T;
    reverse(t.begin(),t.end());
    if(t>T){
        T=t;
    }
cout<<T<<"a";
    
}