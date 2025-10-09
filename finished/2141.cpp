#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int num[n];
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    vector<int> add_result;
    for (int j=0;j<n;j++){
        for(int k=j+1;k<n;k++){
            add_result.push_back(num[j]+num[k]);
        }
    }
    sort(add_result.begin(),add_result.end());
    vector<int> add_result_no_same;
    add_result_no_same.push_back(add_result[0]);
    for (int l=1;l<add_result.size()/*不用-1*/;l++){
        if (add_result[l]!=add_result[l-1]){
            add_result_no_same.push_back(add_result[l]);
        }
    }
    int answer=0;
    for (int m=0;m<n;m++){/*笔误写成啥啥.size()时间会炸*/
        if (find(add_result_no_same.begin(),add_result_no_same.end(),num[m])!=add_result_no_same.end())
        answer++;
    }
    cout<<answer<<endl;
    return 0;
}
/*ai优化版，学一下

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> num(n);  // 用 vector，long long 防溢出
    for (auto &x : num) cin >> x;
    
    vector<long long> sorted_num = num;
    sort(sorted_num.begin(), sorted_num.end());
    
    int answer = 0;
    for (int m = 0; m < n; m++) {
        long long target = num[m];
        int left = 0, right = n - 1;
        bool found = false;
        while (left < right) {
            long long sum_val = sorted_num[left] + sorted_num[right];
            if (sum_val == target) {
                found = true;
                break;
            } else if (sum_val < target) {
                left++;
            } else {
                right--;
            }
        }
        if (found) answer++;
    }
    cout << answer << endl;
    return 0;
}*/