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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    if(!(cin >> n)) return 0;
    string op = "";
    long long a, b;
    for(long long i = 0; i < n; ++i){
        string t1;
        if(!(cin >> t1)) break;
        if(t1 == "a" || t1 == "b" || t1 == "c"){
            op = t1;
            cin >> a >> b;
        } else {
            // t1 is the first operand (number), reuse previous op
            a = stoll(t1);
            cin >> b;
        }
        long long res;
        char sign;
        if(op == "a"){ res = a + b; sign = '+'; }
        else if(op == "b"){ res = a - b; sign = '-'; }
        else { res = a * b; sign = '*'; }

        string expr = to_string(a) + sign + to_string(b) + "=" + to_string(res);
        cout << expr << "\n" << expr.size() << "\n";
    }
    return 0;
}