#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n);
        for(int i = 0 ; i < n ; i++){
            cin>>a[i];
        }
        unordered_set<int> st;
        bool ok = true;
        for(int x : a){
            if(st.count(x)){
                ok = false;
                break;
            }
            st.insert(x);
        }
        if(!ok){
            cout<<-1<<'\n';
            continue;
        }
        sort(a.begin(), a.end(), greater<int>());
        for(int i = 0 ; i < n ; i++){
            cout<<a[i]<<(i + 1 < n ? ' ' : '\n');
        }
    }
}