#include <bits/stdc++.h>
using namespace std;
int main(){
    //18*2+25=59 18*2+21=57 21+25=46
    //18+21*2=60
    //先弄完25的 剩下/3
    //哦还能2个25
    //哦不对不对
    //先 3*18+6*21 再3*2*25 再3*18 7个6套
    double n;
    cin>>n;
    if(n%7==0) cout<<6*(n%7);
    else cout<<6*(n%7)+n/7+1;
}