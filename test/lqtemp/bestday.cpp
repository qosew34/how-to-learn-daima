#include <bits/stdc++.h>
using namespace std;

int sum(int num){
    int ans = 0;
    while(num>0){
        ans+=num%10;
        num/=10;
    }
    return ans;
}
int main(){
    int ans = 0;
    vector<int> month = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    for(int i = 2001 ; i < 2021 ; i++){
        for(int j = 1 ; j <= 12 ; j++ ){
            int days = month[j];
            if(i%4==0&&j==2) days++;
            for(int k = 1 ; k <= days ; k++){
                int total = sum(k)+sum(j)+sum(i);
                int temp = sqrt(total);
                if(total == temp*temp) ans++;
            }
        }
    }
    cout<<ans<<endl;
}