#include <bits/stdc++.h>
using namespace std;

int n;int total=0;//输出前三个
vector<int> queens;
void put(int line){
    if(line==n){
        total++;
        if(total<=3){
            for(int j=0;j<n;j++){
                cout<<queens[j]+1<<" ";
            }
            cout<<endl;
        }
    }
    for(int k=0;k<n;k++){
        bool canput=true;
        for(int l=0;l<line;l++){
            if(abs(queens[l]-k)==abs(l-line)||queens[l] == k){
                canput=false;
                break;
            }
        }
        if(canput){
            queens.push_back(k);
            put(line+1);
            queens.pop_back();
        }
    }
}


int main(){
    cin>>n;
    put (0);
    cout<<total;
}