//dfs练过了，偷看了下标签，让我们练道bfs
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b;
    cin>>n>>a>>b;
    vector<int> elavator;//电梯能跳到哪
    a-=1;b-=1;
    vector<int> min_step(n,n+1);//最少几步
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        elavator.push_back(temp);
    }
    min_step[a]=0;
    queue<int> q;//只允许一段入一段出，刚学的
    q.push(a);
    while (!q.empty()) {
    int current = q.front(); q.pop();
    // 向上
    int upstair = current + elavator[current];
    if (upstair <= n - 1) {
        if (min_step[upstair] > min_step[current] + 1) {  // 只在改善时更新和入队，这里原来忘写了
            min_step[upstair] = min_step[current] + 1;
            q.push(upstair);
        }
    }//我去你妈的预置变量名，要多打好几个字
    // 向下
    int downstair = current - elavator[current];
    if (downstair >= 0) {
        if (min_step[downstair] > min_step[current] + 1) {  // 同上
            min_step[downstair] = min_step[current] + 1;
            q.push(downstair);
        }
    }
}//忘记检查不行了
if (min_step[b] == n + 1) {
    cout << -1 << endl;
} else {
    cout << min_step[b] << endl;
}
}