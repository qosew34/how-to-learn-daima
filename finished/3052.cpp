#include <bits/stdc++.h>
using namespace std;

int best_cnt[1 << 18];
long long best_weight[1 << 18];

vector<int> cow;

int n, w;

int ans = 20;

void dfs(int cnt, int mask, long long total){

    if(mask == (1 << n) - 1){
        ans = min(ans, cnt);
        return;
    }

    if(cnt > best_cnt[mask]) return;

    if(cnt == best_cnt[mask] && total >= best_weight[mask])
        return;

    best_cnt[mask] = cnt;
    best_weight[mask] = total;

    for(int i = 0; i < n; i++){

        if(mask & (1 << i)) continue;

        if(total + cow[i] > w){

            dfs(cnt + 1,
                mask | (1 << i),
                cow[i]);
        }
        else{

            dfs(cnt,
                mask | (1 << i),
                total + cow[i]);
        }
    }
}

int main(){

    cin >> n >> w;

    cow.resize(n);

    for(int i = 0; i < (1 << 18); i++){
        best_cnt[i] = 20;
        best_weight[i] = 1e18;
    }

    for(int i = 0; i < n; i++)
        cin >> cow[i];

    for(int i = 0; i < n; i++){

        dfs(1,
            1 << i,
            cow[i]);
    }

    cout << ans << endl;
}#include <bits/stdc++.h>
using namespace std;

int best_cnt[1 << 18];
long long best_weight[1 << 18];

vector<int> cow;

int n, w;

int ans = 20;

void dfs(int cnt, int mask, long long total){

    if(mask == (1 << n) - 1){
        ans = min(ans, cnt);
        return;
    }

    if(cnt > best_cnt[mask]) return;

    if(cnt == best_cnt[mask] && total >= best_weight[mask])
        return;

    best_cnt[mask] = cnt;
    best_weight[mask] = total;

    for(int i = 0; i < n; i++){

        if(mask & (1 << i)) continue;

        if(total + cow[i] > w){

            dfs(cnt + 1,
                mask | (1 << i),
                cow[i]);
        }
        else{

            dfs(cnt,
                mask | (1 << i),
                total + cow[i]);
        }
    }
}

int main(){

    cin >> n >> w;

    cow.resize(n);

    for(int i = 0; i < (1 << 18); i++){
        best_cnt[i] = 20;
        best_weight[i] = 1e18;
    }

    for(int i = 0; i < n; i++)
        cin >> cow[i];

    for(int i = 0; i < n; i++){

        dfs(1,
            1 << i,
            cow[i]);
    }

    cout << ans << endl;
}