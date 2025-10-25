#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    for(int sb=0;sb<t;sb++){
        int a1,b1,a2,b2,a3,b3;
        cin>>a1>>b1>>a2>>b2>>a3>>b3;
        vector<pair<int,int>> r = {{a1,b1},{a2,b2},{a3,b3}};
        int s=2147483600;
        vector<int> p={0,1,2};
                for (int p0=0;p0<3;++p0) {
            for (int p1=0;p1<3;++p1) {
                if (p1==p0) continue;
                for (int p2=0;p2<3;++p2) {
                    if (p2== p0||p2==p1) continue;
                    int p[3]={p0,p1,p2};{
                    for(int mask=0;mask<8;++mask){
                        int w[3],h[3];//长宽
                        for(int i=0;i<3;i++){
                            int temp=p[i];
                            int chang,kuan;
                            auto [chang,kuan]=r[temp];
                            if(mask&(1<<i)) swap(chang,kuan);//第i位为1，旋转,1<<i代表生成第i为1的数，&表示都1则1
                            w[i]=chang;h[i]=kuan;
                }
                        s=min(s,(w[0]+w[1]+w[2])*max(h[0],max(h[1],h[2])));//全平
                        s=min(s,max(w[0],max(w[1],w[2]))*(h[0]+h[1]+h[2]));
                        s=min(s,max(w[0]+w[1],w[2])*(max(h[0],h[1])+h[2]));
                        s=min(s,(w[0]+max(w[1],w[2]))*max(h[0],h[1]+h[2]));
            }
        }
    }
}        
                    cout<<s<<endl;
}
}
}

/*    int a[3]={a1,a2,a3};
    int b[3]={b1,b2,b3};

  //  sort(a,a+3);sort(b,b+3);
    //int chang,kuan;
    //chang=max(a[0]+a[1],a[2]);
    //kuan=max(b[0]+b[1],b[2]);
    //cout<<chang*kuan<<endl;//用namespace的时候不能用long做变量
    //要么放第一个右边，要么放第一个上边，写四个for算了
    int mini=2147483600;
    //先按照高排序
    int temp=0;
    if(b[0]>b[1]){
        temp=b[0];b[0]=b[1];b[1]=temp;
        temp=a[0];a[0]=a[1];a[1]=temp;
    }
    if(b[1]>b[2]){
        temp=b[1];b[1]=b[2];b[2]=temp;
        temp=a[1];a[1]=a[2];a[2]=temp;
    }
    if(b[0]>b[1]){
        temp=b[0];b[0]=b[1];b[1]=temp;
        temp=a[0];a[0]=a[1];a[1]=temp;
    }
    if(a[2]>=a[1]){
        mini=min(mini,max(b[0]+b[1],b[2])*(a[1]+a[2]));
    }
    else{
        mini=min(mini,min(b[2]*(a[0]+a[1]+a[2]),(b[2]+b[1])*(max(a[0],a[1]+a[2]))));
    }
    cout<<mini;
}有点麻烦，再写一遍算了，原来逻辑有点错*/