#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;cin>>n>>m;
    vector<int> a(n);
    long long total = 0;
    for(int i = 0 ; i < n ; i++) {
        cin>>a[i];
        total += a[i];
    }

    if(m == 1){
        cout << total << '\n';
        return 0;
    }

    long long l = *max_element(a.begin(), a.end()), r = total;
    long long ans = r;

    while(l <= r){
        long long mid = (l + r) / 2;
        int count = 1;     
        long long cur = 0;

        for(int i = 0 ; i < n ; i++){
            if(cur + a[i] > mid){
                count++;
                cur = a[i];
            } else {
                cur += a[i];
            }

            if(count > m) break;  
        }

        if(count <= m){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    cout<<ans<<endl;
}