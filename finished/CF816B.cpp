#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q,k;
    cin>>n>>k>>q;

    const int MAXT = 200000;

    vector<int> diff(MAXT + 3, 0);

    for(int i = 0 ; i < n ; i++){
        int l,r;cin>>l>>r;
        diff[l] += 1;
        diff[r + 1] -= 1;
    }

    vector<int> cover(MAXT + 2, 0);
    for(int t = 1; t <= MAXT; t++){
        cover[t] = cover[t-1] + diff[t];
    }

    vector<int> accPrefix(MAXT + 2, 0);
    for(int t = 1; t <= MAXT; t++){
        accPrefix[t] = accPrefix[t-1] + (cover[t] >= k ? 1 : 0);
    }

    while(q){
        q--;
        int a,b;
        cin>>a>>b;
        int ans = accPrefix[b] - accPrefix[a-1];
        cout << ans << "\n";
    }
}