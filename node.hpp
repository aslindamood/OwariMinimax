#ifndef NODE_HPP
#define NODE_HPP

//	Allister Lindamood - aslindamood@alaska.edu
//  Peter Trinh - pptrinh@alaska.edu
//
//	Homework assignment 3
//	10/21/17
//
//	node.hpp
//	A class that contains a node for searching Owari board states and various functions to manipulate it
//

struct Node
{
    Node(const Node* parent=(Node*)0x0, const int playAt=-1);               //default constructor

    int decide(char maxDepth=5);                                            //wrapper function for Minimax algorithm- returns cup to play at based on whose turn it is
    char evalMax(char maxDepth, char alpha=0x80, char beta=0x7F);           //Maximizer node for Minimax algorithm
    char evalMin(char maxDepth, char alpha=0x80, char beta=0x7F);           //Minimizer node for Minimax algorithm
    bool isEndState() const;                                                //Check for game over state

    static int nodesExpanded;
    static int nodesPruned;

    char cupPlayed;
    Board state;
    std::vector<Node> children;
};

#endif // NODE_HPP
