#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>> hf(n, vector<int>(n, 0));/*幻方，先行后列*/
    int a,b;
    for (int i=1;i<=n*n;i++){
        if (i==1){
            a=0;b=n/2;
        }
        else{
            if (a==0&&b!=n-1){
                a=n-1;b=b+1; 
            }
            else if(a!=0&&b==n-1){
                a=a-1;b=0;
            }
            else if(a==0&&b==n-1){
                a=1;b=n-1;
            }
            else if(a!=0&&b!=n-1){
                if (hf[a-1][b+1]==0){
                    a=a-1;b=b+1;
                }
                else{
                    a=a+1;
                }
            }
        }
        hf[a][b]=i;
    }
    for (int j=0;j<n;j++){
        for(int k=0;k<n;k++){
            cout<<hf[j][k]<<" ";
            if (k==n-1){
                cout<<endl;
            }
        }
    }
    return 0;
}