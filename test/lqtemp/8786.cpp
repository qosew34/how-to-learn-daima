#include <bits/stdc++.h>
using namespace std;
using ll = long long;

static const ll MOD = 1000000007LL;

string minusOne(string s) {
    bool allZero = true;
    for (char c : s) {
        if (c == '1') { allZero = false; break; }
    }
    if (allZero) return "-1";

    for (int i = (int)s.size() - 1; i >= 0; --i) {
        if (s[i] == '1') {
            s[i] = '0';
            break;
        } else {
            s[i] = '1';
        }
    }

    int pos = 0;
    while (pos + 1 < (int)s.size() && s[pos] == '0') pos++;
    return s.substr(pos);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // dp[i][j]：喝了 i 次（-1）操作、做了 j 次（*2）操作后，达到某个二进制串的方案数
    vector<vector<unordered_map<string, ll>>> dp(
        m + 1, vector<unordered_map<string, ll>>(n + 1)
    );

    dp[0][0]["10"] = 1;

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            auto &cur = dp[i][j];
            if (cur.empty()) continue;

            // 做一次加倍：j -> j+1
            if (j + 1 <= n) {
                auto &nxt = dp[i][j + 1];
                for (const auto &kv : cur) {
                    const string &a = kv.first;
                    ll cnt = kv.second;
                    string b = a + '0';
                    ll &ref = nxt[b];
                    ref += cnt;
                    if (ref >= MOD) ref %= MOD;
                }
            }

            // 做一次喝一壶：i -> i+1
            if (i + 1 <= m) {
                auto &nxt = dp[i + 1][j];
                for (const auto &kv : cur) {
                    const string &a = kv.first;
                    ll cnt = kv.second;
                    string b = minusOne(a);
                    if (b == "-1") continue; // 不能再减就不转移
                    ll &ref = nxt[b];
                    ref += cnt;
                    if (ref >= MOD) ref %= MOD;
                }
            }
        }
    }

    ll ans = 0;
    auto &finalMap = dp[m][n];
    auto it = finalMap.find("0");
    if (it != finalMap.end()) ans = it->second % MOD;

    cout << ans << "\n";
    return 0;
}
/*#include <bits/stdc++.h>
using namespace std;
using ll = long long;

static const ll MOD = 1000000007LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    // dp[i][j][x] : used i shops, j flowers (among first N+M-1 steps), current wine x
    // We only simulate first (M-1) flowers, because the last step is forced to be a flower.
    vector<vector<vector<ll>>> dp(N + 1, vector<vector<ll>>(M, vector<ll>(M + 1, 0)));

    dp[0][0][2] = 1; // start with 2 dou

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M - 1; j++) {
            for (int x = 0; x <= M; x++) {
                ll cur = dp[i][j][x];
                if (!cur) continue;

                // next: shop
                if (i < N) {
                    long long nx = 2LL * x;
                    // If nx > M, then even if all remaining are flowers, cannot drink to 0 (need at least nx flowers).
                    if (nx <= M) {
                        dp[i + 1][j][(int)nx] = (dp[i + 1][j][(int)nx] + cur) % MOD;
                    }
                }

                // next: flower (only among first M-1 flowers)
                if (j < M - 1) {
                    if (x > 0) {
                        dp[i][j + 1][x - 1] = (dp[i][j + 1][x - 1] + cur) % MOD;
                    }
                }
            }
        }
    }

    // After first N shops and M-1 flowers, must have wine=1,
    // then the forced last flower makes it 0.
    cout << dp[N][M - 1][1] % MOD << "\n";
    return 0;
}
记录*2的位置，记录之后有的02数量
*/