#include <iostream>
#include <vector>
#include "board.hpp"
#include "node.hpp"

//	Allister Lindamood - aslindamood@alaska.edu
//  Peter Trinh - pptrinh@alaska.edu
//
//	Homework assignment 3
//	10/21/17
//
//	main.cpp
//	A test routine for the minimax algorithms found in the node classes to solve Owari games
//

int Node::nodesExpanded=0;
int Node::nodesPruned=0;

int main()
{
    Node node;
    node.state.printBoard();
    int input=-1;
    while(!node.state.checkForWin())
    {
        std::cout << "Enter South's input: ";
        std::cin >> input;
        if(input>=0)
        {
            std::cout << "South plays at cup no. " << input << std::endl;
            node.state.playAt(input);
        }
        else
        {
            node.decide(16);
            std::cout << "AI South plays at cup no. " << (int)node.cupPlayed << std::endl;
            node.state.playAt(node.cupPlayed);
        }
        node.state.printBoard();
        node.decide(15);
        std::cout << "Nodes expanded: " << Node::nodesExpanded << ", nodes pruned: " << Node::nodesPruned << std::endl;
        if(node.state.checkForWin())
            break;
        std::cout << "AI North plays at cup no. " << (int)node.cupPlayed << std::endl;
        node.state.playAt(node.cupPlayed);
        node.state.printBoard();
    }
    std::cout << "Game over!\nFinal score: " << std::endl;
    node.state.addPoints();
    node.state.printBoard();
    return 0;
}
