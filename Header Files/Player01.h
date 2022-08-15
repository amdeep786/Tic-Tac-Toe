#include "Player.h"

class Player_New :
	public Player
{
public:
	Player_New();
	Player_New(int no);
	~Player_New();

	int getNextMove(int fld_status[]);
};
