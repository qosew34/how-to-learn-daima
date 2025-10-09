#include <bits/stdc++.h>
using namespace std;

void pd(vector<int> &x,int &n){
bool z =true;
    for (int i=0;i<x.size();i++){
        if(n%x[i]==0){z=false;}
}
    if (z){x.push_back(n);}
}

int main(){
    vector<int> zs;
    zs.push_back(2);
    for (int j=3;j<2000;j++){
        pd(zs,j);
    }
    int l;
    cin>>l;
    int ans=0;
    vector<int> pushout;
    while (l>=0){
    l-=zs[ans];
    pushout.push_back(zs[ans]);
    ans++;
    }
    for (int k=0;k<pushout.size()-1;k++){
    cout<<pushout[k]<<endl;
    }
    cout<<ans-1<<endl;
    return 0;

}