#include <bits/stdc++.h>
using namespace std;

int main(){
    int t ; cin>>t;
    for(int k = 0 ; k < t ; k++){
        int n,q;cin>>n>>q;
        vector<int> ele;
        for(int j = 0 ; j < n ; j++){
            int temp;cin>>temp;
            if(!ele.empty()) if(ele[ele.size()-1]==1&&temp==1) continue;
            ele.push_back(temp);
        }
        n = ele.size();
        vector<long long> query(q);
        long long m = 0;
        for(int i = 0 ; i < q; i++){
            cin>>query[i];
            m=max(query[i],m);
        }
        unordered_set<long long> possible;
        for(int i = 0 ; i < n ; i++){
            long long temp = 1;
            for(int j = i ; j < n ; j++){
                temp*=ele[j];
                if(temp>m)break;
                possible.insert(temp);
            }
        }
        for(int i = 0 ; i < q; i++){
            int ans = query[i];
            if(possible.find(ans)!=possible.end()) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
}