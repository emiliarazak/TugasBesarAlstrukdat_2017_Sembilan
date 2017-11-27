#ifndef player_H
#define player_H

#include "boolean.h"
#include "unit.h"
#include "listunit.h"
#include "listpoint.h"
#include "map.h"
#include "stacklist.h"

typedef struct
{
    int id;
	int gold;
    ListU units;
    ListP villages;
    ListP castle;
    POINT tower;
	int income;
	int upKeep;
    Unit current_unit;
} Player;

#define Id(P) (P).id
#define Gold(P) (P).gold
#define Units(P) (P).units
#define Villages(P) (P).villages
#define Income(P) (P).income
#define UpKeep(P) (P).upKeep
#define CurrentUnit(P) (P).current_unit

void CreatePlayer (Player *P,int id);
/* Membuat pemain baru pada saat awal permainan, dengan identitas id */
void PrintAttribute (Player P);
/* Mencetak attribute gold, income, dan upkeep suatu pemain */
void GenerateUpkeep(Player *P);
/* menghitung jumlah upkeep saat ini */
void GenerateIncome(Player *P);
/* menghitung jumlah income saat ini */
void PrintCurrentUnit(Player P);
/* print unit yang sedang dipilih */
void Recruit (Player *P);
//Command recruit
/*Prekondisi: King sedang berada pada tower*/
void ChangeUnit(Player *P);
/* Menampilkan secara rinci unit yang dimiliki pemain dan pemain dapat memilih unit */
void Move(Player *P);
/* Melakukan move terhadap current unit */
void Undo(Player *P);
/* Melakukan undo terhadap posisi current unit */
void InfoMap();
/* Menampilkan info yang ada pada sebuah petak */
void AkuisisiVillage(Player *P, POINT Loc);
/* Mengakuisisi village */
void NextUnit(Player *P);
/* Mencari next unit yang masih memiliki movement points atau chance attack */
void RecoverGoldMove (Player *P);
/* Mengembalikan nilai movement points dan mengupdate nilai gold */
#endif
