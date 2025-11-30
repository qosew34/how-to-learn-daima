#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    int temp;cin>>temp;
    int max1 = temp,min1=temp,maxl=1,minl=1;
    for(int i = 2 ; i <= n ; i++){
        cin>>temp;
        if(temp>max1){
            max1=temp;maxl=i;
        }
        if(temp<min1){
            min1=temp;minl=i;
        }
    }
    cout<<min(minl,maxl)<<" "<<max(minl,maxl)<<" "<<max1-min1;
}