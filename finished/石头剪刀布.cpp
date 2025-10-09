/*大家应该都会玩“锤子剪刀布”的游戏：两人同时给出手势，胜负规则如图所示：

现要求你编写一个稳赢不输的程序，根据对方的出招，给出对应的赢招。但是！为了不让对方输得太惨，你需要每隔K次就让一个平局。
输入格式：

输入首先在第一行给出正整数K（≤10），即平局间隔的次数。随后每行给出对方的一次出招：ChuiZi代表“锤子”、JianDao代表“剪刀”、Bu代表“布”。End代表输入结束，这一行不要作为出招处理。
输出格式：*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<string> arr;
    int n,a;
    cin>>n;
    string temp;
    while(cin>>temp&&temp!="End"){
    arr.push_back(temp);
    }
    int i;
    string ans[3];
    ans[0]="ChuiZi";
    ans[1]="JianDao";
    ans[2]="Bu";
    for (i=0;i<arr.size();i++){
    if (i+1%n+1==0){
        cout<<arr[i]<<endl;
    }
    else{
        if (arr[i]==ans[0]){
        cout<<ans[2]<<endl;
        }
        if (arr[i]==ans[1]){
        cout<<ans[0]<<endl;
        }
        if (arr[i]==ans[2]){
        cout<<ans[1]<<endl;
        }
    }
    }
}