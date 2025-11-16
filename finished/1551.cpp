#include <bits/stdc++.h>
using std::vector;
vector<int> parent;
vector<int> rank;
int find(int x){
    if(parent[x]!=x){
        parent[x]=find(parent[x]);
    }
    return parent[x];
}

bool same(int x,int y){
    if(find(x)==find(y)) return true;
    return false;
}

void unite(int x,int y){
    int fx = find(x);
    int fy = find(y);
    if(fx==fy) return;
    if(rank[fx]<rank[fy]){
        parent[fx]=fy;
    }
    else if(rank[fx]>rank[fy]){
        parent[fy]=fx;
    }
    else{
        parent[fy]=fx;
        rank[fx]++;
    }
}

int main(){
    int n,m,p;
    std :: cin >> n >> m >> p;
    parent.resize(n+1);
    rank.resize(n+1,0);
    for (int i = 1; i <= n; ++i) {
        parent[i] = i; // 初始时每个节点自成一个集合
    }
    for(int i = 0 ; i < m ; i++){
        int a , b;
        std :: cin >> a >> b;
        unite(a,b);
    }
    for(int i = 0 ; i < p ; i++){
        int a , b;
        std :: cin>>a>>b;
        if(same(a,b)) std::cout<<"Yes"<<std::endl;
        else std::cout<<"No"<<std::endl;

    }
}