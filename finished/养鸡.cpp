/*
问题描述

小蓝养了三只鸡，它们身上分别长了 xx、 yy、zz 根羽毛。小蓝想让这三只鸡身上的羽毛数量一样多，这样它们看起来才更默契。

小蓝可以进行以下两种操作：

    选择任意两只鸡，给它们各贴上一根羽毛。
    选择任意一只鸡，给它贴上两根羽毛。

请你计算，小蓝最少需要进行多少次操作，才能让三只鸡身上的羽毛数量相同。题目保证解必然存在。
输入格式

输入一行，包含三个整数 xx、yy 和 zz (1≤x,y,z≤105)(1≤x,y,z≤105)，分别表示三只鸡身上的羽毛数量。
输出格式

输出一个整数，表示达到三只鸡羽毛数量相等所需的最少操作次数。
样例输入

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
int a;
int b;
int c; 
int temp;
cin>>a>>b>>c;
if (a<b){
	a=temp;
	a=b;
	b=temp;
}
if(b<c){
	c=temp;
	c=b;
	b=temp;
}
if (a<b){
	a=temp;
	a=b;
	b=temp;
}

if ((a+c-b)%2==!0){
  cout<<int(a-b)/2+int(a-c)/2;
}
else{
  cout<<int(a-b)/2+int(a-c)/2+2;
}


}
//不知道哪错了，累了，交给ai
//数学部分还得多想想 
/*
int main() {
    long long x, y, z;
    cin >> x >> y >> z;
    long long s = x + y + z;
    long long m = max({x, y, z});
    long long t = m;
    if ((s % 2) != (m % 2)) t++; // 调整 t 使 3t ≡ s (mod 2)
    long long k = (3 * t - s) / 2; // 操作次数
    cout << k << endl;
    return 0;
*/
