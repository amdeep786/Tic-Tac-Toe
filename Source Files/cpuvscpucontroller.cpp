#include "cpuvscpucontroller.h"

CpuVsCpuController::CpuVsCpuController(){
    gameModel = new CpuVsCpuModel;
    in_tournament = true;

    srand((unsigned)time(NULL));
    setup_taken_square((rand()%16)+1);
}

void CpuVsCpuController::setCurrentPlayers(unsigned long index1, unsigned long index2){

    gameModel->setActivePlayers(index1, index2);
    gameModel->setPlayerNumber(index1, 1);
    gameModel->setPlayerNumber(index2, 2);
}



void CpuVsCpuController::setup_taken_square(int square){
    gameModel->getBoard()[square] = 3;
}


void CpuVsCpuController::doStep(){    
    int loc_field = gameModel->getCurrentPlayersNextMove();

    if(loc_field != -1){
        bool emptyFieldsExist = false;
        for(int i = 1; i<17; i++){
            if(gameModel->getBoard()[i] == 0){
                emptyFieldsExist = true;
            }
        }
        if(!emptyFieldsExist){
            loc_field = -1;
        }
    }

    if(loc_field == -1)
    {
        show_singlegame_Result(0, 1);

        doReset();
    } else {
        setMarkOnField(loc_field);

        checkWhoWon();

        if(gameModel->getCurrent_Player() == 1)
            gameModel->setCurrent_Player(2);
        else
            gameModel->setCurrent_Player(1);
    }
}


void CpuVsCpuController::doReset(){
    int i;
    for(i = 0; i<17; i++)
    {
        gameModel->getBoard()[i] = 0;
    }

    setup_taken_square((rand()%16)+1);
}

void CpuVsCpuController::show_singlegame_Result(int status, int winner){
    std::string message = "Result-" + std::to_string(gameModel->getGameCounter()) + ": ";
    switch(status)
    {
        case 0: message += "remis!";
            break;

        case 1: message += gameModel->getActivePlayerName((winner==0)?1:2) + " wins!";
            break;

        default:
            break;
    }
    std::cout << std::endl;
    std::cout << message;
    std::cout << std::endl;

    print_board();

    gameModel->setGameCounter(gameModel->getGameCounter()+1);

    if(gameModel->getGameCounter() >= 5){
        in_tournament = false;
        gameModel->setGameCounter(0);
    }
}

bool CpuVsCpuController::checkWhoWon(){
    int iLook;

        iLook = gameModel->getBoard()[1]; // the lines first element.
        if (gameModel->getBoard()[6] == iLook && gameModel->getBoard()[11]==iLook && gameModel->getBoard()[16] == iLook && iLook != 0)
        {
            show_singlegame_Result(1, iLook - 1);
            doReset();
            return true;
        }

        iLook = gameModel->getBoard()[4]; // the lines first element.
        if (gameModel->getBoard()[7] == iLook && gameModel->getBoard()[10]==iLook && gameModel->getBoard()[13] == iLook && iLook != 0)
        {

            show_singlegame_Result(1, iLook - 1);
            doReset();
            return true;
        }

        iLook = gameModel->getBoard()[1]; // the lines first element.
        if (gameModel->getBoard()[2] == iLook && gameModel->getBoard()[3]==iLook && gameModel->getBoard()[4] == iLook && iLook != 0)
        {

            show_singlegame_Result(1, iLook - 1);
            doReset();
            return true;
        }

        iLook = gameModel->getBoard()[5]; // the lines first element.
        if (gameModel->getBoard()[6] == iLook && gameModel->getBoard()[7]==iLook && gameModel->getBoard()[8] == iLook && iLook != 0)
        {

            show_singlegame_Result(1, iLook - 1);
            doReset();
            return true;
        }

        iLook = gameModel->getBoard()[9]; // the lines first element.
        if (gameModel->getBoard()[10] == iLook && gameModel->getBoard()[11]==iLook && gameModel->getBoard()[12] == iLook && iLook != 0)
        {

            show_singlegame_Result(1, iLook - 1);
            doReset();
            return true;
        }

        iLook = gameModel->getBoard()[13]; // the lines first element.
        if (gameModel->getBoard()[14] == iLook && gameModel->getBoard()[15] == iLook && gameModel->getBoard()[16] == iLook && iLook != 0)
        {

            show_singlegame_Result(1, iLook - 1);
            doReset();
            return true;
        }


        iLook = gameModel->getBoard()[1]; // the lines first element.
        if (gameModel->getBoard()[5] == iLook && gameModel->getBoard()[9]==iLook && gameModel->getBoard()[13] == iLook && iLook != 0)
        {

            show_singlegame_Result(1, iLook - 1);
            doReset();
            return true;
        }

        iLook = gameModel->getBoard()[2]; // the lines first element.
        if (gameModel->getBoard()[6] == iLook && gameModel->getBoard()[10]==iLook && gameModel->getBoard()[14] == iLook&& iLook != 0)
        {
            show_singlegame_Result(1, iLook - 1);
            doReset();
            return true;
        }


        iLook = gameModel->getBoard()[3]; // the lines first element.
        if(gameModel->getBoard()[7] == iLook && gameModel->getBoard()[11] == iLook && gameModel->getBoard()[15] == iLook && iLook != 0)
        {

            show_singlegame_Result(1, iLook - 1);
            doReset();
            return true;
        }

 
        iLook = gameModel->getBoard()[4]; // the lines first element.
        if(gameModel->getBoard()[8] == iLook && gameModel->getBoard()[12] == iLook && gameModel->getBoard()[16] == iLook && iLook != 0)
        {

            show_singlegame_Result(1, iLook - 1);
            doReset();
            return true;
        }

        return false;
}

void CpuVsCpuController::setMarkOnField(int field){

    bool illegalMove = false;

    if((field > 16) || field < 1) { illegalMove = true; }

    if(gameModel->getBoard()[field] != 0) { illegalMove = true; }

    if(illegalMove){
        bool emptyFieldFound = false;

        while(!emptyFieldFound){
            field = (rand()%16)+1;
            emptyFieldFound = (gameModel->getBoard()[field] == 0);
        }
    }

    gameModel->getBoard()[field] = gameModel->getCurrent_Player();
}


void CpuVsCpuController::reversePlayers(){

    setCurrentPlayers(gameModel->getActivePlayers()[1], 
                      gameModel->getActivePlayers()[0]);

    gameModel->setGameCounter(0);
}

bool CpuVsCpuController::is_in_tournament(){
    return in_tournament;
}


void CpuVsCpuController::print_board(){

    std::cout << "+---------------+" << std::endl;
    for(int i=1; i<17; i++){
        std::cout << "| ";
        switch(gameModel->getBoard()[i]){
            case 1: std::cout << "x"; break;
            case 2: std::cout << "o"; break;
            case 3: std::cout << "Z"; break;
            case 0: std::cout << " "; break;
            default: std::cout << "E"; 
        }
        std::cout << " ";
        if(i%4==0) std::cout << "|" << std::endl;
    }
    std::cout << "+---------------+" << std::endl;
}
