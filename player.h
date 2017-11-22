#ifndef player_H
#define player_H

#include "boolean.h"
#include "listunit.h"
#include "listpoint.h"
#include "map.h"
#include "queue.h"
#include "stacklist.h"

typedef struct
{
	int id ;
    int gold;
    ListU units;
    ListP villages;
    ListP castle;
    POINT tower;
    int income;
    int upKeep;
    Unit current_unit;
} Player;

extern Stack S;

#define Id(P) (P).id
#define Gold(P) (P).gold
#define Units(P) (P).units
#define Villages(P) (P).villages
#define Income(P) (P).income
#define UpKeep(P) (P).upKeep
#define CurrentUnit(P) (P).current_unit
void CreatePlayer (Player *P);
/* Membuat pemain baru pada saat awal permainan, dengan identitas warna adalah color */

void PrintAttribute (Player P);
/* Mencetak attribute gold, income, dan upkeep suatu pemain */

void GenerateUpkeep(Player *P);
/* menghitung jumlah upkeep saat ini */

void PrintCurrentUnit(Player P);
/* print unit yang sedang dipilih */

void Recruit (Player *P);
/* Command recruit */
/*Prekondisi: King sedang berada pada tower*/

void ChangeUnit(Player *P);
/* Menampilkan secara rinci unit yang dimiliki pemain dan pemain dapat memilih unit */

void Move(Player *P, Map M);
/* Melakukan move terhadap current unit */

void Undo(Player *P);
/* Melakukan undo terhadap posisi current unit */

void InfoMap(Map M);
/* Prosedur ini untuk menampilkan info yang ada pada sebuah petak */

void CreateTurn (Queue *QTurn, Player P1, Player P2);
/* Prosedur ini untuk membuat sebuah giliran antara 2 pemain */

Player CurrentTurn (Queue QTurn);
/* Prosedur ini untuk mengembalikan player mana yang saat ini mendapat giliran bermain */ 

void EndTurn (Queue QTurn);
/* Prosedur ini untuk melakukan pergantian giliran antar pemain */
#endif