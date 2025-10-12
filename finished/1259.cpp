#include <bits/stdc++.h>
using namespace std;

int a,b,c;//a是o,b标记ox数 
void cir1(int &a,int &b){
for(int i=0;i<a;i++){
    cout<<'o';
}
for(int i=0;i<a;i++){
    cout<<'*';
} 
cout<<'-'<<'-';
for(int i=0;i<b;i++){
    cout<<"o*";
}
cout<<endl;
a--;b++;
for(int i=0;i<a;i++){
    cout<<'o';
}
cout<<'-'<<'-';
for(int i=0;i<a;i++){
    cout<<'*';
} 
for(int i=0;i<b;i++){
    cout<<"o*";
}
cout<<endl;
}
void cir2(int n){
    cout<<"ooo*o**--*";
    for(int i=0;i<n-4;i++){
        cout<<"o*";
    }
    cout<<endl<<"o--*o**oo*";
        for(int i=0;i<n-4;i++){
        cout<<"o*";
    }
    cout<<endl<<"o*o*o*--o*";
        for(int i=0;i<n-4;i++){
        cout<<"o*";
    }
    cout<<endl<<"--o*o*o*o*";
        for(int i=0;i<n-4;i++){
        cout<<"o*";
    }
}

int main(){
    ios::sync_with_stdio(false);  // 关闭 cout 与 printf 同步
    cin.tie(NULL);                // 解绑 cin 和 cout
    int n;
    cin>>n;
    a=n;b=0;
    for(int i=0;i<n-3;i++){
        cir1(a,b);
    }
    cir2(n);
}