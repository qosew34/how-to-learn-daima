#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> fruits;
    int temp,energy=0;
    for(int i=0;i<n;i++){
        cin>>temp;
        fruits.push_back(temp);
    }
    sort(fruits.begin(),fruits.end());
    for(int j=0;j<n-1;j++){
        fruits.push_back(fruits[2*j]+fruits[2*j+1]);
        energy+=fruits[2*j]+fruits[2*j+1];
       // sort(fruits.begin()+2*j,fruits.end());这样会tle，得自己想办法插

    }//第一次01，第二次插进去23+sort,第四次56
    //全插完2n-1个。？
    cout<<energy<<endl;
    return 0;
}/*#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    priority_queue<long long, vector<long long>, greater<long long>> pq;//构建最小堆
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        pq.push(x);
    }
    long long energy = 0;
    while (pq.size() > 1) {
        long long a = pq.top(); pq.pop();
        long long b = pq.top();获取顶pq.pop();扔
        long long sum_ab = a + b;
        energy += sum_ab;
        pq.push(sum_ab);
    }
    cout << energy << endl;
    return 0;
}
    使用最小堆写*/