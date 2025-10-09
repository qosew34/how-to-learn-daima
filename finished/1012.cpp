#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int shu[n];
    int temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        shu[i]=temp;
    }
    for(int j=0;j<n;j++){
        for(int k=0;k<n-j-1;k++){
            if(shu[k]*pow(10.0,(1+floor(log10(abs(shu[k+1])))))+shu[k+1]<shu[k]+shu[k+1]*pow(10.0,(1+floor(log10(abs(shu[k]+1)))))){
                temp=shu[k];
                shu[k]=shu[k+1];
                shu[k+1]=temp;
            }
        }
    }
    for(int l=0;l<n;l++){cout<<shu[l];}cout<<endl;return 0;
}