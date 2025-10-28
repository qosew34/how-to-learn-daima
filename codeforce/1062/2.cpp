#include <bits/stdc++.h>
using namespace std;

int main(){
    int q;cin>>q;
    for(int i=0;i<q;i++){
        int l;cin>>l;
        string a,b;cin>>a>>b;
        int ab[26]={};
        int temp;
        for(int i=0;i<l;i++){
            temp=a[i]-'a';
            ab[temp]++;
        }
        bool same =true;
        for(int i=0;i<l;i++){
            temp=b[i]-'a';
            ab[temp]--;
            if(ab[temp]<0) {
                same = false;
            }
        }
        if(same) {cout<<"YES"<<endl;}
        else {cout<<"NO"<<endl;}
    }
}