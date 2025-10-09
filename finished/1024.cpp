#include <bits/stdc++.h>
using namespace std;
void cal(double a,double b,double c,double d,double x,double &y){
    y=a*x*x*x+b*x*x+c*x+d;
}

int main(){
    double a,b,c,d;
    cin>>a>>b>>c>>d;
    double x,y;
    double result[201]={0};
    vector<double> ans;
    for (int i=0;i<201;i++){
        cal(a,b,c,d,i-100.0,y);
        result[i]=y;
    }
    double left_part,right_part,mid_part;
    double left,right,mid;
    for (int j=0;j<200;j++){
        if (result[j]*result[j+1]<=0){
            left_part=j-100.0;right_part=j-99.0;
            while(right_part-left_part>0.001){
                mid_part=(left_part+right_part)/2.0;
                cal(a,b,c,d,mid_part,mid);
                cal(a,b,c,d,left_part,left);
                if(mid*left<=0){
                    right_part=mid_part;
                }
                else{
                    left_part=mid_part;
                }
                mid_part=(left_part+right_part)/2.0;
            }
            ans.push_back(mid_part);
        }
    }
    vector<double> superans;
    superans.push_back(ans[0]);
    for(int k=1;k<ans.size();k++){
        if (abs(superans.back()-ans[k])>0.1){
            superans.push_back(ans[k]);
        }
    }
    cout<<fixed<<setprecision(2)<<superans[0]<<" "<<superans[1]<<" "<<superans[2]<<endl;
    return 0;
}
/*#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

void cal(double a, double b, double c, double d, double x, double &y) {
    y = a * x * x * x + b * x * x + c * x + d;
}

int main() {
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    double y;
    double result[201] = {0};
    vector<double> ans;
    for (int i = 0; i < 201; i++) {
        cal(a, b, c, d, i - 100.0, y);
        result[i] = y;
    }
    double left_part, right_part, mid_part;
    double left_val, mid_val;
    for (int j = 0; j < 200; j++) {
        if (result[j] * result[j + 1] <= 0.0) {
            left_part = j - 100.0;
            right_part = j - 99.0;
            while (right_part - left_part > 0.001) {  // 更高精度以确保2位准确
                mid_part = (left_part + right_part) / 2.0;
                cal(a, b, c, d, mid_part, mid_val);
                cal(a, b, c, d, left_part, left_val);
                if (mid_val * left_val <= 0.0) {
                    right_part = mid_part;
                } else {
                    left_part = mid_part;
                }
            }
            ans.push_back((left_part + right_part) / 2.0);  // 取中点作为根
        }
    }
    // 去重和排序
    sort(ans.begin(), ans.end());
    vector<double> superans;
    if (!ans.empty()) {
        superans.push_back(ans[0]);
        for (size_t k = 1; k < ans.size(); ++k) {
            if (fabs(ans[k] - superans.back()) > 0.1) {  // 阈值0.1 >1的保证
                superans.push_back(ans[k]);
            }
        }
    }
    // 输出，假设正好3个
    cout << fixed << setprecision(2);
    cout << superans[0] << " " << superans[1] << " " << superans[2] << endl;
    return 0;
}*/