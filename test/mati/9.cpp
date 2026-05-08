#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(t--){

        int n,m;cin>>n>>m;
        vector<long long> qs(n);
        for(int i = 0 ; i < n ; i++) cin>>qs[i];
        priority_queue<pair<long long,long long>> pq;
        for(int i = 0 ; i < m ; i++){
            long long u,v;cin>>u>>v;
            u--;
            pq.push({u,v});
        }
        long long ans = 0;
        vector<long long> ks;
        int count = n;
        for(int i = 0 ; i < m ; i++){
            auto[a,b]=pq.top();
            pq.pop(); 
            while(count>a){
                count--;
                ks.push_back(qs[count]);
            }
            if(ks.empty()) continue;
            sort(ks.begin(),ks.end());
            if(ks[0]>b) continue;
            int loc = 0;
            int l = 0 , r = ks.size() - 1;

            while(l<=r){
                int mid =(l+r)/2;
                if(ks[mid]<=b){
                    loc = mid;
                    l = mid+1;
                } 
                else r = mid -1 ;
            }
            ans+=ks[loc];
            ks.erase(ks.begin()+loc);

           // cout<<"ok2"<<endl;

        }
            cout<<ans<<endl;
    }

}