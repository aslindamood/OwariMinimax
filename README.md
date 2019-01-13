# OwariMinimax
Owari board game with minimax-based AI. 
This project was written for an AI Owari Tournament at UAA in 2017

# Features
The Board class implements a functional model of Owari, a traditional game similar to Mancala.
The Node class represents a game state and can calculate a move for either side in any given state

# How to Use
The code in main.cpp provides an example layout for a human playing against the AI. 
Creating a Node object will also create a board laid out in the starting position.
Calling Node::decide() will cause the AI to generate a move for the current player.
  The search depth can be set explicitly by passing an integer to Node::decide().
  Searches running deeper than 15 steps grow slower and unstable quickly.
The gamestate can be modified directly by accessing the board object within the current Node.

# Credits
Written and designed by Allister Lindamood and Peter Trinh
Compiled and tested with GCC 4.7
