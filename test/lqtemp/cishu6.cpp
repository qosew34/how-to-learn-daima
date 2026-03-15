#include <iostream>
#include <vector>
using namespace std;
int main()
{
  // 请在此输入您的代码
  int n;cin>>n;
  vector<int> t(n);
  for(int i = 0 ; i < n ; i++) cin>>t[i];
  vector<int> cishu;
  for(int i = 0 ; i < n/2 ; i++){
    cishu.push_back(t[i]-t[n-i-1]);
  }
  int ans = 0;
  for(int i = 0 ; i < n/2 ; i++){
    if(i<n/2-1){
      if(cishu[i]*cishu[i+1]<=0){
        ans+=abs(cishu[i]);
      }
      else{
        if(cishu[i]>0){
        if(cishu[i]<cishu[i+1]){
          ans+=cishu[i];
          cishu[i+1]-=cishu[i];
        }
        else{
          ans+=cishu[i];
          cishu[i+1] = 0;
        }}
        else{
             if(cishu[i]>cishu[i+1]){
          ans-=cishu[i];
          cishu[i+1]-=cishu[i];
        }
        else{
          ans-=cishu[i];
          cishu[i+1] = 0;
        }
        }
      }
    }
    else ans+=cishu[i];
  }
  cout<<ans<<endl;
  return 0;
}