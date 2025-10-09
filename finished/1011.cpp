#include <bits/stdc++.h>
using namespace std;
int main(){
int a,n,m,x;
cin>>a>>n>>m>>x;
double all[n]={0};
int on[n]={0};
double off[n]={0};
all[0]=0;
on[0]=a;
off[0]=0;
all[1]=a;
on[1]=off[0];
off[1]=off[0];
for (int y=2;y<n;y++){
    off[y]=on[y-1];
    on[y]=on[y-1]+on[y-2];
    all[y]=all[y-1]+on[y]-off[y];
}
int mi=0;
int ha[n]={0};
ha[0]=ha[1]=1;
for (int ji=2;ji<n;ji++){
ha[ji]=ha[ji-1]+ha[ji-2];
mi+=ha[ji-2];
}
int b=(m-all[n-1])/mi;
off[0]=b;
on[1]=off[0];
off[1]=off[0];
for (int y=2;y<n;y++){
    off[y]=on[y-1];
    on[y]=on[y-1]+on[y-2];
    all[y]=all[y-1]+on[y]-off[y];
}
cout<<all[x]<<endl;
return 0;
}
/*#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, n, m, x;
    cin >> a >> n >> m >> x;
    if (n == 1) {
        if (x == 1) cout << a << endl;
        else cout << 0 << endl;
        return 0;
    }
    if (x == n) {
        cout << 0 << endl;
        return 0;
    }
    if (n == 2) {
        cout << a << endl;
        return 0;
    }
    // n >= 3, x < n
    vector<double> all(n + 1, 0.0);  // 1-based: all[1..n-1]
    vector<double> on(n + 1, 0.0);
    vector<double> off(n + 1, 0.0);
    // 第一次模拟: 假设 b=0
    on[1] = a;
    off[1] = 0.0;
    all[1] = a;
    all[2] = a;
    on[2] = 0.0;  // b=0
    off[2] = 0.0;
    for (int y = 3; y <= n - 1; ++y) {  // 从第 3 站开始 (y=3)
        on[y] = on[y - 1] + on[y - 2];
        off[y] = on[y - 1];
        all[y] = all[y - 1] + on[y] - off[y];
    }
    double arriving_n = all[n - 1];
    // 计算 mi = F_{n-2} - 1
    vector<long long> ha(n + 1, 0);
    double mi = 0.0;
    if (n > 3) {
        ha[1] = 1;
        ha[2] = 1;
        for (int ji = 3; ji <= n - 1; ++ji) {
            ha[ji] = ha[ji - 1] + ha[ji - 2];
        }
        mi = ha[n - 2] - 1;  // ha[1]=F1=1, ha[2]=F2=1, ..., ha[n-2]=F_{n-2}
    }
    double b = 0.0;
    if (mi == 0) {
        b = 0.0;  // 假设输入有效
    } else {
        b = (m - arriving_n) / mi;
    }
    // 第二次模拟: 用正确 b
    on[1] = a;
    off[1] = 0.0;
    all[1] = a;
    all[2] = a;
    on[2] = b;
    off[2] = b;
    for (int y = 3; y <= n - 1; ++y) {
        on[y] = on[y - 1] + on[y - 2];
        off[y] = on[y - 1];
        all[y] = all[y - 1] + on[y] - off[y];
    }
    cout << fixed << setprecision(0) << all[x] << endl;
    return 0;
}*/