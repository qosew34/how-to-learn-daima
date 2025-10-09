#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> ch,all,rank;
    int a,b,c;
    for (int i=0;i<n;i++){
        cin>>a>>b>>c;
        ch.push_back(a);
        all.push_back(a+b+c);
        rank.push_back(i+1);
    }
    /*如rank[1]=7，那么rank[1]对应的all储存在all[7-1]处*/
    int temp=0;
    for(int k=0;k<n;k++){
        for(int j=0;j<n-1-k;j++){
            if(all[j]<all[j+1]){
                temp=rank[j];
                rank[j]=rank[j+1];
                rank[j+1]=temp;
                temp=all[j];
                all[j]=all[j+1];
                all[j+1]=temp;
                temp=ch[j];
                ch[j]=ch[j+1];
                ch[j+1]=temp;

            }
            else if(all[j]==all[j+1]){
                if(ch[j]<ch[j+1]){
                    temp=rank[j];
                    rank[j]=rank[j+1];
                    rank[j+1]=temp;
                    temp=all[j];
                    all[j]=all[j+1];
                    all[j+1]=temp;
                    temp=ch[j];
                    ch[j]=ch[j+1];
                    ch[j+1]=temp;

                }
            }
        }
    }
    for(int l=0;l<5;l++){
        cout<<rank[l]<<" "<<all[l]<<endl;
    }
    return 0;
}