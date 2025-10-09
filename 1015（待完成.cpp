/*用str，重写！*/
#include <bits/stdc++.h>
using namespace std;

int main(){
string m;
int n;
cin>>n>>m;

}
















/*#include <bits/stdc++.h>
using namespace std;

void hwjf(vector<int> &x,int n){
vector<int> y;
y=x;

if(y[0]+y[x.size()-1]>=n){
    y.insert(y.begin(),1);
    y[1]=y[0]+y[x.size()-1]-n;
    for(int i=2;i<y.size();i++){
        if(y[i]+x[x.size()-i]>n){
            y[i-1]+=1;
            y[i]=y[i]+x[x.size()-i]-n;
        }
        else{
            y[i]=y[i]+x[x.size()-i];
        }
    }
}
else{
    for(int i=0;i<y.size();i++){
        if(y[i]+x[x.size()-i-1]>n){
            y[i-1]+=1;
            y[i]=y[i]+x[x.size()-1-i]-n;
        }
        else{
            y[i]=y[i]+x[x.size()-i-1];
        }
    }
}
x=y;
}
进位搞反了

bool pd(const vector<int>& x) {
    int a = x.size();
    for (int i = 0; i < a / 2; i++) {
        if (x[i] != x[a - 1 - i]) {
            return false;
        }
    }
    return true;
}


int main(){
int n,ans; long long m;longlong太短了
cin>>n>>m;
vector<int> num;
while (m!=0){
    num.insert(num.begin(),m%n);正过来的注意是n进制，不能/10%10
    m/=n;
}
int sb=0;
ans=0;
while (ans<=30&&sb==0){
    if (pd(num)){
    
    sb++;
    }
    else{
        hwjf(num,n);
        ans++;
    }
}
if (ans>30){
    cout<<"Impossible!"<<endl;
}
else{
    cout<<ans<<endl;
}
return 0;
}
#include <bits/stdc++.h>
using namespace std;

bool is_palindrome(const vector<int>& v) {
    size_t s = v.size();
    for (size_t i = 0; i < s / 2; ++i) {
        if (v[i] != v[s - 1 - i]) {
            return false;
        }
    }
    return true;
}

void add_reverse(vector<int>& v, int base) {
    size_t s = v.size();
    vector<int> res(s + 1, 0);
    int carry = 0;
    for (size_t i = 0; i < s; ++i) {
        int r = v[s - 1 - i];
        int sum_val = v[i] + r + carry;
        res[i] = sum_val % base;
        carry = sum_val / base;
    }
    if (carry) {
        res[s] = carry;
    } else {
        res.resize(s);
    }
    while (res.size() > 1 && res.back() == 0) {
        res.pop_back();
    }
    v = std::move(res);
}

int main() {
    int base;
    string num_str;
    cin >> base >> num_str;
    vector<int> digits;
    for (int i = num_str.size() - 1; i >= 0; --i) {
        char c = toupper(num_str[i]);
        int val;
        if (isdigit(c)) {
            val = c - '0';
        } else if (c >= 'A' && c <= 'F') {
            val = 10 + (c - 'A');
        } else {
            // Invalid char, assume valid input
            val = 0;
            continue;
        }
        if (val >= base) {
            // Invalid digit
            cout << "Impossible!" << endl;
            return 0;
        }
        digits.push_back(val);
    }
    if (digits.empty()) {
        digits = {0};
    }
    int steps = 0;
    while (steps <= 30) {
        if (is_palindrome(digits)) {
            cout << steps << endl;
            return 0;
        }
        add_reverse(digits, base);
        ++steps;
    }
    cout << "Impossible!" << endl;
    return 0;
}*/