#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<int> point;
    for(int i = 0 ; i < n ; i++){
        int temp;cin>>temp;
        point.push_back(temp);
    }
    int all = point[point.size()-1]-point[0];
    if(all==0){
        cout<<0;
        return 0;
    }
    else{
        vector<int> dis;
        for(int i = 1 ; i < n ; i++){
            dis.push_back(point[i]-point[i-1]);
        }
        sort(dis.begin(),dis.end());
        for(int i = n-2 ; i >= 0 ; i--){
            cout<<all<<" ";
            all-=dis[i];
        }cout<<0;
    }
}