#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int temp;
    vector<int> jg;
    int total;
    for (int i=0;i<n;i++){
        cin>>temp;
        jg.push_back(temp);
    }
    for(int j=0;j<n;j++){
        if(find(jg.begin(),jg.end(),jg[j]-1)==jg.end()){
            total+=jg[j];
        }
    }
    cout<<total;
}