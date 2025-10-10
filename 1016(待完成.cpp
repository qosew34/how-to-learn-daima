#include <bits/stdc++.h>
using namespace std;

int main(){
    double s,c,l,p0;
    int n;
    double total_money=0;
    double temp;
    cin>>s>>c>>l>>p0>>n;
    vector<double> dis;
    dis.push_back(0);
    vector<double> exp;
    exp.push_back(p0);
    for(int i=1;i<n;i++){
        cin>>temp;
        dis.push_back(temp);
    }
    dis.push_back(s);
    for(int i=1;i<n;i++){
        cin>>temp;
        exp.push_back(temp);
    }
    exp.push_back(5000);
    double add_oil=0;
    double current_oil=0;
    /*    double oil_max=0;
    for(int i=0;i<n;i++){
        if(i!=0){
            current_oil-=(dis[i]-dis[i-1])/l;
        }
        if(i==n-1){
            add_oil=(s-dis[i])/l;
            total_money+=add_oil*exp[i];
            current_oil+=add_oil;
            break;
        }
        //用油
        if(dis[i+1]-dis[i]>c*l){
            cout<<"No Solution";
            return 0;
        }
        //不可达
        oil_max=c;
        for(int j=i+1;j<n;j++){
            if(dis[j]<dis[i]+c*l){
                if(exp[j]<exp[i]){
                    oil_max=min(oil_max,(dis[j]-dis[i])/l);
                    
                }
            }
            else{
                break;
            }
        }//找到能苟到最近的比这家便宜的加油站

        if(oil_max==c){
            add_oil=c-current_oil; 
        }//没找到更便宜的加油站，加满
        else{
            add_oil=oil_max-current_oil;
        }
        total_money+=add_oil*exp[i];
        current_oil+=add_oil;
    }
    cout<<fixed<<setprecision(2)<<total_money<<endl;
    return 0;
}*/
 for(int i = 0; i < n; i++) {
    if(i > 0) current_oil -= (dis[i] - dis[i-1]) / l;
    if(current_oil < 0) { cout << "No Solution" << endl; return 0; }
    if(i < n-1 && dis[i+1] - dis[i] > c * l) { cout << "No Solution" << endl; return 0; }
    double target_oil;
    if(i == n-1) {
        target_oil = (s - dis[i]) / l;  // 到s所需
    } else {
        target_oil = c;
        for(int j = i+1; j < n; j++) {  // 只到n-1
            if(dis[j] < dis[i] + c * l) {
                if(exp[j] < exp[i]) target_oil = min(target_oil, (dis[j] - dis[i]) / l);
            } else break;
        }
    }
    double add_oil = max(0.0, target_oil - current_oil);
    if(add_oil > c - current_oil) { cout << "No Solution" << endl; return 0; }
    total_money += add_oil * exp[i];
    current_oil += add_oil;
}
// 最后消耗到s（理论上够）
current_oil -= (s - dis[n-1]) / l;
if(current_oil < 0) { cout << "No Solution" << endl; return 0; }}