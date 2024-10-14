#include "supemon.h"

int main()
{
    struct Player Player;
    Player.selectedSupemon = 0;
    Player.nbSupecoins = 0;
    Player.nbSupemon = 0;
    launchGame(&Player);
    affichageMenu(&Player);
    return 0;
}
