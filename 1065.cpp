#include <bits/stdc++.h>
using namespace std;

int m,n,total_time;
vector<vector<int>> lc(m,vector<int>(total_time,0));//总的流程
vector<vector<int>> record(n,vector<int> (m,0));
/*记录工件对应机器号*/
vector<vector<int>> exhausted_time(n,vector<int>(m,0));
//机器用的时间
vector<int> gj_end_time(n,0);//当前工件可以从哪里开始写
vector<int> machine_max_time(m,0);
void jg(int gjnum,int gxnum){//工件，工序，读用的机器，塞进去
//第一步，读机器
int machine_num;
machine_num=record[gjnum][gxnum];
//第二步，读时间
int used_time;
used_time=exhausted_time[gjnum][gxnum];
//第三步，填
//已经用到p了
if(gj_end_time[gjnum]>machine_max_time){
    
}
for(int q=gj_end_time[gjnum];q<machine_max_time[machine_num]+1;q++){
    int accomplish=0;
    if ()
}
}
int main(){
    cin>>m>>n;//m机器n工件
    vector<int> sx={0};//顺序
    int temp;
    for(int i=0;i<m*m;i++){
        cin>>temp;
        sx.push_back(temp);
    }
    for(int j=0;j<n;j++){
        for(int k=0;k<m;k++){
            cin>>temp;
            record[n][m]=temp;
        }
    }
    for(int l=0;l<n;l++){
        for(int o=0;o<m;o++){
            cin>>temp;
            exhausted_time[n][n]=temp;
        }
    }
    //开始拼时间表
    vector<int> gx={1};//第x位代表第x个零件到第几步
    for(int p=0;p<m*n;p++){
        jg(sx[p],gx[sx[p]]);
        gx[sx[p]]++;//做完这一步到下一步
    }
}