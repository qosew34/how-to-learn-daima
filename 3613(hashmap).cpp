#include <bits/stdc++.h>
using namespace std;
/*
int main(){
    int n,q;
    cin>>n>>q;
    vector<pair<int,int>> store(n+1);//位置代表柜子
    //pairfirst代表格子 pair second代表物品
    int temp;
    for(int i=0;i<q;i++){
        cin>>temp;
        if(temp==1){
            int shelf,ge,wu;
            cin>>shelf>>ge>>wu;
            if(wu==0){
                store[shelf]={ge,0};
            }
            else{
                store[shelf]= {ge,wu};
            }
        }
        else if(temp==2){
            int shelf,ge;
            cin>>shelf>>ge;
            int wu=store[shelf].second;
            cout<<wu<<endl;
        }

    }
}*/
int main(){
    int n,q;
    cin>>n>>q;
    vector<unordered_map<int,int>> store(n+1);
    for(int i = 0; i < q; ++i){
        int type;
        cin>>type;
        if(type == 1){
            int shelf,ge,k;
            cin>>shelf>>ge>>k;
            if(k==0){
                auto it=store[shelf].find(ge);
                if(it!=store [shelf].end())store [shelf].erase(it);
            }
            else {
                store[shelf][ge]=k;
            }
        }else if(type == 2){
            int shelf,ge;
            cin>>shelf>>ge;
            auto it=store [shelf].find(ge);
            if(it==store[shelf].end()) cout<<'0'<<'\n';
            else cout<<it->second<<'\n';
        }
    }
}
/*insert / emplace：插入元素
operator[]：访问或插入（若键不存在会构造默认值）
at(key)：不插入，键不存在抛出异常
find(key)：返回迭代器或 end()
erase(key / iterator)：删除
count(key)：是否存在（0 或 1）
size(), clear()*/