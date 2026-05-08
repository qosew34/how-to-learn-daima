#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    int mx=0,my=0;
    int minx = 2147483647,miny = minx;
    while(n--){
        int x,y;cin>>x>>y;
        mx = max(mx,x);
        my = max(my,y);
        minx = min(minx,x);
        miny = min(miny,y);
    }
    cout<<(mx-minx)*(my-miny);
}