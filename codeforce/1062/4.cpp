/*#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> num;
int prime(int limit){
    vector<bool>isprime(limit+1,true);
    isprime[0]=false;isprime[1]=false;
    for (int i = 2; i * i <= limit; ++i) {
        if (isprime[i]) {
            for (int j=i*i;j<=limit;j+=i) {
                isprime[j] = false;
            }
        }
    }
    for(int i=2;i<=limit;i++){
        if(isprime[i]){
            for(int j=0;j<n;j++){
                int temp=num[j]%i;
                if(temp==0) break;
            }
            return i;
        }
    }
    for(int i=int(sqrt(limit))+1;i<limit*limit;i++){
        if(isprime[i]) return i;
    }
    return -1;
}
int main(){
    int t;cin>>t;
    for(int j=0;j<t;j++){
        cin>>n;
        num.clear();
        int temp;
        for(int i=0;i<n;i++){
            cin>>temp;num.push_back(temp);
        }
        sort(num.begin(),num.end());
        if(n==1&&temp==1) {cout<<2<<endl;continue;}
        temp=prime(num[n-1]);
        cout<<temp<<endl;
    }
}*/



#include <bits/stdc++.h>
using namespace std;


int main(){
    int t;cin>>t;
    for(int k=0;k<t;k++){
        int n;cin>>n;
        vector<long long> num;long long temp;
        for(int j=0;j<n;j++){
            cin>>temp;
            num.push_back(temp);
        }
        bool is_put = false;
        if(n==1&&temp==1) {cout<<2<<endl; continue;}
        else {
            sort(num.begin(),num.end());
        long long g=num[0];
        for(int i=1;i<n;i++){
            g=gcd(g,num[i]);
        }
        for(long long j=2;j<=num[0]+1;j++){
            long long h=gcd(j,g);
            if(h==1){
                cout<<j<<endl;is_put = true;break;
            }
        }}
        if(!is_put) cout<<-1<<endl;
    }
}
