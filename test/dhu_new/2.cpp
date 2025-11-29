#include <bits/stdc++.h>
using namespace std;

bool trianglefirsthua(vector<double>cur){
    if(cur.size()==1){
        if(cur[0]>=abs(24-1e-6)&&cur[0]<abs(24+1e-6)) return true;
        return false;
    }
    for(int i = 0 ; i < cur.size();i++){
        for(int j = i+1 ; j < cur.size() ; j++){
            vector<double> t;
            double a=cur[i];
            double b=cur[j];
            for(int k = 0 ; k < cur.size() ; k++){
                if(k!=i&&k!=j) t.push_back(cur[k]);
            }
            t.push_back(a+b);
            if(trianglefirsthua(t)) return true;
            t.pop_back();
            t.push_back(a-b);
            if(trianglefirsthua(t)) return true;
            t.pop_back();
            t.push_back(b-a);
            if(trianglefirsthua(t)) return true;
            t.pop_back();
            if(b!=0){
            t.push_back(a/b);
            if(trianglefirsthua(t)) return true;
            t.pop_back();
            }
            if(a!=0){
            t.push_back(b/a);
            if(trianglefirsthua(t)) return true;
            t.pop_back();
            }
            t.push_back(a*b);
            if(trianglefirsthua(t)) return true;
            t.pop_back();
        }
    }
    return false;
}
int main(){
    int n ;
    cin>>n;
    for(int i = 0 ; i < n ; i++){
        vector<double> c;
        for(int j = 0 ; j < 4 ; j++){
            double temp;cin>>temp;c.push_back(temp);
        }
        if(trianglefirsthua(c)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}