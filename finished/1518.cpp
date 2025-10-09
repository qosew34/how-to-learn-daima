#include <bits/stdc++.h>
using namespace std;

void move(vector<vector<char>>&mp,int &x,int &y,int &cx,char renshou){
    /*第一类情况，朝向边界，第二类情况，朝向障碍
    感觉可以按照朝向来*/
    if (cx==0){/*北*/
        if(x==0||x!=0&&mp[x-1][y]=='*'){
            cx++;
        }
        else{
            if (renshou=='F'){
            mp[x-1][y]='F';}
            if (renshou=='C'){
            mp[x-1][y]='C';}
            mp[x][y]='.';
            x--;
        }
    }
    else if (cx==1){/*东*/
        if(y==9||y!=9&&mp[x][y+1]=='*'){
            cx++;
        }
        else{
            if (renshou=='F'){
            mp[x][y+1]='F';}
            if (renshou=='C'){
            mp[x][y+1]='C';}
            mp[x][y]='.';
            y++;
        }
    }
    else if (cx==2){/*南*/
        if(x==9||x!=9&&mp[x+1][y]=='*'){
            cx++;
        }
        else{
            if (renshou=='F'){
            mp[x+1][y]='F';}
            if (renshou=='C'){
            mp[x+1][y]='C';}
            mp[x][y]='.';
            x++;
        }
    }
    else if (cx==3){/*西*/
        if(y==0||y!=0&&mp[x][y-1]=='*'){
            cx++;
        }
        else{
            if (renshou=='F'){
            mp[x][y-1]='F';}
            if (renshou=='C'){
            mp[x][y-1]='C';}
            mp[x][y]='.';
            y--;
        }
    }
    cx=cx%4;
}
int main(){
    string temp_line;
    vector<vector<char>> mp(10,vector<char>(10,'.'));
    int manx,many,cowx,cowy;
    for(int i=0;i<10;i++){
        getline(cin,temp_line);
        for(int j=0;j<10;j++){
            if(temp_line[j]=='F'){
                manx=i;many=j;
            }
            else if(temp_line[j]=='C'){/*单引号，string某项是char*/
                cowx=i;cowy=j;
            }
            mp[i][j]=temp_line[j];
        }
    }
    int mcx=0;int ccx=0;
    int time=0;
    while (time<1000&&time>=0){
        if(cowx==manx&&cowy==many){break;}
        else{
            move(mp,manx,many,mcx,'F');
            move(mp,cowx,cowy,ccx,'C');
            time++;
        }
    }
    /*0北1东2南3西*//*最高次用同余*/
    if(time==1000){cout<<0<<endl;}
    else{cout<<time<<endl;}
    return 0;
}