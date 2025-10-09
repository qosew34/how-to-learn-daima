#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    long long total=0;//要给初始量
    long long  side[5001]={0};
    long long  temp_side={0};
    for (int i=0;i<n;i++){
        cin>>temp_side;
        side[temp_side]++;
    }
    long long addition_side[10001]={0};
    for(int j=0;j<5000;j++){
        for (int k=j;k<5001;k++){
            if(k!=j){
            addition_side[j+k]+=side[j]*side[k];}
            else{
            addition_side[j+k]+=side[j]*(side[k]-1)/2;
            } 
        }
    }
    for (int l=0;l<5001;l++){
        total+=side[l]*(side[l]-1)*addition_side[l]/2;
        total%=1000000007LL;
    }
    cout<<total<<endl;
    return 0;
}