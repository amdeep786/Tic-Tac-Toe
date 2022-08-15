#include "cpuvscpucontroller.h"

int main(int argc, char *argv[])
{
    CpuVsCpuController* controller = new CpuVsCpuController();

    controller->setCurrentPlayers(0,1);

    while(controller->is_in_tournament())
    {
        controller->doStep();
    }

    return 1;
}
