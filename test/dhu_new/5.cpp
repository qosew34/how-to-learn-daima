#include<bits/stdc++.h>
using namespace std;
long long mod = 998244353;
/*我草这是数学题
long long factorial(int cur){
    long long ans = 1;
    for(int i = 1 ; i <=cur ; i++){
        ans*=i;
    }
    return ans;
}
long long ca(int a , int b ){
    long long up = factorial(a)*factorial(b-a);
    long long down = factorial(b);
    return down/up;
}
int mod = 998244353;

long long ireallywannausepython(long long q ){
    q%=mod;
    long long res = 1%mod;
    long long n = mod-2;
    while(n>0){
        if(n&1) res = res*q%mod;
        n = q*q%mod;
        n>>1;
    }
    return res;
}
long long iwannausepython(long long p , long long q){
    return p*ireallywannausepython(q)%mod;
}*/

long long why_not_use_python(long long a){
    long long r = 1%mod;
    a%=mod;
    long long b = mod-2;
    while(b>0){
        if(b&1) r = r*a%mod;
        a = a*a%mod;
        b>>=1;
    }
    return r;
}
int main(){
    long long a,b,c;
    cin>>a>>b>>c;
    if(c>=a+b||a+b==0){
        cout<<0<<endl;
        return 0;
    }
    long long n = a+b;
    long long ans = (a%mod)*why_not_use_python(a+b)%mod;
    cout<<ans;
}