#include "../StudPlayer/Player.h"
#include "../StudPlayer/Player_00.h"
#include "../StudPlayer/Player_01.h"
#include "../StudPlayer/Player_New.h"
#include <vector>
#include <memory>
#include <string>
#include <iostream>


class CpuVsCpuModel{
public:
  
    CpuVsCpuModel();
    ~CpuVsCpuModel();

    int * getBoard();

    int getCurrent_Player();

    void setCurrent_Player(int playerNumber);

    int getCurrentPlayersNextMove();

    std::string getPlayerName(unsigned long playerNumber);

    std::string getActivePlayerName(unsigned long playerNumber);

    void setActivePlayers(unsigned long player1, unsigned long player2);

    unsigned long * getActivePlayers();

    void setPlayerNumber(unsigned long playerIndex, int playerNumber);

    int getGameCounter();

    void setGameCounter(int counter);
private:

    unsigned long activePlayers[2];


    int board[17];

    int gameCounter;

    int current_player = 1;

    std::vector<std::unique_ptr<Player>> smartPlayers;
};





