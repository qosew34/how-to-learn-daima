#include "tradition.h"
#include <vector>
#include <iostream>
#include <unordered_map>
std :: vector<std :: vector<char>>& board;

void tradition_killer(std :: vector<std :: vector<char>>& board,int n){
    std :: cout<<"请输入已知内容，未知则输入/,雷则输入m";
    std :: vector<std ::vector<bool>> is_mine(n,std :: vector<bool>(n,true));
    std :: vector<std ::vector<bool>> is_empty(n,std :: vector<bool>(n,true));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            char temp;
            while(!((temp>='0'&&temp<='9')||temp=='?'||temp=='/'||temp=='m')){
                std :: cout<<"请重新输入";
                std :: cin>>temp;
            }
            board[i][j] = temp;
            if(temp!='m'&&temp!='/') is_mine[i][j] = false;
            if(temp!='/') is_empty[i][j] = false;
        }
    }


}