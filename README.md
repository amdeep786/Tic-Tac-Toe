# TIC TAC TOE Game

Tic-Tac-Toe is a simple game for two players. The game involves 2 players placing their respective symbols in a 4x4 grid with 16 square fields. 

## INTRODUCTION

In this work two "AI’s" compete against each other in an extended version of the game Tic-Tac-Toe. At the beginning of the game one square is blacked out and can not be used by either one of the players. In alternating turns the AI’s mark one square with either an X or an O, trying to achieve "four-in-a-row" and win the game. The player who manages to place four of their symbols in horizontal/vertical/diagonal row wins the game. If either player fails to do so the game ends in a draw. If both the people always play their optimal strategies the game always ends in a draw.
 
## DESCRIPTION

As the grid is small & there are only two players involved the number of possible moves for every board state is limited thus allowing Tree-based search algorithms like Alpha-Beta pruning or Minimax Algorithm to provide a computationally feasible & exact solution to building a AI-based Tic-Tac-Toe player. The Minimax Algorithm has been employed in this work.

Like a professional chess player, this algorithm takes into account a few steps ahead and puts itself in the shoes of its opponent. It keeps playing ahead until it reaches a terminal arrangement of the board (terminal state) resulting in a tie, a win, or a loss. Every board state has a value associated with it Once in a terminal state, the AI will assign an arbitrary positive score (+1) for a win, a negative score (-1) for a loss, or a neutral score (0) for a tie. At the same time, the algorithm evaluates the moves that lead to a terminal state based on the players’ turn. It will choose the move with maximum score when it is the AI’s turn and choose the move with the minimum score when it is the other player’s turn. Using this strategy, Minimax avoids losing to the other player.
Minimax is a backtracking algorithm that is used in decision making and game theory to find the optimal move for a player, assuming that your opponent also plays optimally, which means that the terminal level nodes are analyzed and values are calculated that are then propagated to the root node and then the decision regarding the selection of the node is carried out. In Minimax the two players are called maximizer and minimizer. The maximizer tries to get the highest score possible while the minimizer tries to do the opposite and get the lowest score possible.

## System Features

In this project the AI player that has been designed in order to win over the other player. The function "Check", is used to check win situation of the game. It takes into account all possibilities by which a player can win this game. The following conditions associated with winning this Tic Tac Toe game have been considered:
1. The status of the field of the board in horizontal direction is considered, that is all the 4 rows present in the 4*4 matrix.
2. The status of the field of the board in the vertical direction is considered, that is it all the 4 coloumns present in the 4*4 matrix.
3. The status of the field of the tic tac toe game among the diagonals, the 2 diagonals present.
4. To acknowkledge a draw between the players.

The next and foremost important function is the "Minimax", in which the algorithm is being deployed, in order to find the next optimal move for the player. The first  task that is being carried out is to find the current status of the particular field in the board, i.e is it winning, losing or there’s a draw. Then the maximize segment of the Minimax algorithm comes into action which will try to get the highest score possible and maximize the chances of winning of the player, followed by the min segment of the Minimax algorithm which will try to get the lowest score possible and minimize the chances of winning of the other player.

The function next in line is "corner". It takes into account the corner values in the grid and deploy the values in a manner so that the AI player wins. As in general, the corner values in a tic tac toe game plays a striking role in deciding the winning player, thus it lays down the logic to cover all these values. Last but not the least is the getNextMove function, that will decide the next move to be taken by the AI player, as per the analysis that has been carried out by the Minimax Algorithm.
