#include <vector>
#include <iostream>
#include "tradition.h"
#include <windows.h>
int main(){
    SetConsoleOutputCP(CP_UTF8); // 设置控制台为UTF-8
    setlocale(LC_ALL, "");
    int size_of_board;
    std::cout<<"基于十四种扫雷变体而写";
    std::cout<<"请输入边长"<<std::endl;
    std::cin>>size_of_board;
    board.resize(size_of_board,std :: vector<char>(size_of_board,-1));
    tradition_killer(board,size_of_board);
}