/*任何一个正整数都可以用 2 的幂次方表示。例如 137=27+23+20。

同时约定次方用括号来表示，即 ab 可表示为 a(b)。

由此可知，137 可表示为 2(7)+2(3)+2(0)。

进一步：

7=22+2+20 ( 21 用 2 表示)，并且 3=2+20。

所以最后 137 可表示为 2(2(2)+2+2(0))+2(2+2(0))+2(0)。

又如 1315=210+28+25+2+1。

所以 1315 最后可表示为 2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2(0))+2+2(0)。*/

#include <bits/stdc++.h>
using namespace std;
int main(){
vector<int> ejz;
int n;
cin>>n;
int i;
while(n!=0){/*原来写成n=!0*/
i=n%2;
n=n/2;
ejz.push_back(i);
}
/*先转化为倒着的二进制存到数组里*/
int j,k,m;
m=0;
/*j是主要的，k是次要的,m存)*/
bool l=true;/*存+*/
for (j=ejz.size()-1;j>=0;j--){
if (ejz[j]==1){
    
    if(!l){
        cout<<"+";
    }
    else{l=false;}
    cout<<"2(";
k=j+1;
m++;
while(k!=0){
if(k==1){
cout<<"2(0";
m++;
}
else if(k%2==1){
cout<<"2(";
m++;
}
k=k/2;
}
while(m!=0){
cout<<")";
m--;
}
}
}
return 0;
}

/*#include <bits/stdc++.h>
using namespace std;

string express(int k) {
    if (k == 0) return "0";
    vector<string> terms;
    int p = 0;
    int temp = k;
    while (temp > 0) {
        if (temp & 1) {
            string term;
            if (p == 0) {
                term = "2(0)";
            } else if (p == 1) {
                term = "2";
            } else {
                term = "2(" + express(p) + ")";
            }
            terms.push_back(term);
        }
        temp >>= 1;
        p++;
    }
    // 从高位到低位构建字符串
    string res;
    bool first = true;
    for (int i = terms.size() - 1; i >= 0; i--) {
        if (!first) {
            res += "+";
        }
        res += terms[i];
        first = false;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << "0" << endl;
    } else {
        cout << express(n) << endl;
    }
    return 0;
}*/