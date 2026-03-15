#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
  
  int n,k;cin>>n>>k;
  //二分+贪心+模拟
  vector<int> as(k,0);
  for(int i = 0 ; i < k ; i++) cin>>as[i];
  sort(as.begin(),as.end());
  int l = 0,r = n;int ans = n;
  while(l<r){
    int mid = (l+r)/2;
    int prer = 1;bool is = true;
    for(int i = 0 ; i < k ; i++){
      if(as[i]-prer>mid){
        is = false;break;
      }
      int nr = (mid-2*prer)/2;
      if(i==k-1){
        if(nr<n) is = false;
      }
      prer = nr;
    }
    if(is){r = mid-1;ans = min(ans,mid);
  }else l = mid+1;}
  cout<<ans<<endl;
  return 0;
}