#include <bits/stdc++.h>
using namespace std;

bool bfs(vector<vector<char>> &mp,int x,int y,int n, int m){
    queue<pair<int,int>> q;
    q.push({x,y});
    vector<int> xs = {-1,1,0,0};
    vector<int> ys = {0,0,1,-1};
    while(!q.empty()){
        auto a = q.front();q.pop();
        int b = a.first,c=a.second;
        if(b>=2*n||c>=2*m) continue;
        if(b<0||c<0) continue;
        if(mp[b][c]!='.'&&mp[b][c]!='S') continue;
        if(b>=n||c>=m){
            if(mp[b][c]=='S'){
                return true;
            }
        }
        mp[b][c]='a';
        for(int i = 0 ; i < 4 ; i++) q.push({b+xs[i],c+ys[i]});
    }
    return false;
}


int main(){
    int n, m;
    while(cin>>n>>m){
        vector<vector<char>> mp(2*n,vector<char>(2*m));
        int x = 0;int y = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                char temp;cin>>temp;
                if(temp=='S'){
                    x=i;y=j;
                }
                for(int k = 0 ; k < 2 ; k++){
                    for(int l = 0 ; l < 2 ; l++){
                        mp[i+k*n][j+l*m]=temp;
                    }
                }
            }
        }
        bool ans = bfs(mp,x,y,n,m);
        if(ans) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
/*#include <bits/stdc++.h>
using namespace std;
using ll = long long;

static ll floor_div(ll a, ll b) {
    if (b <= 0) throw;
    if (a >= 0) return a / b;
    // floor division for negative a
    return - ((-a + b - 1) / b);
}

struct State {
    int i, j;
    ll bx, by;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    while ( (cin >> n >> m) ) {
        vector<string> base(n);
        int sx = -1, sy = -1;
        for (int i = 0; i < n; ++i) {
            cin >> base[i];
            for (int j = 0; j < m; ++j) {
                if (base[i][j] == 'S') { sx = i; sy = j; }
            }
        }
        // store for each modulo cell the first visited block (bx,by)
        const pair<ll,ll> UNDEF = {LLONG_MIN, LLONG_MIN};
        vector<pair<ll,ll>> first_block((size_t)n * m, UNDEF);

        queue<State> q;
        q.push({sx, sy, 0LL, 0LL});
        first_block[sx * m + sy] = {0LL, 0LL};

        bool ok = false;
        const int dx[4] = {-1, 1, 0, 0};
        const int dy[4] = {0, 0, -1, 1};

        while (!q.empty() && !ok) {
            State cur = q.front(); q.pop();
            for (int d = 0; d < 4; ++d) {
                ll ax = cur.bx * (ll)n + cur.i + dx[d];
                ll ay = cur.by * (ll)m + cur.j + dy[d];
                ll nbx = floor_div(ax, n);
                ll nby = floor_div(ay, m);
                int ni = int(ax - nbx * (ll)n); // 0..n-1
                int nj = int(ay - nby * (ll)m); // 0..m-1
                // safety (shouldn't happen)
                if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                if (base[ni][nj] == '#') continue;
                size_t idx = (size_t)ni * m + nj;
                auto fb = first_block[idx];
                if (fb == UNDEF) {
                    first_block[idx] = {nbx, nby};
                    q.push({ni, nj, nbx, nby});
                } else if (fb.first != nbx || fb.second != nby) {
                    // same modulo cell visited in a different block -> can go to infinity
                    ok = true;
                    break;
                }
                // else same block seen before -> skip
            }
        }

        cout << (ok ? "Yes" : "No") << '\n';
    }
    return 0;
}*/