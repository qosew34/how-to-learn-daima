#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> fingers;
    vector<int> original_fingers;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        original_fingers.push_back(temp);
        fingers.push_back(temp);
    }
    int a,b,c,d;//a-24,b-6,c-2
    int i=5;
    sort(fingers[n-i],fingers[n-1]);
    while(fingers[n-i]==original_fingers[n-i]){
        i++;
        sort(fingers[n-i],fingers[n-1]);
    }
    if(i==5){
        a=n%24;b=(n-24*a)%6;c=(n-24*a-6*b)%2;d=n/2;
        
    }
}