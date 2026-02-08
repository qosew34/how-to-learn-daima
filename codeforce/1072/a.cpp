#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t){
        t--;
        int n;cin>>n;
        vector<int> num(n,0);
        unordered_map<int,int> colored;
        for(int i = 0 ; i < n ; i++) {
            cin>>num[i];
            if(i%2==0) colored[num[i]]++;
        }
        if(n<=2) cout<<"yes"<<endl;
        else{
        sort(num.begin(),num.end());
        int cir = colored[0];bool is = true;
        for(int i = 2 ; i < n ; i+=2){
            if(colored[i]!=cir) is = false;
        }
        if(is) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    }
}