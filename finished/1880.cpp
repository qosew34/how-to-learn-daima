#include <bits/stdc++.h>

int main(){
    int n ; std :: cin >> n;
    std :: priority_queue<int> p;
    std :: priority_queue<int,std :: vector<int>,std :: greater<int>> q;
    for(int i = 0 ; i < n ; i ++){
        int temp ; 
        std :: cin >> temp ;
        p.push(temp);
        q.push(temp);
    }
    int ans1=0,ans2=0;
    while(q.size()>1){
        int a = q.top();q.pop();
        int b = q.top();q.pop();
        q.push(a+b);
        ans1+=a;ans1+=b;
    }
    while(p.size()>1){
        int a = p.top();p.pop();
        int b = p.top();p.pop();
        p.push(a+b);
        ans2+=a;ans2+=b;
    }
    std :: cout<<ans1<<std :: endl<<ans2<<std :: endl;

}