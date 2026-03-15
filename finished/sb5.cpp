#include <iostream>
using namespace std;
int main()
{
  // 请在此输入您的代码
  double n ; cin>>n;
  double ok = 0 ; double good = 0;
  for(int i = 0 ; i < n ; i++){
    int temp;cin>>temp;
    if(temp>=60) ok++;
    if(temp>=85) good++;
  } 
  cout<<int((ok/n)*100+0.5)<<"%"<<endl;
  cout<<int((good/n)*100+0.5)<<"%"<<endl;
  return 0;
}