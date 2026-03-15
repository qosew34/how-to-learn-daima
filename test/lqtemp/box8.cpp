#include <iostream>
#include <vector>
using namespace std;
int main()
{
  // 请在此输入您的代码
  //无脑贪心
  //k是体力
  int n,k;cin>>n>>k;
  vector<int> magic(n);
  for(int i = 0 ; i < n ; i++) cin>>magic[i];
  vector<int> ans(n,-1);
  for(int i = 0 ; i < n ; i++){
    int loc = max(0,i-k),count = magic[loc];
    for(int j = max(0,i-k) ; j <= min(n-1,i+k) ; j++){
      if(magic[j]>count){
        loc = j;count = magic[j];
      }
      else if(magic[j]==count){
        if(abs(i-j)<abs(loc-i)) loc = j;
      }
    }
    magic[loc] = -1;
    ans[i] = count;
    k-=(abs(loc-i));
  }
  for(int i = 0 ; i < n ; i++){
    cout<<ans[i];
    if(i!=n-1) cout<<" ";
  }
  return 0;
}