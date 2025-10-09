#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>> location(n,vector<int>(3,0));
    int temp1,temp2,temp3;
    for(int i=0;i<n;i++){
        cin>>temp1>>temp2>>temp3;
        location[i][0]=temp1;
        location[i][1]=temp2;
        location[i][2]=temp3;
    }
sort(location.begin(), location.end(), [](const vector<int>& a, const vector<int>& b) {
    return a[2] > b[2];  // 冒泡太慢啦
});
    double ans=0;
    double x,y,z;
    for (int l=0;l<n-1;l++){
        x=(location[l][0]-location[l+1][0]);
        y=(location[l][1]-location[l+1][1]);
        z=(location[l][2]-location[l+1][2]);
        ans+=sqrt(x*x+y*y+z*z);
    }
cout<<fixed<<setprecision(3)<<ans<<endl;
return 0;
}