#include "board.hpp"
#include <vector>
#include "node.hpp"

Node::Node(const Node* parent, int playAt)
{
    if(parent)
        state=Board(parent->state);
    else
        state=Board();
    if(playAt>=0)
        state.playAt(playAt);               //update board to new state if necessary
    cupPlayed=playAt;
}

int Node::decide(char maxDepth)
{
    nodesExpanded=0;
    nodesPruned=0;
    children.clear();
    if(state.whoseTurn=='S')               //maximize
        evalMax(maxDepth);
    else                                    //minimize
        evalMin(maxDepth);
    return cupPlayed;
}

char Node::evalMax(char maxDepth, char alpha, char beta)
{
    if(maxDepth==0 || state.checkForWin()) //First, check to see if we can go any deeper, or if this state is an endgame state
        return (char)state.staticEval();             //if so, return the heuristic value of this state.
    for(int i=0; i<6; i++)                  //it's important to note that heuristic values here are not side-specific, that is, a heuristic value that is negative is
    {                                           // beneficial to the North player, whereas a positive is beneficial to south
        if(state.isValidPlay(i))           //step through all moves, making sure each move is valid for the given scenario (can't play on an empty cup!)
        {
            nodesExpanded++;
            children.push_back(Node(this, i));  //Expand node
            char compare=children.back().evalMin(maxDepth-1, alpha, beta);      //recursive (bicursive?) call to expand the tree further
            if(compare>alpha)               //check for better maximin value
            {
                alpha=compare;
                cupPlayed=i;                //set the 'last move' variable to the best option from the branch. When the algorithm completes, the 'last move' variable
            }                                   //will be set to the best option from the uppermost branch;
            if(beta<=alpha)
            {                               //check for better preexisting solutions-
                nodesPruned++;
                return alpha;               //if they exist, stop evaluating this branch and simply return the best number found yet
            }
        }
    }
    return alpha;                           //return the maximum heuristic value for a fully expanded branch
}

char Node::evalMin(char maxDepth, char alpha, char beta) //this is all a mirror of evalMax
{
     if(maxDepth==0 || state.checkForWin())
        return state.staticEval();
    for(int i=7; i<13; i++)
    {
        if(state.isValidPlay(i))
        {
            children.push_back(Node(this, i));
            char compare=children.back().evalMax(maxDepth-1, alpha, beta);
            if(compare<beta)
            {
                beta=compare;
                cupPlayed=i;
            }
            if(beta<=alpha)
                return beta;
        }
    }
    return beta;
}

bool Node::isEndState() const
{
    return state.checkForWin();
}
