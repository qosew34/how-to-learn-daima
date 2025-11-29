#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> yu(n,vector<int>(m));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            int temp;cin>>temp;yu[i][j]=temp;
        }
    }
    vector<int> a={0,0,0,-1,1},b={1,-1,0,0,0};
    for(int i = 0 ; i<k ; i++){
        int x,y;
        cin>>x>>y;
        x--;y--;
        for(int k = 0 ; k < 5 ; k++){
            int p = x+a[k],q = y+b[k];
            if(p>=0&&p<n&&q>=0&&q<m){
                yu[p][q]++;yu[p][q]%=2;
            }
        }
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cout<<yu[i][j];
            if(j!=m-1) cout<<" ";
        }
        cout<<endl;
    }
}