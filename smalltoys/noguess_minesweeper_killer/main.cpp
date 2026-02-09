#include <vector>
#include <iostream>
#include "tradition.h"
int main(){
    int size_of_board;
    std :: vector<std :: vector<char>> board;
    std::cout<<"test"<<std::endl;
    std::cout<<"please enter board size:"<<std::endl;
    std::cout.flush();
    std::cin>>size_of_board;
    board.resize(size_of_board,std :: vector<char>(size_of_board,'/'));
    tradition_killer(board,size_of_board);
}