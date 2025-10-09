#include <bits/stdc++.h>
using namespace std;
int main(){
long long a,n,b,x,y;
cin>>n;
a=1;
b=1;
while(n>a){
b++;
a=(b*(b+1))/2;
} 
x=b-a+n;
y=a+1-n;
if (b%2==0){
cout<<x<<"/"<<y<<endl;
}
else{
cout<<y<<"/"<<x<<endl;
}
return 0;
}
/*#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long b = 1;
    long long a = 1;
    while (n > a) {
        b++;
        a = b * (b + 1) / 2;
    }
    long long prev = a - b;
    long long pos = n - prev;
    long long num, den;
    if (b % 2 == 0) {
        num = pos;
        den = b + 1 - pos;
    } else {
        num = b + 1 - pos;
        den = pos;
    }
    cout << num << "/" << den << endl;
    return 0;
}*/