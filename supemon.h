#ifndef SUPEMON_H_INCLUDED
#define SUPEMON_H_INCLUDED

#include <stdio.h>
#include <wchar.h>
#include <io.h>
#include <fcntl.h>
#define MAX_TEAM 5

struct Supemon {
    char name[50];
    int level;
    int exp;
    int maxHp;
    int hp;
    int baseAtk;
    int atk;
    int baseDef;
    int def;
    int baseEvasion;
    int evasion;
    int baseAccuracy;
    int accuracy;
    int speed;
    //list of moves
};

struct Player {
    char name[50];
    char rivalName[50];
    int nbSupemon;
    struct Supemon supTeam[0];
    int selectedSupemon;
    int nbSupecoins;
    //liste items
    int lastChoice;
};


// Prototypes
void printa(wchar_t texte[]);
int launchGame(struct Player* Player);
void affichageStarterSupemon(struct Player* Player);
void selectStarterSupemon(struct Player* Player);
void createSupemon(struct Player* Player, int iSupemon);
void affichageMenu(struct Player* Player);
void selectMenu(struct Player* Player);
int checkTeam(struct Player* Player);

#endif // SUPEMON_H_INCLUDED
