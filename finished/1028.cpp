/*#include <bits/stdc++.h>
using namespace std;

void sc(int m,int &total){
    if(m==1){
        total+=2;
    }
    else{
    for (int i=m/2;i>0;i--){
        sc(i,total);
    }
}
}
int main(){
    int n;
    cin>>n;
    if (n==0){
        cout<<0<<endl;
        return 0;
    }
    int total=0;
    sc(n,total);
    cout<<total<<endl;
    return 0;
}
    第一版 太大的数会tle
#include <bits/stdc++.h>
using namespace std;

void sc(int n,int &total){
    if(n==2||n==3){
        total+=2;
    }
    
    else{
        int m=n/2;
        n-=2;
        sc(m,total);
        sc(n,total);
    }
}

int main(){
int n;
cin>>n;
if(n==1){cout<<1;return 0;}
int total=0;
sc(n,total);
cout<<total;
}好一点，但还是有一些tle*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int num[n+10]={0};
    num[0]=0;
    num[1]=1;
    num[2]=2;
    int i=3;
    while(num[n+9]==0){
        num[i]=num[i-2]+num[i/2];
        i++;
    }
    cout<<num[n]<<endl;
    return 0;

}