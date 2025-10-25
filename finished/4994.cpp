#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    unsigned long long sb=1;
    for(int i=0;i<n+1;i++){
        sb*=2;
    }
    sb-=2;
    cout<<sb;
}