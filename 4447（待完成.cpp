#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int min=2147483647;
    int max=0;
    int temp;
    const int OFFSET = 1000000000; //声明常量不可改
    int people[2 * OFFSET + 100] = {};
    for(int i=0;i<n;i++){
        cin>>temp;
        temp+=OFFSET;
        if(temp<min)temp=min;
        if(temp>max)temp=max;
        people[temp]++;
    }
    //我们不关心多少是多少，有多少才重要
    int pre=people[min];int done=0;int temp_long=1;int longest=10000;
    for(int i=min+1;i<=max;i++){
        
    }
}