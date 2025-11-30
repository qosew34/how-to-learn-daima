#include <bits/stdc++.h>
using namespace std;
int main(){
    //bfs咯
    vector<bool> isPrime(10001, true);
    isPrime[0] = isPrime[1] = false;  
    for (int i = 2; i * i <= 10000; ++i){
        if (isPrime[i]) {
            for (int j = i * i; j <= 10000; j += i) {
                isPrime[j]=false;
            }
        }
    }
    int t;cin>>t;for(int zzz = 0 ; zzz < t ; zzz++){
    int ai,bi;
    cin>>ai>>bi;
    string a = to_string(ai);
    string b = to_string(bi);
    while(a.size()<4) a.insert(0,"0");
    while(b.size()<4) b.insert(0,"0");
    if(a==b){
        cout<<0<<endl;continue;
    }
    vector<int> dis(10000,-1);
    queue<int> q;
    q.push(ai);
    dis[ai]=0;
    bool end = false;
    while(!q.empty()){
        int cur = q.front();q.pop();
        string s= to_string(cur);
        while (s.size() < 4) s.insert(s.begin(), '0');
        if(end)break;
        for(int i = 0 ; i < 4 ; i++){
            if(end) break;
            char temp = s[i];
            for(char d ='0';d<='9';d++){
                if(d==temp) continue;
                s[i]=d;
                int ttt=stoi(s);
                if(isPrime[ttt]&&dis[ttt]==-1){
                    dis[ttt]=dis[cur]+1;
                    if(ttt==bi){
                        cout<<dis[ttt]<<endl;
                        end = true;
                        break;
                    }
                    q.push(ttt);
                }
                s[i]=temp;
            }
        }
    }
    if(!end)cout<<-1<<endl;
}}