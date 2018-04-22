#include "board.hpp"
#include <iostream>
#include <string.h>

Board::Board()
{
    whoseTurn='S';
    for(int i=0; i<14; i++)
    {
        if((i+1)%7==0)
            pieces[i]=0;        //set goal cup
        else
            pieces[i]=3;        //set cups
    }
}

Board::Board(const Board* board)
{
    whoseTurn=board->whoseTurn;
    memcpy((void*)pieces, (void*)board->pieces, 14);
}

Board::Board(const Board& board)
{
    whoseTurn=board.whoseTurn;
    memcpy((void*)pieces, (void*)board.pieces, 14);
}

void Board::printBoard() const
{
    std::cout << " ";
    for(int i=12; i>6; i--)
        std::cout << (int)(pieces[i]);
    std::cout << std::endl;
    std::cout << (int)(pieces[13]);
    for(int i=0; i<6; i++)
        std::cout << " ";
    std::cout << (int)(pieces[6]) << std::endl;
    std::cout << " ";
    for(int i=0; i<6; i++)
        std::cout << (int)(pieces[i]);
    std::cout << std::endl;

}

int Board::staticEval() const
{
    int out=0;
    for(int i=0; i<7; i++)
    {                           //sum of souths cups and goal plus negated sum of north's cups goal
        out+=pieces[i];
        out-=pieces[i+7];
    }
    return out;
}

void Board::playAt(const int playAt)
{
    char spread=pieces[playAt];
    char endAt=(spread+playAt)%14;
    pieces[playAt]=0;
    for(int i=0; i<spread; i++)
        pieces[(playAt+i+1)%14]++;
    if(pieces[(int)endAt]==1 &&
       ((whoseTurn=='S' && endAt<6) ||
       (whoseTurn=='N' && endAt<13 && endAt>6)))
    {
        int offset=6;
        if(playAt>6)
            offset+=7;
        pieces[offset]+=pieces[(endAt+12-(endAt%7)*2)%14]; //magic
        pieces[(endAt+12-(endAt%7)*2)%14]=0;
    }
    if(whoseTurn=='S')
        whoseTurn='N';
    else
        whoseTurn='S';
}

void Board::addPoints()
{
    for(int i=0; i<6; i++)
    {
        pieces[6]+=pieces[i];
        pieces[i]=0;
    }
    for(int i=7; i<13; i++)
    {
        pieces[13]+=pieces[i];
        pieces[i]=0;
    }
}

bool Board::checkForWin() const
{
    char sumS=0;
    char sumN=0;
    for(int i=0; i<6; i++)
    {
        sumS+=pieces[i];
        sumN+=pieces[i+7];
    }
    return ((!sumS) || (!sumN));
}

bool Board::isValidPlay(int playAt) const
{
    if(whoseTurn=='S')
        if(playAt>5)
            return 0;
    if(whoseTurn=='N')
        if(playAt<6 || playAt>12)
            return 0;
    return (bool)pieces[playAt];
}
