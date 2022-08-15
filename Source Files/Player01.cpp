#include "Player_New.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <vector>

Player_New::Player_New()
{
	name_of_developer = std::string("Player_New");
	player_no = 7625;
}

Player_New::~Player_New()
{
}


int checkWinner(int fld_status[]) {
	//horizontal
	int winner = -1;
	for (int i = 1; i < 13; i += 4) {
		if (fld_status[i] !=0 && (fld_status[i] == fld_status[i + 1] && fld_status[i] == fld_status[i + 2] && fld_status[i] == fld_status[i + 3] )) {
			winner = fld_status[i];
			return winner;
		}
	}

	//vertical
	for (int i = 1; i < 5; i++) {
		if (fld_status[i] != 0 && (fld_status[i] == fld_status[i + 4] && fld_status[i] == fld_status[i + 8] && fld_status[i] == fld_status[i + 12])) {
			winner = fld_status[i];
			return winner;
		}
	}

	//diagnal
	if (fld_status[1] != 0 && (fld_status[1] == fld_status[6] && fld_status[1] == fld_status[11] && fld_status[1] == fld_status[16])) {
		winner = fld_status[1];
		return winner;
	}

	if (fld_status[4] != 0 && (fld_status[4] == fld_status[7] && fld_status[4] == fld_status[10] && fld_status[4] == fld_status[13])) {
		winner = fld_status[4];
		return winner;
	}

	//draw
	int count = 0;
	for (int i = 1; i < 17; i++) {
		if (fld_status[i] != 0) {
			count++;
		}
	}
	if (count == 16) return 0;
	return winner;
}


int minMaxAlgo(int fld_status[], int depth, bool isMaximize, int playerNo) {
	//std::cout << "Entered into this depth "<< depth;
	int result = checkWinner(fld_status);
	if (result != -1) {
		if (result == playerNo) {
			return 1;
		}
		else if (result != 0) {
			return -1;
		}
		else {
			return 0;
		}
	}
	if (isMaximize) {
		int bestScore = -5;
		for (int i = 1; i < 17; i++) {
			if (fld_status[i] == 0) {
				//available
				fld_status[i] = playerNo;
				int score = minMaxAlgo(fld_status, depth + 1, false, playerNo);
				fld_status[i] = 0;
				if (score > bestScore) {
					bestScore = score;
				}
			}
		}
		return bestScore;
	}
	else {
		int bestScore = 5;
		for (int i = 1; i < 17; i++) {
			if (fld_status[i] == 0) {
				//available
				fld_status[i] = (playerNo == 1) ? 2 : 1;
				int score = minMaxAlgo(fld_status, depth + 1, true, playerNo);
				fld_status[i] = 0;
				if (score < bestScore) {
					bestScore = score;
				}
			}
		}
		return bestScore;
	}
}

int cornersAvailable(int fld_status[]) {
	int cornerValues[] = { 1,4,13,16,6,11 };
	std::vector< int > availablePos;
	for (int i = 1; i < 6; i++) {
		int pos = cornerValues[i];
		if (fld_status[pos] == 0) {
			availablePos.push_back(pos);
		}
	}
	if (availablePos.size() == 0) {
		return -1;
	}
	int random_index = (rand() % availablePos.size()-1) + 1;
	return availablePos[random_index];
}

int Player_New::getNextMove(int fld_status[])
{
	srand((unsigned)time(NULL));
	int toplace_pos = -1;

	int bestScore = -5;
	int move = 0;
	if (!fields_left(fld_status)) {
		return -1;
	}
	if (cornersAvailable(fld_status) != -1) {
		int pos = cornersAvailable(fld_status);
		int temp = 0;
		return pos;
	}
	for (int i = 1; i < 17; i++) {
		
		if (fld_status[i] == 0) {
			fld_status[i] = 1;
			int score = minMaxAlgo(fld_status, 0, false, 1);
			fld_status[i] = 0;
			if (score > bestScore) {
				bestScore = score;
				move = i;
			}
		}
	}
	return move;
}
