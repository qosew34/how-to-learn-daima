
//看了题解，用贪心？
//先杀ci>0再杀<0
//懒得再写了，就这样吧


/*#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(vector<int>& swords, vector<pair<int, int>>& monsters, int killed) {
    int max_kill = killed;
    // 枚举每只没死的怪物
    for (int i = 0; i < monsters.size(); ++i) {
        int hp = monsters[i].first;
        int drop = monsters[i].second;
        // 枚举所有剑
        for (int j = 0; j < swords.size(); ++j) {
            if (swords[j] >= hp) {
                // 状态备份
                vector<int> new_swords = swords;
                vector<pair<int, int>> new_monsters = monsters;
                // 消耗一把剑，击杀怪物
                new_swords.erase(new_swords.begin() + j);
                new_monsters.erase(new_monsters.begin() + i);
                if (drop > 0) {
                    new_swords.push_back(max(swords[j], drop));
                }
                max_kill = max(max_kill, dfs(new_swords, new_monsters, killed + 1));
            }
        }
    }
    return max_kill;
}

int main() {
    int t;cin>>t;
    for(int i=0;i<t;i++){
    int n, m;
    cin >> n >> m;
    vector<int> swords(n);
    for (int i = 0; i < n; ++i) cin >> swords[i];
    vector<pair<int, int>> monsters(m); // {hp, drop}
    for (int i = 0; i < m; ++i) cin >> monsters[i].first;
    for (int i = 0; i < m; ++i) cin >> monsters[i].second;
    cout << dfs(swords, monsters, 0) << endl;
    }
}




























/*#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    for(int z = 0;z<t;z++){
        int m,n;cin>>n>>m;
        int kill=0;
        vector<pair<int,int>>monster(m,{0,0});vector<int>sword;
        for(int i=0;i<n;i++){
            int temp;cin>>temp;
            sword.push_back(temp);
        }
        for(int i=0;i<m;i++){
            int temp;cin>>temp;
            monster[i].first=temp;
        }
        for(int i=0;i<m;i++){
            int temp;cin>>temp;
            monster[i].second=temp;
        }
    
        multiset<pair<int,int>> monsters(monster.begin(),monster.end());
        multiset<int> swords(sword.begin(), sword.end());
        //给岁月以文明，而不是给文明以岁月
        //说白了，给剑找熊（刚看日本新闻），而不是给熊找剑
        for (auto x : sword) {
            auto it = monsters.lower_bound({x-1,-2147483555});//找到大于x的数
            if (it == monsters.begin()) continue; //这剑也太废物了
            int m = 0 ;auto location =it;
            for(auto t = monsters.begin();t!=it;++t){
                int sss=t->second;
                if(sss>m){
                    location=t;
                    m=sss;
                }
            }
            monsters.erase(location);
            kill++;
            if(m>0) swords.insert(m);
        }
    cout<<kill<<endl;
    }
}
/*    int low=0,high=m;
    for(int i=0;i<n;i++){
        high=int(sword.size());low=max(low-1,0);
        while(low<high){
            int mid=(low+high)/2;
            if(sword[mid]>monster[mid].first) low=mid+1;
            else high=mid-1;
        }//定位能砍死哪个
        if(mid>0){
            sword.erase(sword[mid]);
            kill++;
            int num=-1;int attack=0;
            for(int i=0;i<low;i++){
                if(monster[i].second<0) continue;
                if(monster[i].second>attack){
                    num=i;attack=monster[i].second;
                }
            }
            if(num!=-1) sword.push_back(attack);
        }
        
    }
        错的*/