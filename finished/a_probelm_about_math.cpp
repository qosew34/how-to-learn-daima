#include <bits/stdc++.h>
using namespace std;

void stringize_system(int n,vector<int> &num){//长了点，但你不觉得很帅吗
    //我知道没stringize这个词
    string temp=to_string(n);
    for(int l=0;l<temp.size();l++){
        num.push_back(temp[l]-'0');
    }
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,m;
        cin>>n>>m;
        int total=0;
        vector<int> num;
        stringize_system(n,num);
        vector<int> temp2;//加个2，虽然不加也行
        total+=n%9;
        for(int j=0;j<m;j++){
            int cur=0;
            for(int k=0;k<num.size();k++){
                cur+=(num[k])*(num[k]);
            }
            cur%=9;
            total+=cur;
            temp2.clear();
            for(int m=0;m<num.size();m++){
                stringize_system(num[m]*num[m],temp2);
            }
            num=temp2;
        }
        total%=9;
        cout<<total<<endl;
    }
}