#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p;
    DSU(int n=0){ p.resize(n); iota(p.begin(), p.end(), 0); }
    int find(int x){ return p[x]==x? x : p[x]=find(p[x]); }
    void unite(int x,int y){
        x = find(x); y = find(y);
        if(x==y) return;
        p[y]=x;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long a,b;
    int p;
    if(!(cin>>a>>b>>p)) return 0;
    if(a > b) swap(a,b);
    long long n = b - a + 1;
    DSU dsu((int)n);

    int B = (int) b;
    vector<char> is_prime(B+1, true);
    if(B >= 0) is_prime[0] = false;
    if(B >= 1) is_prime[1] = false;
    for(int i = 2; (long long)i * i <= B; ++i){
        if(is_prime[i]){
            for(long long j = 1LL * i * i; j <= B; j += i) is_prime[(int)j] = false;
        }
    }

    int start = max(p, 2);
    for(int pr = start; pr <= B; ++pr){
        if(!is_prime[pr]) continue;
        long long first = ((a + pr - 1) / pr) * (long long)pr;
        if(first > b) continue;
        int id_first = (int)(first - a);
        for(long long x = first + pr; x <= b; x += pr){
            int id = (int)(x - a);
            dsu.unite(id_first, id);
        }
    }

    unordered_set<int> roots;
    roots.reserve((size_t)min(n, (long long)100000));
    for(long long x = 0; x < n; ++x){
        roots.insert(dsu.find((int)x));
    }
    cout << roots.size() << '\n';
    return 0;
}
/*
用压缩索引 id = x - a 避免 parent 越界或未初始化问题。
修正并简化了素数筛（i*i <= b）并在筛后对每个 >= p 的素数计算区间内首个倍数，然后把这个首个倍数与后续倍数 union。
用 unordered_set 统计不同的根，逻辑清晰且边界正确（包含 a 和 b）。
很显然，是邻接表
//然后呢？
//先根据单一质数建立
#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
int find(int x){
    if(parent[x]!=x) parent[x]=find(parent[x]);
    return parent[x];
}
void unite(int x,int y){
    int fx = find(x);
    int fy = find(y);
    if(fx==fy) return;
    parent[fy]=fx;
}
bool same(int x,int y){
    return find(x)==find(y);
}
int main(){
    int a,b,p;cin>>a>>b>>p;
    //第一步，筛
    parent.resize(b+1,0);
    for(int i = a ; i <= b ; i++) parent[i]=i;
    unordered_map<int,vector<int>> pmap; 
    vector<bool> prime(b+1,true);
    prime[0]=prime[1]=false;
    for(int i = 2 ; i * i <= b ; i++){
        if(prime[i]){
            for(int j = i * i ; j <= b+1 ; j+=i){
                if(i>=p) pmap[i].push_back(j);
                prime[j] = false;
            } 
        }
    }
    vector<int> primes;
    for(int i = max(p,0) ; i <= b ; i++ ){
        if(prime[i]) primes.push_back(i);
    }
    //第二步，邻接表
    for(int i = 0 ; i < primes.size() ; i++){
        auto v = pmap[primes[i]];
        if(v.size()>1){
            for(int i = 1 ; i < v.size() ; i++){
                unite(v[0],v[i]);
            }
        }
    }
    vector<int> pre;
    for(int i = a; i < b ;i++ ){
        int temp = find(a);
        if(find(pre.begin(),pre.end(),temp)!=pre.end()) pre.push_back(temp);
    }
    cout<<pre.size();
}

*/