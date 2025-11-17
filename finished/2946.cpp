#include<bits/stdc++.h>
using namespace std;

int main(){
const int MOD = 100000000;
long long n;
int f;
if (!(cin >> n >> f)) return 0;

vector<int> dp(f, 0);
dp[0] = 1; // empty subset

for (long long i = 0; i < n; ++i) {
    long long x;
    cin >> x;
    int r = int(((x % f) + f) % f);
    vector<int> prev = dp; // snapshot before adding current element
    for (int j = 0; j < f; ++j) {
        int idx = (j + r) % f;
        dp[idx] = (dp[idx] + prev[j]) % MOD;
    }
}

// subtract the empty subset
int ans = dp[0] - 1;
if (ans < 0) ans += MOD;
cout << ans << '\n';
return 0;
}

/*
逻辑有错
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;int f;
    cin>>n>>f;
    vector<int> amount(f,0);
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        amount[temp%f]++;
    }
    vector<vector<int>> team(n+1,vector<int>(f,0));//n+1行n个物品
    for(int i = 1;i<n+1;i++){
        int total=amount[0];
        int local=0;
        while(i>total){
            local++;
            total+=amount[local];
        }
        for(int j=0;j<f;j++){
            int temp=j+local;
            if(temp>=f){
                temp%=f;
            }
            team[i][local]++;
            team[i][temp]+=team[i-1][local];
        }
    }
    cout<<team[n][0];
}*/