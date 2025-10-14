#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    if(n==3){//==!!!!
        cout<<3;
        return 0;
    }
    int result=1;//初始化！！！
    vector<int> fj;
    int total=0;
    int m=n;
    for(int i=2;i<=m/2;i++){
        if(n-i>0){
            fj.push_back(i);
            total+=1;
            n-=i;
        }
        else{
            for(int j=total-n;j<total;j++){
                fj[j]++;
            }
            break;
        }
    }
    for(int i=0;i<total;i++){
        result*=fj[i];
        cout<<fj[i]<<" ";
    }
    cout<<endl<<result<<endl;
    return 0;
}