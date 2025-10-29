/*#include <bits/stdc++.h>
using namespace std;

int main(){
    int m,s,t;
    cin>>m>>s>>t;
    //二维pair数组
    //个头，分为搓魔法和跑两种，不用pair
    //那我算搓多久魔法就行了
    //二维数组，横t竖m记录s
    //然后t的地方画一条死线
    vector<vector<int>> tmmap(t+1,vector<int> (m+20,-1));
    tmmap[0][m]=0;
    for(int i=1;i<t+1;i++){
        for(int j=0;j<m+10;j++){
            int temp=-1;
            if(tmmap[i-1][j]>=0) 
                temp=max(tmmap[i-1][j]+17,temp);
            if(j+10<m+20&&tmmap[i-1][j+10]>=0)
                temp=max(temp,tmmap[i-1][j+10]+60);//有十点魔法发动一次
            if(j>=4&&tmmap[i-1][j-4]>=0)
                temp=max(temp,tmmap[i-1][j-4]);//搓一下魔法
            if(temp>=s){
                cout<<"Yes"<<endl<<i;return 0;
            }
            tmmap[i][j]=temp;
        }
    }
    int max_dis=0;
    for(int i=0;i<m+10;i++){
        max_dis=max(max_dis,tmmap[t][i]);
    }
    cout<<"No"<<endl<<max_dis;return 0;

}妈的mle了，试试一维的*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int m,s,t;
    cin>>m>>s>>t;
    vector<int> prev(m+1,-1), cur(m+1,-1);
    prev[m]=0;
    for(int time=1;time<=t;time++){
        fill(cur.begin(),cur.end(),-1);
        for(int prevMana = 0; prevMana <= m; ++prevMana){
            if(prev[prevMana] < 0) continue; // 不可达则跳过

            int baseDist = prev[prevMana];

            // 跑步：魔法不变，+17
            {
                int curMana = prevMana;
                int tmp = baseDist + 17;
                if(tmp >= s){ cout << "Yes\n" << time << '\n'; return 0; }
                cur[curMana] = max(cur[curMana], tmp);
            }

            // 闪烁：需 >=10 魔法，消耗10点，+60
            if(prevMana >= 10){
                int curMana = prevMana - 10;
                int tmp = baseDist + 60;
                if(tmp >= s){ cout << "Yes\n" << time << '\n'; return 0; }
                cur[curMana] = max(cur[curMana], tmp);
            }

            // 休息：魔法 +4（上限 m），距离不变
            {
                int curMana = min(m, prevMana + 4);
                int tmp = baseDist;
                if(tmp >= s){ cout << "Yes\n" << time << '\n'; return 0; }
                cur[curMana] = max(cur[curMana], tmp);
            }
        }

        // 把 cur 变为 prev，进行下一秒计算
        prev.swap(cur); // 修改
    }
        int max_dis = 0;
    for(int mana = 0; mana <= m; ++mana){
        if(prev[mana] > max_dis) max_dis = prev[mana];
    }
    cout << "No\n" << max_dis << '\n';
    return 0;
    //我草还能这么玩
    }
