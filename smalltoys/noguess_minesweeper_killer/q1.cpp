#include "tradition.h"
#include <vector>
#include <iostream>
#include <unordered_map>
//和普通版相比，结算的时候要检查每四格是否有m
//没想法，后面再改
void q1_checker_notcut(std :: vector<std :: vector<char>> &board,int n,int x,int y,std :: vector<std ::vector<bool>>&is_empty,std :: vector<std ::vector<bool>>&is_mine,int total){
    if(board[x][y]!='/'){
        if(x==n-1&&y==n-1){
            int total_m = 0;
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < n ; j++){
                    if(board[i][j]=='m') total_m++;
                }
            }
            if(total_m!=total) return;
            std :: vector<std :: vector<bool>> pre(n-1,std:: vector<bool>(n-1,false));
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < n ; j++){
                    if(board[i][j]=='m'){
                        if(i+1 <= n-2 && j+1 <= n-2) pre[i+1][j+1] = true;
                        if(i <= n-2 && j <= n-2) pre[i][j] = true;
                        if(i <= n-2 && j+1 <= n-2) pre[i][j+1] = true;
                        if(i+1 <= n-2 && j <= n-2) pre[i+1][j] = true;
                    }
                }
            }
            bool cannot = true;
            for(auto a : pre)for(auto b : a) cannot = cannot&&b;
            if(!cannot) return;
            for(int i = 0 ; i < n ; i++){
                    for(int j = 0 ; j < n ; j++){
                        if(board[i][j]=='/'||board[i][j]=='?') is_empty[i][j] = is_empty[i][j]&true;
                        else is_empty[i][j] = false;
                        if(board[i][j]=='m') is_mine[i][j] = is_mine[i][j]&true;
                        else is_mine[i][j] = false;
                    }
            }
        }
        if(x!=n-1) q1_checker_notcut(board,n,x+1,y,is_empty,is_mine,total);
        else if(y!=n-1) q1_checker_notcut(board,n,0,y+1,is_empty,is_mine,total);
        return;
    }
    else{
        std :: vector<int> xs = {-1,-1,-1,0,0,1,1,1};
        std :: vector<int> ys = {1,0,-1,1,-1,1,0,-1};
        bool can_be_mine = true;
        bool can_be_empty = true;
        for(int i = 0 ; i < 8 ; i++){
            if(x+xs[i]<0||x+xs[i]>n-1||y+ys[i]<0||y+ys[i]>n-1) continue;
            char temp = board[x+xs[i]][y+ys[i]];
            int x1 = x+xs[i],y1 = y+ys[i];//是数字的点
            if(temp>='0'&&temp<='9'){
                int may_be_mine = 0;
                int must_mine = 0;
                for(int j = 0 ; j < 8 ; j++){//数m和/的数量
                    if(x1+xs[j]<0||x1+xs[j]>n-1||y1+ys[j]<0||y1+ys[j]>n-1) continue;
                    if(x1+xs[j]==x&&y1+ys[j]==y) continue;//不数本格
                    char a = board[x1+xs[j]][y1+ys[j]];
                    if(a=='/') may_be_mine++;
                    if(a=='m') must_mine++;
                }
                if(temp-'0'-may_be_mine-must_mine==1){
                    can_be_empty = false;
                }
                else if(temp - must_mine - '0'==0){
                    can_be_mine = false;
                }
            }
        }
        if(x==n-1&&y==n-1){
            if(can_be_empty){
                board[x][y] = '?';
                for(int i = 0 ; i < n ; i++){
                    for(int j = 0 ; j < n ; j++){
                        if(board[i][j]=='/'||board[i][j]=='?') is_empty[i][j] = is_empty[i][j]&true;
                        else is_empty[i][j] = false;
                        if(board[i][j]=='m') is_mine[i][j] = is_mine[i][j]&true;
                        else is_mine[i][j] = false;
                    }
                }
            }
            if(can_be_mine){
                board[x][y] = 'm';
                for(int i = 0 ; i < n ; i++){
                    for(int j = 0 ; j < n ; j++){
                        if(board[i][j]=='/'||board[i][j]=='?') is_empty[i][j] = is_empty[i][j]&true;
                        else is_empty[i][j] = false;
                        if(board[i][j]=='m') is_mine[i][j] = is_mine[i][j]&true;
                        else is_mine[i][j] = false;
                    }
                }
            }
        }
        if(y*n+x+1>total){
            int count_m = 0;
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < n ; j++){
                    if(board[i][j]=='m') count_m++;
                }
            }
            if(count_m>total) return;
        }
        if(x>0&&y>0&&is_empty[x][y]){
            char a = board[x-1][y-1] , b = board[x][y-1] , c = board[x-1][y];
            if(a!='m'&&a!='/'&&b!='m'&&b!='/'&&c!='m'&&c!='/') is_empty[x][y] = false;
        }
        if(x>0&&y<n-1&&is_empty[x][y]){
            char a = board[x-1][y+1] , b = board[x][y+1] , c = board[x-1][y];
            if(a!='m'&&a!='/'&&b!='m'&&b!='/'&&c!='m'&&c!='/') is_empty[x][y] = false;
        }
        if(x<n-1&&y<n-1&&is_empty[x][y]){
            char a = board[x+1][y+1] , b = board[x][y+1] , c = board[x+1][y];
            if(a!='m'&&a!='/'&&b!='m'&&b!='/'&&c!='m'&&c!='/') is_empty[x][y] = false;
        }
        if(x<n-1&&y>0&&is_empty[x][y]){
            char a = board[x+1][y-1] , b = board[x][y-1] , c = board[x+1][y];
            if(a!='m'&&a!='/'&&b!='m'&&b!='/'&&c!='m'&&c!='/') is_empty[x][y] = false;
        }
        char pre = board[x][y];
        if(can_be_empty){
            board[x][y] = '?';
            if(x!=n-1) q1_checker_notcut(board,n,x+1,y,is_empty,is_mine,total);
            else if(y!=n-1) q1_checker_notcut(board,n,0,y+1,is_empty,is_mine,total);
            board[x][y] = pre;
        }
        if(can_be_mine){
            board[x][y] = 'm';
            if(x!=n-1) q1_checker_notcut(board,n,x+1,y,is_empty,is_mine,total);
            else if(y!=n-1) q1_checker_notcut(board,n,0,y+1,is_empty,is_mine,total);
            board[x][y] = pre;
        }
        
    }
}
void q1_checker_cut(std :: vector<std :: vector<char>> &board,int n,int x,int y,std :: vector<std ::vector<bool>>&is_empty,std :: vector<std ::vector<bool>>&is_mine){
    //这个点是雷的可能，然后传给下一个checker,如果true传回ismine和isempty
    //非/则过
    if(board[x][y]!='/'){
        if(x==n-1&&y==n-1){
            for(int i = 0 ; i < n ; i++){
                    for(int j = 0 ; j < n ; j++){
                        if(board[i][j]=='/'||board[i][j]=='?') is_empty[i][j] = is_empty[i][j]&true;
                        else is_empty[i][j] = false;
                        if(board[i][j]=='m') is_mine[i][j] = is_mine[i][j]&true;
                        else is_mine[i][j] = false;
                    }
            }
        }
        if(x!=n-1) q1_checker_cut(board,n,x+1,y,is_empty,is_mine);
        else if(y!=n-1) q1_checker_cut(board,n,0,y+1,is_empty,is_mine);
        return;
    }
    else{
        std :: vector<int> xs = {-1,-1,-1,0,0,1,1,1};
        std :: vector<int> ys = {1,0,-1,1,-1,1,0,-1};
        //先判定周围有没有数字，非雷可不可能，可以加入剪枝
        bool can_be_mine = true;
        bool can_be_empty = true;
        bool has_number = false;
        for(int i = 0 ; i < 8 ; i++){
            if(x+xs[i]<0||x+xs[i]>n-1||y+ys[i]<0||y+ys[i]>n-1) continue;
            char temp = board[x+xs[i]][y+ys[i]];
            int x1 = x+xs[i],y1 = y+ys[i];//是数字的点
            if(temp>='0'&&temp<='9'){
                has_number = true;
                int may_be_mine = 0;
                int must_mine = 0;
                for(int j = 0 ; j < 8 ; j++){//数m和/的数量
                    if(x1+xs[j]<0||x1+xs[j]>n-1||y1+ys[j]<0||y1+ys[j]>n-1) continue;
                    if(x1+xs[j]==x&&y1+ys[j]==y) continue;//不数本格
                    char a = board[x1+xs[j]][y1+ys[j]];
                    if(a=='/') may_be_mine++;
                    if(a=='m') must_mine++;
                }
                if(temp-'0'-may_be_mine-must_mine==1){
                    can_be_empty = false;
                }
                else if(temp - must_mine - '0'==0){
                    can_be_mine = false;
                }
            }
        }
        //如果周围四格皆非/，那么必为m
        if(has_number){
        if(x>0&&y>0&&is_empty[x][y]){
            char a = board[x-1][y-1] , b = board[x][y-1] , c = board[x-1][y];
            if(a!='m'&&a!='/'&&b!='m'&&b!='/'&&c!='m'&&c!='/') is_empty[x][y] = false;
        }
        if(x>0&&y<n-1&&is_empty[x][y]){
            char a = board[x-1][y+1] , b = board[x][y+1] , c = board[x-1][y];
            if(a!='m'&&a!='/'&&b!='m'&&b!='/'&&c!='m'&&c!='/') is_empty[x][y] = false;
        }
        if(x<n-1&&y<n-1&&is_empty[x][y]){
            char a = board[x+1][y+1] , b = board[x][y+1] , c = board[x+1][y];
            if(a!='m'&&a!='/'&&b!='m'&&b!='/'&&c!='m'&&c!='/') is_empty[x][y] = false;
        }
        if(x<n-1&&y>0&&is_empty[x][y]){
            char a = board[x+1][y-1] , b = board[x][y-1] , c = board[x+1][y];
            if(a!='m'&&a!='/'&&b!='m'&&b!='/'&&c!='m'&&c!='/') is_empty[x][y] = false;
        }
        }
        if(x==n-1&&y==n-1){
            if(can_be_empty){
                board[x][y] = '?';
                for(int i = 0 ; i < n ; i++){
                    for(int j = 0 ; j < n ; j++){
                        if(board[i][j]=='/'||board[i][j]=='?') is_empty[i][j] = is_empty[i][j]&true;
                        else is_empty[i][j] = false;
                        if(board[i][j]=='m') is_mine[i][j] = is_mine[i][j]&true;
                        else is_mine[i][j] = false;
                    }
                }
            }
            if(can_be_mine){
                board[x][y] = 'm';
                for(int i = 0 ; i < n ; i++){
                    for(int j = 0 ; j < n ; j++){
                        if(board[i][j]=='/'||board[i][j]=='?') is_empty[i][j] = is_empty[i][j]&true;
                        else is_empty[i][j] = false;
                        if(board[i][j]=='m') is_mine[i][j] = is_mine[i][j]&true;
                        else is_mine[i][j] = false;
                    }
                }
            }
        }

        char pre = board[x][y];
        if(!has_number){
            if(x!=n-1) q1_checker_cut(board,n,x+1,y,is_empty,is_mine);
            else if(y!=n-1) q1_checker_cut(board,n,0,y+1,is_empty,is_mine);
            is_empty[x][y] = false;
            is_mine[x][y] = false;
            return;
        }
        if(can_be_empty){
            board[x][y] = '?';
            if(x!=n-1) q1_checker_cut(board,n,x+1,y,is_empty,is_mine);
            else if(y!=n-1) q1_checker_cut(board,n,0,y+1,is_empty,is_mine);
            board[x][y] = pre;
        }
        if(can_be_mine){
            board[x][y] = 'm';
            if(x!=n-1) q1_checker_cut(board,n,x+1,y,is_empty,is_mine);
            else if(y!=n-1) q1_checker_cut(board,n,0,y+1,is_empty,is_mine);
            board[x][y] = pre;
        }
    }
}
void q1_killer(std :: vector<std :: vector<char>>& board,int n){
    std :: cout<<"please input the board,if blank,replace it by / "<<std :: endl;
    std :: vector<std ::vector<bool>> is_mine(n,std :: vector<bool>(n,true));
    std :: vector<std ::vector<bool>> is_empty(n,std :: vector<bool>(n,true));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            char temp;std :: cin>>temp;
            while(!((temp>='0'&&temp<='9')||temp=='?'||temp=='/'||temp=='m')){
                std :: cout<<"please reenter";
                std :: cin>>temp;
            }
            board[i][j] = temp;
            if(temp!='m'&&temp!='/') is_mine[i][j] = false;
            if(temp!='/') is_empty[i][j] = false;
        }
    }
    int total = -1;
    std :: cout<<"tell me the total number of mines if you know, if not, input -1"<< std :: endl;
    std :: cin>>total;
    //没什么好的思路，穷举？
    //回溯
    if(total == -1){//启动剪枝
        q1_checker_cut(board,n,0,0,is_empty,is_mine);
    }
    else if(total!=-1){
        q1_checker_notcut(board,n,0,0,is_empty,is_mine,total);
    }
    for(int i = 0 ; i <= n - 1 ; i ++){
        for(int j = 0 ; j <= n - 1 ; j++){
            if(is_empty[i][j]) board[i][j] = '?';
            if(is_mine[i][j]) board[i][j] = 'm';
            std :: cout<<board[i][j]<<" ";
        }
        std :: cout<<std :: endl;
    }
}