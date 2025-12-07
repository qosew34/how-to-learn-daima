#include <bits/stdc++.h>

int main(){
    int n; std :: cin>>n;
    std :: set<int> storage;//不会仓库英文
    for(int i = 0 ; i < n ; i++){
        int a,b;
        std :: cin >> a >> b;
        if(a==1){
            if(storage.find(b)!=storage.end()){
                std :: cout<<"Already Exist"<<std::endl;
                continue;
            }
            storage.insert(b);
        }
        else if(a==2){
            if(storage.empty()){
                std :: cout<<"Empty" << std::endl;
            }
            else if(storage.find(b)!=storage.end()){
                std :: cout << b << std :: endl;
                storage.erase(b);
                continue;
            }
            auto it_succ = storage.lower_bound(b);
            bool has_succ = (it_succ != storage.end());
            bool has_pred = (it_succ != storage.begin());
            int pred_val = 0, succ_val = 0;
            if(has_pred){
                auto it_pred = std::prev(it_succ);
                pred_val = *it_pred;
            }
            if(has_succ){
                succ_val = *it_succ;
            }
            if(has_pred && has_succ){
                if((long long)succ_val - b < (long long)b - pred_val){
                    std::cout << succ_val << '\n';
                    storage.erase(it_succ);
                }else{
                    storage.erase(std::prev(it_succ));
                    std::cout << pred_val << '\n';
                }
            }else if(has_pred){
                storage.erase(std::prev(it_succ));
                std::cout << pred_val << '\n';
            }else if(has_succ){
                storage.erase(it_succ);
                std::cout << succ_val << '\n';
            }
            
            
        }
    }
}