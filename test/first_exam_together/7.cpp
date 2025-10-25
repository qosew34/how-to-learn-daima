#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;long long k;
    scanf("%d" "%lld",&n,&k);
    int skill[n+2];
    int max_skill=0;
    for(int i=0;i<n;i++){
        scanf("%d",&skill[i]);
        if(skill[i]>max_skill){
            max_skill=skill[i];
        }
    }
    if(k>=n){
        cout<<max_skill;return 0;
    }

    queue<int> q;
    for(int i=1;i<n;i++){
        q.push(i);
    }
    int max_sc=0;
    int local=0;
    while(max_sc!=k){
        int challenger=q.front();q.pop();
        if(skill[local]>skill[challenger]){
            max_sc++;
            q.push(challenger);
        }
        else{
            max_sc=1;
            q.push(local);
            local=challenger;
        }
        
    }
    printf("%d\n",skill[local]);
}