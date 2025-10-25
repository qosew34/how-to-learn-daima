#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    //本质上就11 111 11*111-11-111以上随便凑
    if(n>1099){
        cout<<"YES";return 0;
    }
    for(int i=0;i<12;i++){
        int temp=n;
        temp-=i*111;
        if(temp<0) continue;
        if(temp%11==0){
            cout<<"YES";return 0;
        }
    }
    cout<<"NO";
}