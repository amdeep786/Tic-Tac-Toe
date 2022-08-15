# TIC TAC TOE Game

Tic-Tac-Toe is a simple game for two players. The game involves 2 players placing their respective symbols in a 4x4 grid with 16 square fields. 

## INTRODUCTION

In this project two "AI’s" compete against each other in an extended version of the game Tic-Tac-Toe. At the beginning of the game one square is blacked out and can not be used by either one of the players. In alternating turns the AI’s mark one square with either an X or an O, trying to achieve "four-in-a-row" and win the game. The player who manages to place four of their symbols in horizontal/vertical/diagonal row wins the game. If either player fails to do so the game ends in a draw. If both the people always play their optimal strategies the game always ends in a draw. The figure below shows the depiction of how the Tic Tac Toe game is being played
between the two AI’s in the project.
 
## DESCRIPTION

As the grid is small & there are only two players involved the number of possible moves for every board state is limited thus allowing Tree-based search algorithms like Alpha-Beta pruning or Minimax Algorithm to provide a computationally feasible & exact solution to building a AI-based Tic-Tac-Toe player. In this project, we look at Minimax Algorithm to the same game.

Like a professional chess player, this algorithm takes into account a few steps ahead and puts itself in the shoes of its opponent. It keeps playing ahead until it reaches a terminal arrangement of the board (terminal state) resulting in a tie, a win, or a loss. Every board state has a value associated with it Once in a terminal state, the AI will assign an arbitrary positive score (+1) for a win, a negative score (-1) for a loss, or a neutral score (0) for a tie. At the same time, the algorithm evaluates the moves that lead to a terminal state based on the players’ turn. It will choose the move with maximum score when it is the AI’s turn and choose the move with the minimum score when it is the other player’s turn. Using this strategy, Minimax avoids losing to the other player.
Minimax is a backtracking algorithm that is used in decision making and game theory to find the optimal move for a player, assuming that your opponent also plays optimally, which means that the terminal level nodes are analyzed and values are calculated that are then propagated to the root node and then the decision regarding the selection of the node is carried out. In Minimax the two players are called maximizer and minimizer. The maximizer tries to get the highest score possible while the minimizer tries to do the opposite and get the
lowest score possible.
