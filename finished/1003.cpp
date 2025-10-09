/*题目描述

为了准备一个独特的颁奖典礼，组织者在会场的一片矩形区域（可看做是平面直角坐标系的第一象限）铺上一些矩形地毯。一共有 n 张地毯，编号从 1 到 n。现在将这些地毯按照编号从小到大的顺序平行于坐标轴先后铺设，后铺的地毯覆盖在前面已经铺好的地毯之上。

地毯铺设完成后，组织者想知道覆盖地面某个点的最上面的那张地毯的编号。注意：在矩形地毯边界和四个顶点上的点也算被地毯覆盖。
输入格式

输入共 n+2 行。

第一行，一个整数 n，表示总共有 n 张地毯。

接下来的 n 行中，第 i+1 行表示编号 i 的地毯的信息，包含四个整数 a,b,g,k，每两个整数之间用一个空格隔开，分别表示铺设地毯的左下角的坐标 (a,b) 以及地毯在 x 轴和 y 轴方向的长度。

第 n+2 行包含两个整数 x 和 y，表示所求的地面的点的坐标 (x,y)。
输出格式

输出共 1 行，一个整数，表示所求的地毯的编号；若此处没有被地毯覆盖则输出 -1。*/
/*
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dt(100000, vector<int>(100000, 0));
这样做符合题意，但会炸内存 

int main(){
int n;
    cin>>n;
vector<vector<int>> dj(n, vector<int>(4, 0)); 
for (int k=0;k<n;k++) {
    for (int i=0;i<4;i++) {
        cin>>dj[k][i];
}
}
    int maxX = 0, maxY = 0;
    for (int k = 0; k < n; k++) {
        maxX = max(maxX, dj[k][0] + dj[k][2]);
        maxY = max(maxY, dj[k][1] + dj[k][3]);
    }

    vector<vector<int>> dt(maxX + 1, vector<int>(maxY + 1, 0));
for (int j=0;j<n;j++){
        for (int h=dj[j][0];h<dj[j][0]+dj[j][2];h++){
            for (int g=dj[j][1];g<dj[j][1]+dj[j][3];g++){
                dt[h][g]+=pow(2,j);
            }
        }
    }

int x,y;
    cin>>x>>y;
if (dt[x][y]!=0){
cout<<dt[x][y]<<endl;
}
else{
    cout<<(int)log2(dt[x][y]);
}
return 0;
}
这样会炸内存，册那
正确做法：倒着找
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
int n;
    cin>>n;
vector<vector<int>> dj(n, vector<int>(4, 0)); 
for (int k=0;k<n;k++) {
    for (int i=0;i<4;i++) {
        cin>>dj[k][i];
}
}
int x,y,z;
cin>>x>>y;
z=0;
for (int j=n-1;j>=0;j--){
   
    if(z!=0){
        return 0;
    }
    else{
        if (dj[j][0]<=x&&x<=dj[j][0]+dj[j][2]&&dj[j][1]<=y&&y<=dj[j][1]+dj[j][3]){
            cout<<j+1;
            z+=1;
        }
    }
    
}
return 0;
}
