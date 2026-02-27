#include <vector>
#include <iostream>
#include "tradition.h"
#include "q1.h"
#include "c1.h"
int main(){
    int size_of_board;
    std :: vector<std :: vector<char>> board;
    std::cout<<"please enter board size:"<<std::endl;
    std::cout.flush();
    std::cin>>size_of_board;
    board.resize(size_of_board,std :: vector<char>(size_of_board,'/'));
    std::cout<<"please choose the mode"<<std :: endl;
    std::cout<<"tradition : 1"<<std :: endl;
    std::cout<<"q1 : 2(there's some problem remain to be debug)"<<std :: endl;
    std::cout<<"more mode remains cin"<< std :: endl;
    int op;
    std :: cin>>op;
    bool running = true;
    while(running){
        switch(op){
            case 1: 
            tradition_killer(board,size_of_board);
            running = false;
            break;
        case 2:
            break;
            q1_killer(board,size_of_board);
            running = false;
            break;
        case 3:
            c1_killer(board,size_of_board);
            running = false;
            break;
        default :
            std :: cout<<"INvalid input."<<std :: endl;
            break;
        }
    }
}