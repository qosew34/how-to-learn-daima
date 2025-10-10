#include <bits/stdc++.h>
using namespace std;
int main(){
    int min=100;
    int max=0;
    int n;
    cin>>n;
    int temp;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            cin>>temp;
            if(i==j||i+j==n+1){
                if(temp>max){
                    max=temp;
                }
                if(temp<min){
                    min=temp;
                }
            }
        }
    }
    cout<<max<<" "<<min<<endl;
    return 0;
}