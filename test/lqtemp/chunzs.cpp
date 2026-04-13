#include <bits/stdc++.h>
using namespace std;

int main(){
    //2357
    //先质数表再判断
    int limit = 20210605;
    vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;  // 0 和 1 不是素数
    for (int i = 2; i * i <= limit; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                isPrime[j] = false;
            }
        }
    }
    int ans = 0;
    for (int i = 2; i <= limit; ++i) {  // 从 2 开始
        if (isPrime[i]){
            string s = to_string(i);
            bool is = true;
            for(auto a : s){
                if(!(a=='2'||a=='3'||a=='5'||a=='7')) is = false;
            }
            if(is) ans++;
        }
    }
    cout<<ans;

}