#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    double p;
    cin >> n >> p;
    vector<double> a(n), b(n);  // a[i]=消耗, b[i]=初始能量
    double l = 0, r = 2e12;  // 足够大的上界
    double sum_a = 0;
    
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        sum_a += a[i];
    }

    if(sum_a <= p){
        cout << -1 << endl;
        return 0;
    }
    
    // 二分搜索最大时间
    while(r - l > 1e-6){
        double mid = (l + r) / 2;
        double need_charge = 0;
        
        // 计算在mid时间内需要充电的总能量
        for(int i = 0; i < n; i++){
            double consume = a[i] * mid;  // 消耗能量
            if(consume > b[i]){
                need_charge += consume - b[i];
            }
        }
        
        // 充电宝能否在mid时间内满足需求
        if(need_charge <= p * mid){
            l = mid;  // 可以满足，尝试更长时间
        } else {
            r = mid;  // 不能满足，尝试更短时间
        }
    }
    cout  << l << endl;
}