#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    int  chexiang[N]={0};
    int temp;
    for(int i=0;i<N;i++){
        cin>>temp;
        chexiang[i]=temp;
    }
    int total=0;
    for(int j=0;j<N;j++){
        for(int k=0;k<N-1-j;k++){
            if(chexiang[k]>chexiang[k+1]){
                temp=chexiang[k];
                chexiang[k]=chexiang[k+1];
                chexiang[k+1]=temp;
                total+=1;
            }
        }
    }
    cout<<total<<endl;return 0;
}
