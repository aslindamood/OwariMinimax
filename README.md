# OwariMinimax
Owari board game with minimax-based AI. <br/>
This project was written for an AI Owari Tournament at UAA in 2017

# Features
The Board class implements a functional model of Owari, a traditional game similar to Mancala.<br/>
The Node class represents a game state and can calculate a move for either side in any given state

# How to Use
The code in main.cpp provides an example layout for a human playing against the AI.<br/>
Creating a Node object will also create a board laid out in the starting position.<br/>
Calling Node::decide() will cause the AI to generate a move for the current player.<br/>
  The search depth can be set explicitly by passing an integer to Node::decide().<br/>
  Searches running deeper than 15 steps grow slower and unstable quickly.<br/>
The gamestate can be modified directly by accessing the board object within the current Node.

# Credits
Written and designed by Allister Lindamood and Peter Trinh<br/>
Compiled and tested with GCC 4.7
