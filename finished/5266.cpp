#include <bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<string,int> sys;
    int n;cin>>n;
    for(int i = 0 ; i < n ; i++){
        int a;cin>>a;
        if(a==1){
            string name;int score;cin>>name>>score;
            sys[name]=score;
            cout<<"OK"<<endl;
        }
        else if(a==2){
            string name;cin>>name;
            if(sys.find(name)!=sys.end()) cout<<sys[name]<<endl;
            else cout<<"Not found"<<endl;
        }
        else if(a==3){
            string name;cin>>name;
            if(sys.find(name)!=sys.end()) {
                sys.erase(name);
                cout<<"Deleted successfully"<<endl;
            }
            else cout<<"Not found"<<endl;
        }
        else cout<<sys.size()<<endl;
    }
}