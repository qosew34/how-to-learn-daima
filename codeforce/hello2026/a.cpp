#include <bits/stdc++.h>
using namespace std;

int main(){
    //bob 非0
    // 一串1换0 或一串全换1
    int t;cin>>t;
    while(t){
        t--;
        int n;cin>>n;
        int total=0;
        int pre;
        int temp;cin>>temp;
        pre  = temp;total++;
        for (int i = 1 ; i < n ; i++){
            cin>>temp;if(temp==pre) continue;
            else {
                total++;
                pre = temp;
            }
        }
        if(total%2==0&&total!=2) cout<<"bob"<<endl;
        else cout<<"alice"<<endl;
    }
}