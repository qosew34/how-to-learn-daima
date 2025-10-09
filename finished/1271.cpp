#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int piao[m]={0};
    int temp_ticket;
    for (int i=0;i<m;i++){
        cin>>temp_ticket;
        piao[i]=temp_ticket;
    }
    sort(piao,piao+m);
    for(int j=0;j<m;j++){
        cout<<piao[j]<<" ";
    }
    cout<<endl;
     return 0;
}