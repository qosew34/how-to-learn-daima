/*#include <bits/stdc++.h>
using namespace std;

int main(){
int n;
string inner;
cin>>n;
getline(cin,inner);
vector<string> true_inner;
for (int i=0;i<3*n;i++){
    if(i%3==0){
        if(typeid(inner[i])==typeid(int)){
            true_inner.push_back(true_inner[i-3]);
        i++;
        }
        else{
            true_inner.push_back(to_string(inner[i]));
        }
    }
    else{
        true_inner.push_back(to_string(inner[i]));
    }

}
}
这关输入类型纯傻逼
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string previous_operation;
    
}