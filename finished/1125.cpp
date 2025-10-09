#include <bits/stdc++.h>
using namespace std;

void pd(vector<int> &x,int &n){
bool z =true;
    for (int i=0;i<x.size();i++){
        if(n%x[i]==0){z=false;}
}
    if (z){x.push_back(n);}
}

int main(){
    string word;
    getline(cin,word);
    int amount[200]={0};
    int ascii;
    for(int i=0;i<word.length();i++){
        ascii=static_cast<int>(word[i]);
        amount[ascii]++;
    }
int max=0;
int min=100;
    for(int j=0;j<200;j++){
        if(amount[j]>max){
            max=amount[j];
        }
        if(amount[j]<min&&amount[j]!=0){
            min=amount[j];
        }
    }
vector<int> zs;
zs.push_back(2);
for(int k=3;k<101;k++){
    pd(zs,k);
}
if(find(zs.begin(),zs.end(),max-min)!=zs.end()){
    cout<<"Lucky Word"<<endl;
    cout<<max-min<<endl;
}
else{
    cout<<"No Answer"<<endl;
    cout<<0<<endl;
}

return 0;
}
/*一定要仔细读题*/