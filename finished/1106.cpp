#include <bits/stdc++.h>
using namespace std;

int main() {
    string num;
    int n;
    getline(cin, num);
    vector<int> bignum;
    for (int i = 0; i < num.size(); i++) {
        bignum.push_back(num[i]);
    }
    cin >> n;
    int k0 = 0;
    int removals = min(n, (int)bignum.size()); 
    for (int j = 0; j < removals; j++) {
        bool removed = false;
        for (int k = max(k0 - 1, 0); k < (int)bignum.size() - 1; k++) {
            if (bignum[k] > bignum[k + 1]) {
                bignum.erase(bignum.begin() + k);
                k0 = k;  // 更新 k0 为移除位置
                removed = true;
                break;
            }
        }
        if (!removed && !bignum.empty()) {
            // 未找到降序对，从末尾移除
            bignum.pop_back();
            k0 = bignum.size();
        }
    }
    for (int l = 0; l < (int)bignum.size(); l++) {
        
            cout << (char)bignum[l];
        
    }
    return 0;
}
/*#include <bits/stdc++.h>

int n;
char a[350];
int b[350];
int len=0;
bool flg=0;

void solve(int k1,int left){
    if(!k1){
        if(!flg)std::cout<<0;
        return;
    }
    int min_=10,pos=-1;
    // if(k1 == len-n && k1 != 1){
    //     for(int i=left;i<=len-k1;i++){
    //         if(b[i]<min_ && b[i] != 0){
    //             min_ = b[i];
    //             pos=i;
    //         }
    //     }
    //     if(min_==10){
    //         std::cout<<0;
    //         return;
    //     }
    //     flg = 1;
    //     std::cout<<min_;
    //     solve(k1-1,pos+1);
    //     return;
    // }
    for(int i=left;i<=len-k1;i++){
        if(b[i]<min_){
            min_ = b[i];
            pos=i;
        }
    }
    if(min_)flg=1;
    if(!flg){
        solve(k1-1,pos+1);
        return;
    }
    std::cout<<min_;
    solve(k1-1,pos+1);
    return;
}



int main(){
    std::cin>>a;//0 48
    std::cin>>n;
    for(int i=0;a[i] != '\0';i++,len++){
        b[i] = a[i]-48;
    }
    // for(int i = 0 ; i<len;i++){
    //     std::cout<<b[i];
    // }


    solve(len-n,0);

}还得看高中哥们*/