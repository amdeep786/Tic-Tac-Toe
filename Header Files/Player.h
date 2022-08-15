#include <string>

class Player
{
public:
    Player();
    Player(int no);
    ~Player();

    virtual int getNextMove(int fld_status[]);

    bool fields_left(int fld_status[]);

    int get_own_Player_no();

    std::string get_dev_name();

    void setPlayerNumber(int no) { player_no = no; }

protected:

    std::string name_of_developer;

    int player_no;
};
