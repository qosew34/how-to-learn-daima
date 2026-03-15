#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> count = {13,1,2,3,5,4,4,2,2,2};
    vector<int> month = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int ans = 10;
    for(int i = 2000 ; i <= 2024 ; i++){
        for(int m = 1 ; m <= 12 ; m++){
            if(i==2024&&m>=4) break;
            int days = month[m];
            if(i%4==0&&m==2) days++; 
            for(int j = 1 ; j <= days ; j++){
                int c = 0;
                int cur = i*10000+m*100+j;
                while(cur>0){
                    c+=count[cur%10];
                    cur/=10;
                }
                if(c>50) ans++;
            }
        }
    }
    cout<<ans<<endl;
}