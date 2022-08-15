#include "cpuvscpumodel.h"

CpuVsCpuModel::CpuVsCpuModel() {
    for (int i=0; i<17;i++) {
        board[i]=0;
    }

    gameCounter = 0;
    smartPlayers.reserve(2);

   
    std::unique_ptr<Player> player_new(new Player_New());
    smartPlayers.push_back(std::move(player_new));
    
    std::unique_ptr<Player> player_01 (new Player_01());
    smartPlayers.push_back(std::move(player_01));

    smartPlayers.at(0)->setPlayerNumber(1);
    smartPlayers.at(1)->setPlayerNumber(2);
    activePlayers[0] = 0;
    activePlayers[1] = 1;
}


int * CpuVsCpuModel::getBoard(){
    return board;
}

int CpuVsCpuModel::getCurrent_Player(){
    return current_player;
}

void CpuVsCpuModel::setCurrent_Player(int playerNumber){
    current_player = playerNumber;
}


std::string CpuVsCpuModel::getPlayerName(unsigned long playerNumber){
    return smartPlayers.at(playerNumber)->get_dev_name();
}

std::string CpuVsCpuModel::getActivePlayerName(unsigned long playerNumber){
    return smartPlayers.at(activePlayers[playerNumber-1])->get_dev_name();
}

void CpuVsCpuModel::setActivePlayers(unsigned long player1, unsigned long player2){
    activePlayers[0] = player1;
    activePlayers[1] = player2;
}

unsigned long * CpuVsCpuModel::getActivePlayers(){
    return activePlayers;
}

void CpuVsCpuModel::setPlayerNumber(unsigned long playerIndex, int playerNumber){
    smartPlayers.at(playerIndex)->setPlayerNumber(playerNumber);
}

void CpuVsCpuModel::setGameCounter(int counter){
    gameCounter = counter;
}

int CpuVsCpuModel::getGameCounter(){
    return gameCounter;
}

int CpuVsCpuModel::getCurrentPlayersNextMove(){
    return smartPlayers.at(activePlayers[current_player-1])->getNextMove(board);
}
