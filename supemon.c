#include "supemon.h"

void printa(wchar_t texte[]) {
    _setmode(_fileno(stdout), _O_WTEXT);
    wprintf(L"%ls", texte);
    _setmode(_fileno(stdout), _O_TEXT);
}

int launchGame(struct Player* Player)
{
    printf("\n");
    printa(L"███████╗ ██╗   ██╗ ██████╗  ███████╗ ███╗   ███╗  ██████╗  ███╗   ██╗\n");
    printa(L"██╔════╝ ██║   ██║ ██╔══██╗ ██╔════╝ ████╗ ████║ ██╔═══██╗ ████╗  ██║\n");
    printa(L"███████╗ ██║   ██║ ██████╔╝ █████╗   ██╔████╔██║ ██║   ██║ ██╔██╗ ██║\n");
    printa(L"╚════██║ ██║   ██║ ██╔═══╝  ██╔══╝   ██║╚██╔╝██║ ██║   ██║ ██║╚██╗██║\n");
    printa(L"███████║ ╚██████╔╝ ██║      ███████╗ ██║ ╚═╝ ██║ ╚██████╔╝ ██║ ╚████║\n");
    printa(L"╚══════╝  ╚═════╝  ╚═╝      ╚══════╝ ╚═╝     ╚═╝  ╚═════╝  ╚═╝  ╚═══╝\n\n");

    printa(L"Hello there! Welcome to the world of Supémon! !My name is Laurent People call me the Supémon Prof!\nThis world is inhabited by creatures called Supémon! For some people, Supémon are pets.\nOther use them for fights. Myself… I study Supémon as a profession.\n\nFirst, what is your name?\nYour name :");
    scanf("%s", &Player->name);
    printf("Right! So your name is %s!\n\nLook, this is my grandson. He's been your rival since you were a baby.\n", Player->name);
    printa(L"…Erm, what is his name again?\nHis name :");
    scanf("%s", &Player->rivalName);
    printf("That's right! I remember now! His name is %s!\n\n%s! ", Player->rivalName, Player->name);
    printa(L"Your very own Supémon legend is about to unfold!\nA world of dreams and adventures with Supémon awaits! Let's go!\n\n");

    affichageStarterSupemon(Player);
}

void affichageStarterSupemon(struct Player* Player) {
    printf("+------------------------------+\n");
    printa(L"| Choose your starter Supémon: |\n");
    printf("|      1 - Supmander           |\n");
    printf("|      2 - Supasaur            |\n");
    printf("|      3 - Supirtle            |\n");
    printf("+------------------------------+\n");
    printf("1, 2 or 3 :");
    scanf("%d", &Player->lastChoice);
    fflush(stdin);
    printf("\n");
    selectStarterSupemon(Player);
}

void selectStarterSupemon(struct Player* Player) {
    switch (Player->lastChoice) {
    case 1:
        createSupemon(Player, 1);
        break;
    case 2:
        createSupemon(Player, 2);
        break;
    case 3:
        createSupemon(Player, 3);
        break;
    default:
        printf("You chose nothing! Please retry.\n\n");
        affichageStarterSupemon(Player);
        break;
    }
}

void createSupemon(struct Player* Player, int iSupemon)
{
    struct Supemon Supemon;
    Supemon.level = 1;
    Supemon.exp = 0;
    switch (iSupemon) {
    case 1:
        strcpy(Supemon.name, "Supmander");
        Supemon.maxHp = 10;
        Supemon.hp = Supemon.maxHp;
        Supemon.baseAtk = 1;
        Supemon.atk = Supemon.baseAtk;
        Supemon.baseDef = 1;
        Supemon.def = Supemon.baseDef;
        Supemon.baseEvasion = 1;
        Supemon.evasion = Supemon.baseEvasion;
        Supemon.baseAccuracy = 2;
        Supemon.accuracy = Supemon.baseAccuracy;
        Supemon.speed = 1;
        break;
    case 2:
        strcpy(Supemon.name, "Supasur");
        Supemon.maxHp = 9;
        Supemon.hp = Supemon.maxHp;
        Supemon.baseAtk = 1;
        Supemon.atk = Supemon.baseAtk;
        Supemon.baseDef = 1;
        Supemon.def = Supemon.baseDef;
        Supemon.baseEvasion = 3;
        Supemon.evasion = Supemon.baseEvasion;
        Supemon.baseAccuracy = 2;
        Supemon.accuracy = Supemon.baseAccuracy;
        Supemon.speed = 2;
        break;
    case 3:
        strcpy(Supemon.name, "Supirtle");
        Supemon.maxHp = 11;
        Supemon.hp = Supemon.maxHp;
        Supemon.baseAtk = 1;
        Supemon.atk = Supemon.baseAtk;
        Supemon.baseDef = 2;
        Supemon.def = Supemon.baseDef;
        Supemon.baseEvasion = 2;
        Supemon.evasion = Supemon.baseEvasion;
        Supemon.baseAccuracy = 1;
        Supemon.accuracy = Supemon.baseAccuracy;
        Supemon.speed = 2;
        break;
    default:
        printf("Erreur");
    }
    Player->supTeam[Player->nbSupemon] = Supemon;
    Player->nbSupemon++;
    printf("Congratulations! %s has joined your team!\n\n", Supemon.name);
}

void affichageMenu(struct Player* Player)
{
    printf("+------------------------------+\n");
    printf("|  Where do you want to go ?   |\n");
    printf("|     1 - Into the Wild        |\n");
    printf("|     2 - In the shop          |\n");
    printa(L"|     3 - In the Supémon Center|\n");
    printf("|     4 - Leave the Game       |\n");
    printf("+------------------------------+\n");
    printf("1, 2 3 or 4 :");
    scanf("%d", &Player->lastChoice);
    fflush(stdin);
    printf("\n");
    selectMenu(Player);
}

void selectMenu(struct Player* Player) {
    switch (Player->lastChoice) {
    case 1:
        printf("You chose to go into the wild!\n");
        break;
    case 2:
        printf("You chose to go in the shop!\n");
        break;
    case 3:
        printf("You chose to go in the Supémon Center!\n");
        break;
    case 4:
        printf("You chose to leave the game!\n");
        break;
    default:
        printf("You chose nothing! Please retry.\n\n");
        affichageMenu(Player);
        break;
    }
}

int checkTeam(struct Player* Player) {
    if (Player->nbSupemon < MAX_TEAM) {
        return 1;
    }
    else {
        printf("Your team is full! You cannot add a new one.\n");
        return 0;
    }
}
