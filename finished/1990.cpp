#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> cover_wall={0,1,2,5};
    int i=4;
    while(i<n+2){
        cover_wall.push_back((2*cover_wall[i-1]+cover_wall[i-3])%10000);
        i++;
    }
    cout<<cover_wall[n];
}