/*#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    if(n==3){//==!!!!
        cout<<3;
        return 0;
    }
    int result=1;//初始化！！！
    vector<int> fj;
    int total=0;
    int m=n;
    for(int i=2;i<=m/2;i++){
        if(n-i>0){
            fj.push_back(i);
            total+=1;
            n-=i;
        }
        else{
            for(int j=total-n;j<total;j++){
                fj[j]++;
            }
            break;
        }
    }
    for(int i=0;i<total;i++){
        result*=fj[i];
        cout<<fj[i]<<" ";
    }
    cout<<endl<<result<<endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long maxProduct = 0; // 用于记录最大乘积
vector<int> result;       // 记录最大乘积对应的分解方式

void dfs(int n, int prev, long long product, vector<int>& tmp) {
    // 如果 n 被分解完毕
    if (n == 0) {
        if (product > maxProduct) {
            maxProduct = product;
            result = tmp;
        }
        return;
    }

    // 从 prev+1 开始，保证互不相同且递增
    for (int i = prev + 1; i <= n; ++i) {
        tmp.push_back(i);
        dfs(n - i, i, product * i, tmp);
        tmp.pop_back();
    }
}

int main() {
    int n;
    cin >> n;

    maxProduct = n; // 如果不分解就是 n 本身
    result = {n};   // 默认只用 n 本身

    vector<int> tmp;
    dfs(n, 0, 1, tmp);


    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i + 1 < result.size()) cout << "+";
    }
    cout << endl;
    cout << maxProduct << endl;
    return 0;
}*/
#include <bits/stdc++.h>
using namespace std;

// big integer in base 1e9, least-significant block first
using BigInt = vector<uint32_t>;
const uint32_t BASE = 1000000000u;

// multiply big integer a by small integer b (b fits in 32-bit)
void multiply_small(BigInt &a, uint32_t b) {
    uint64_t carry = 0;
    for (size_t i = 0; i < a.size(); ++i) {
        uint64_t prod = uint64_t(a[i]) * b + carry;
        a[i] = uint32_t(prod % BASE);
        carry = prod / BASE;
    }
    while (carry) {
        a.push_back(uint32_t(carry % BASE));
        carry /= BASE;
    }
}

// print big integer
void print_bigint(const BigInt &a) {
    if (a.empty()) {
        cout << "0\n";
        return;
    }
    // most significant block first
    int i = int(a.size()) - 1;
    cout << a[i];
    for (--i; i >= 0; --i) {
        cout << setw(9) << setfill('0') << a[i];
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    if (n <= 0) {
        cout << "请输入正整数 n\n";
        return 0;
    }

    // dp[s] = 最大的 log(乘积) 能达到的值，使选的互不相同的自然数之和为 s
    const long double NEG_INF = -1e300L;
    vector<long double> dp(n+1, NEG_INF);
    vector<int> parent(n+1, -1);
    dp[0] = 0.0L;

    for (int x = 1; x <= n; ++x) {
        long double lx = log((long double)x);
        for (int s = n; s >= x; --s) {
            if (dp[s-x] > NEG_INF/2) {
                long double cand = dp[s-x] + lx;
                if (cand > dp[s]) {
                    dp[s] = cand;
                    parent[s] = x;
                }
            }
        }
    }

    // 若出问题，则退回单独取 n
    vector<int> parts;
    if (dp[n] <= NEG_INF/2) {
        parts.push_back(n);
    } else {
        int cur = n;
        while (cur > 0) {
            int x = parent[cur];
            if (x == -1) { // 不可还原，保守处理
                parts.clear();
                parts.push_back(n);
                break;
            }
            parts.push_back(x);
            cur -= x;
        }
        sort(parts.begin(), parts.end());
    }

    // 输出分解
    for (size_t i = 0; i < parts.size(); ++i) {
        if (i) cout << ' ';
        cout << parts[i];
    }
    cout << '\n';

    // 计算大整数乘积
    BigInt prod;
    prod.push_back(1u);
    for (int v : parts) multiply_small(prod, (uint32_t)v);

    // 输出乘积
    print_bigint(prod);

    return 0;
}