
#include <string>
#include <iostream>
using namespace std;

int cm(int n,int x){
    int temp=1;
    for(int i=0;i<n;i++){
        temp*=x;
    }
    return temp;
}
int main(){
    int n;
    cin>>n;
int temp;
    for (int j=cm(n-1,10);j<cm(n,10);j++){
        string x=(to_string(j));
        temp=0;
        for(int k=0;k<n;k++){
            temp+=cm(n,x[k]-'0');//很好用
        }
        if(j==temp){cout<<j<<endl;}
    
}
}