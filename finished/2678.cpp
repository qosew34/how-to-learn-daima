#include  <bits/stdc++.h>
using namespace std;

int main(){
    int l,m,n;
    cin>>l>>n>>m;
    int stone[n+5]={};
    int temp;
    int prev=0;
    for(int i=0;i<n;i++){
        cin>>temp;
        stone[i]=temp-prev;
        prev=temp;
    }
    stone[n]=l-prev;
    //二分跳跃距离
    int min=0;int max=l;
    while(min<=max){
        int mid=(min+max)/2;
        int moved=0;
        int dis=0;
        for(int j=0;j<n+1;j++){
            dis+=stone[j];
            if(dis>=mid){
                dis=0;
            }
            else{
                moved++;
            }
            if(moved>m){
                break;
            }
        }
        if(moved>m)max=mid-1;
        else min=mid+1;

    }
    cout<<max;
}/*这个版本末尾计算有问题，不改了，今天头疼
#include <bits/stdc++.h>
using namespace std;

bool check(int mid, const vector<int>& pos, int n, int m, int l) {
    int cnt = 0;  // 移除数
    int last = 0;  // 上次落地
    for (int i = 0; i < n; ++i) {
        if (pos[i] - last >= mid) {
            last = pos[i];
        } else {
            ++cnt;
            if (cnt > m) return false;
        }
    }
    // 检查最后一段
    if (l - last < mid) {
        if (last == 0) return false;  // 无石头，无法修复
        ++cnt;
    }
    return cnt <= m;
}

int main() {
    int l, n, m;
    cin >> l >> n >> m;
    vector<int> pos(n);
    for (int i = 0; i < n; ++i) {
        cin >> pos[i];
    }
    // 二分：最大化最小距离
    int low = 0, high = l;
    int ans = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(mid, pos, n, m, l)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}*/