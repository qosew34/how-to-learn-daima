#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin>>n;
    vector<vector<int>> maze(n,vector<int>(n));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            int temp;cin>>temp;maze[i][j]=temp;
        }
    }
    //注意是每列
    vector<int> start(n,n+1),end(n,-1);
    for(int i = 0 ; i < n ; i++){//列
        for(int j = 0 ; j < n ;j++){
            if(maze[j][i]==1){
                start[i]=min(j,start[i]);
                end[i]=max(j,end[i]);
            }
        }
    }
    //每列首尾全活
    int l = 0 ,r = n;
    while(r>l){
        int mid = (l+r+1)/2;
        bool can = false;
        for(int i = 0 ; i <= n-mid ; i++){//扫描每个出发点x，看y最大值
            int cur = 0 ;
            for(int j = 0; j < n;j++){
                if(start[j]<i||end[j]>i+mid-1){
                    cur++;
                    if(cur>=mid){
                        can = true;break;
                    }
                }
                else{
                    cur = 0;
                }
            }
        }
        if(can) l=mid;
        else r=mid-1;
    }
    cout<<l<<endl;
}