#include <bits/stdc++.h>

int main(){
int q,n,temp;
std :: cin >> q ;
for(int i = 0 ; i < q ; i ++ ){
    std :: cin >> n;
    std :: vector<int> pushed,poped;
    for(int j = 0 ; j < n ; j++){
        std :: cin >> temp ;
        pushed.push_back(temp);
    }
    for(int j = 0 ; j < n ; j++){
        std :: cin >> temp ;
        poped.push_back(temp);
    }
    std :: stack<int> simulate;
    int loc = 0;
    for(int k : pushed){
        simulate.push(k);
        while(!simulate.empty()&&loc<n&&simulate.top()==poped[loc]){
            simulate.pop();
            loc++;}
    }
    if(loc==n) std::cout<<"Yes"<<std::endl;
    else std::cout<<"No"<<std::endl;
}



}