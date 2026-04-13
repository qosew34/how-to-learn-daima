#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> checks(n);
    for(int i = 0 ; i < n ; i++) cin>>checks[i];

    sort(checks.begin(), checks.end()); // 若题目保证有序，可删掉

    int l = 1 , r = checks[n-1];
    int ans = r;

    while(l<=r){ // 改成 <= 更稳
        int mid = (l+r)/2;

        long long count = 0;
        int loc = 0;

        long long bestSave = 0; 
        for(int i = 0 ; i < n ; i++){
            long long d = (long long)checks[i] - loc;
            loc = checks[i];

            if(d <= mid) continue;

            long long need0 = (d - 1) / mid; 
            long long rest = d - 2LL * mid;
            long long need1 = 0;             
            if(rest > 0) need1 = (rest + mid - 1) / mid;

            count += need0;
            bestSave = max(bestSave, need0 - need1);

            if(count > (long long)m + bestSave) break; 
        }

        if(count - bestSave <= m) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout<<ans<<endl;
}