#ifndef BOARD_HPP
#define BOARD_HPP

//	Allister Lindamood - aslindamood@alaska.edu
//  Peter Trinh - pptrinh@alaska.edu
//
//	Homework assignment 3
//	10/21/17
//
//	board.hpp
//	A class that contains an Oware board and various functions to manipulate it
//


struct Board
{
    Board();                                //default and copy constructors
    Board(const Board* board);
    Board(const Board& board);

    void printBoard() const;                //print board to screen
    int staticEval() const;                 //Heuristic function- see source for notes
    void playAt(const int playAt);          //play the seeds in cup specified
    bool checkForWin() const;               //check for and end-game state
    void addPoints();                       //deposit remaining seeds into the appropriate owner's goals for scoring
    bool isValidPlay(int playAt) const;     //check if a given move is valid

    char pieces[14];
    char whoseTurn;
};


#endif // BOARD_HPP
