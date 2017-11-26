#ifndef __COMMAND_H__
#define __COMMAND_H__

#include "mesinkata.h"
#include "player.h"
#include "queue.h"

/*extern Kata ComStart;
extern Kata ComLoad;
extern Kata ComMove;
extern Kata ComUndo;
extern Kata ComChange_Unit;
extern Kata ComRecruit;
extern Kata ComAttack;
extern Kata ComMap;
extern Kata ComInfo;
extern Kata ComEnd_Turn;
extern Kata ComSave;
extern Kata ComExit;*/
void StartGame();

void openingturn ();

void execute ();

void initialkata();

void startcommand();

void readcommand();

void AttackAndRetaliate(Player *P1, Player *P2);

void PrintListEnemy (ListU L, int *choice);

int winningcheck();

void HealPlayer(Player *P);

#endif
