#include <bits/stdc++.h>
using namespace std;

map<array<long long,3>, long long> mp;

long long w(long long a, long long b, long long c){
    array<long long,3> key{a,b,c};
    auto it = mp.find(key);
    if(it != mp.end()) return it->second;

    long long res;
    if(a<=0||b<=0||c<=0) res = 1;
    else if(a>20||b>20||c>20) res = w(20,20,20);
    else if(a<b&&b<c) res = w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
    else res = w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);

    mp.emplace(key, res);
    return res;
}

int main(){
    long long a,b,c;
    while(cin>>a>>b>>c){
        int ans = 0;
        if(a==-1&&b==-1&&c==-1) break;
        cout<<"w("<<a<<", "<<b<<", "<<c<<") = ";
        cout<<w(a,b,c)<<endl;
    }
}