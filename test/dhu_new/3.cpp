#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;int n;
    cin>>s>>n;
    vector<string> sbs;
    for(int i = 0 ; i < n ; i++){
        string a,b;
        cin>>a>>b;
        if(search(b.begin(), b.end(), s.begin(), s.end()) != b.end()&&find(sbs.begin(),sbs.end(),a)==sbs.end()) sbs.push_back(a);
    }
    sort(sbs.begin(),sbs.end());
    if(sbs.size()==0){
        cout<<114514;return 0;
    }
    for(int i = 0 ; i < sbs.size() ; i++){
        cout<<sbs[i];
        if(i!=sbs.size()-1) cout<<" ";
    }
}