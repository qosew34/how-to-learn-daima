#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> yu(n,vector<int>(m));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            int temp;cin>>temp;yu[i][j]=temp;
        }
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            int temp;cin>>temp;yu[i][j]=yu[i][j]^temp;
        }
    }
    
    vector<int> a={0,0,0,-1,1},b={1,-1,0,0,0};
    vector<pair<int,int>> ans;
    int all = 0;
    for(int i = 0 ; i < n-1 ; i++){
        for(int j = 0 ; j < n ;j++){
            if(yu[i][j]==1){
        ans.push_back({i+1,j});
        all++;
    
        for(int k = 0 ; k < 5 ; k++){
            int p = i+1+a[k],q = j+b[k];
            if(p>=0&&p<n&&q>=0&&q<m){
            yu[p][q]++;yu[p][q]%=2;
        }
    }}}}
    cout<<all<<endl;
    for(auto a:ans){
        cout<<a.first+1<<" "<<a.second+1<<endl;
    }
}

