#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

const ull base = 131;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(2*n);
        for(int i = 0; i < 2*n; i++) cin >> a[i];

        vector<array<int,2>> pos(n);
        vector<int> cnt(n, 0);

        for(int i = 0; i < 2*n; i++){
            int x = a[i];
            if(cnt[x] == 0) pos[x][0] = i;
            else pos[x][1] = i;
            cnt[x]++;
        }

        vector<ull> h(2*n+1,0), rh(2*n+1,0), p(2*n+1,1);

        for(int i = 1; i <= 2*n; i++){
            h[i] = h[i-1]*base + a[i-1] + 1;
            p[i] = p[i-1]*base;
        }

        for(int i = 1; i <= 2*n; i++){
            rh[i] = rh[i-1]*base + a[2*n-i] + 1;
        }

        auto get_hash = [&](int l,int r){
            return h[r+1] - h[l]*p[r-l+1];
        };

        auto get_rhash = [&](int l,int r){
            int rl = 2*n-1-r;
            int rr = 2*n-1-l;
            return rh[rr+1] - rh[rl]*p[rr-rl+1];
        };

        int L = 2*n, R = -1;
        int ans = 0;

        for(int m = 1; m <= n; m++){
            int x = m-1;

            L = min(L, min(pos[x][0], pos[x][1]));
            R = max(R, max(pos[x][0], pos[x][1]));

            if(get_hash(L,R) == get_rhash(L,R)){
                ans = m;
            }
        }

        cout << ans << '\n';
    }
}