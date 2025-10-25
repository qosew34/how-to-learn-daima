#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    //0的个数即进位次数
    //算了死算
    vector<int> febo={};
    febo.push_back (1);febo.push_back(1);
    for(int i=2;i<n;i++){
        febo.push_back(febo[i-1]+febo[i-2]);
    }
    int z_count=0;
    int temp=febo[n-1];
    while(temp!=1){
        z_count+=abs(temp%2-1);
        temp/=2;
    }
    cout<<z_count;
}