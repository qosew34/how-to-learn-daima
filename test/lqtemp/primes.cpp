#include <iostream>
#include <vector>
using namespace std;
int main()
{
  // 请在此输入您的代码
  vector<bool> primes(50000,true);
  int count = 0;
  for(int i = 2 ; i < 50000 ; i++){
    if(primes[i]){
      count++;
      for(int j = i ; j < 50000 ; j+=i){
        primes[j] = false;
      }
      if(count==2025) {cout<<i<<endl;return 0;}
    }
    
  }
  return 0;
}