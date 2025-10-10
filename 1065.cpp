#include <bits/stdc++.h>
using namespace std;

int main(){
    int m,n;
    cin>>m>>n;//m机器n工件
    vector<vector<int>> record(n+1,vector<int> (m+1,0));
    /*记录工件对应机器号*/
    vector<vector<int>> exhausted_time(n+1,vector<int>(m+1,0));
    //机器用的时间
    vector<int> sx;//顺序
    int temp=0;
    for(int i=0;i<m*n;i++){
        cin>>temp;
        sx.push_back(temp);
    }
    for(int j=1;j<=n;j++){
        for(int k=1;k<=m;k++){
            cin>>temp;
            record[j][k]=temp;
        }
    }
    for(int l=1;l<=n;l++){
        for(int o=1;o<=m;o++){
            cin>>temp;
            exhausted_time[l][o]=temp;
        }
    }
    //开始拼时间表
    vector<vector<pair<int, int>>> machine_busy(m+1);
    //机器忙碌时间
    // start_time[j][k]: 第 j 个工件的第 k 道工序的开始时间
    vector<vector<int>> start_time(n+1, vector<int>(m+1, -1));
    // end_time[j][k]: 第 j 个工件的第 k 道工序的结束时间
    vector<vector<int>> end_time(n+1, vector<int>(m+1, -1));
    int total_time=0;
    vector<int> current_gj(n+1,1);//第几个工件到哪了
    for(int i=0;i<n*m;i++){
        int j=sx[i];//在做哪个
        int k=current_gj[j]++;//第几步
        int mac_num=record[j][k];//哪个机器
        int use_time=exhausted_time[j][k];//要用多久
        int best_start_time=(k==1?0:end_time[j][k-1]);
        int t=best_start_time;
        for(size_t j=0;j<machine_busy[mac_num].size();j++){//sizet 无符号整型
            auto& busytime=machine_busy[mac_num][j];//遍历busytime
            int s=busytime.first;int e=busytime.second;
            if(t+use_time<=s){
                break;
            }
            else if(t<e){
                t=e;
            }
        }
            start_time[j][k]=t;
            int et = t+use_time;
            end_time[j][k]=et;
            machine_busy[mac_num].push_back({t,et});
            sort(machine_busy[mac_num].begin(),machine_busy[mac_num].end());
            total_time=max(total_time,et);
    }
        cout<<total_time<<endl;
        return 0;
    
}
/*busytime是一个对忙碌时间的引用，试图遍历
busytime.fisrt()是pair的第一个，second是第二个即结束时间*/