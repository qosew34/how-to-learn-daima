#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    for(int i = 0 ; i < t ; i++){
        long long a=0,c=0,m=0,ac=0,cm=0,ans=0;
        string s;cin>>s;
        long long mod = 1e9+7;
        for(int j = 0; j< s.size() ; j++){
            if(s[j]=='a'){
                a++;
                ans+=cm;
                ac+=c;
                a%=mod;ac%=mod;
            }
            if(s[j]=='c'){
                c++;
                cm+=m;
                c%=mod;cm%=mod;
            }
            if(s[j]=='m'){
                m++;
            }
            if(s[j]=='A'){
                a++;a%=mod;
            }
            if(s[j]=='C'){
                ac+=a;ac%=mod;
                c++;c%=mod;
            }
            if(s[j]=='M'){
                ans+=ac;
                cm+=c;cm%=mod;
                m++;m%=mod;
            }
            ans%=mod;
            cout<<ans<<" ";
        }
        cout<<endl;
    }
}