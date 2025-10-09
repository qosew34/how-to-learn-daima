/*
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long b;
    cin>>n>>b;
    int temp_cow_height;
    int cow_height_addition[b]={0};
    for (int i=0;i<n;i++){
        cin>>temp_cow_height;
        cow_height_addition[i]=temp_cow_height;
    }
    sort(cow_height_addition,cow_height_addition+n,greater<int>());
    

for (long long i=0;i<b;i++){
    for(long long j=i+1;j<b;j++){
        if(cow_height_addition[i+j]==0){
            cow_height_addition[i+j]=cow_height_addition[i]+cow_height_addition[j];
        }
        else if (cow_height_addition[i+j]>cow_height_addition[i]+cow_height_addition[j]){
            cow_height_addition[i+j]=cow_height_addition[i]+cow_height_addition[j];
        }
    }
}
cout<<cow_height_addition[b-1]<<endl;
}
内存太大

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long b;
    cin>>n>>b;
    int temp_cow_height;
    vector<int> cow_height_addition={0};
    for (int i=0;i<n;i++){
        cin>>temp_cow_height;
        cow_height_addition[i]=temp_cow_height;
    }
    vector<long long>dp(b+1,b*b);
    dp[0]=0;
    for (auto h : cow_height_addition) {  // 遍历每个高度
    for (long long j = b; j >= h; --j) {  // 逆序更新，避免重复用同一 h
        if (dp[j - h] != b*b) {
            dp[j] = min(dp[j], dp[j - h] + 1);
        }
    }
}
}
也炸了

#include <bits/stdc++.h>
using namespace std;

int calculate(vector<long long> &cow_height,long long b,int n){

    long long sum=0;
    int total=0;
    for(int k=0;k<n;k++){
        sum+=cow_height[k];
        total++;
        if(sum>=b) break;
    }
    long long over=sum-b;
    set<long long> caught;
    for(int j=0;j<total;j++){
        caught.insert(cow_height[j]);
    }
    if(caught.count(over)){
        return total-1;
    }
    for(auto x:caught){
        long long need=x-over;
        if(need>0&&caught.count(need)==0){
            bool found=false;
            for(int l=total;l<n;l++){
                if(cow_height[l]==need){
                    found==true;
                    break;
                }
            }
            if(found){return total;}
        }
    }
    return total;
}
int main(){
    int n;
    long long b;
    cin>>n>>b;
    int temp_cow_height;
    vector<long long> cow_height={0};
    for (int i=0;i<n;i++){
        cin>>temp_cow_height;
        cow_height[i]=temp_cow_height;
    }
    sort(cow_height.rbegin(),cow_height.rend());
    int jieguo=calculate(cow_height,b,n);
    cout<<jieguo<<endl;
    return 0;
}
还是re
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long b;
    cin>>n>>b;
    int temp_cow_height;
    vector<int> cow_height_addition={0};
    for (int i=0;i<n;i++){
        cin>>temp_cow_height;
        cow_height_addition.push_back(temp_cow_height);
    }
        sort(cow_height_addition.rbegin(),cow_height_addition.rend());
    long long sum=0;
    int total=0;
    for(int k=0;k<n;k++){
        sum+=cow_height_addition[k];
        total++;
        if(sum>=b) break;
    }
    cout<<total<<endl;
    return 0;
}
/*傻逼题目，想复杂了*/