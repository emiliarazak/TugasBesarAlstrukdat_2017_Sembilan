#ifndef player_H
#define player_H

#include "boolean.h"
#include "listunit.h"
#include "listpoint.h"

typedef struct
{
    int gold;
    ListU units;
    ListP villages;
    ListP castle;
    POINT tower;
    int income;
    int upKeep;
    char warna;
    Unit current_unit;
} Player;

#define Gold(P) (P).gold
#define Units(P) (P).units
#define Villages(P) (P).villages
#define Income(P) (P).income
#define UpKeep(P) (P).upKeep
#define Warna(P) (P).warna
#define CurrentUnit(P) (P).current_unit
void CreatePlayer (Player *P, char Warna);
//Membuat pemain baru pada saat awal permainan, dengan identitas warna adalah color

void PrintAttribute (Player P);
//Mencetak attribute gold, income, dan upkeep suatu pemain

void GenerateUpkeep(Player *P);
//menghitung jumlah upkeep saat ini

void PrintCurrentUnit(Player P);
//print unit yang sedang dipilih

void Recruit (Player *P);
//Command recruit
/*Prekondisi: King sedang berada pada tower*/

void ChangeUnit(Player *P);
//Menampilkan secara rinci unit yang dimiliki pemain dan pemain dapat memilih unit

void Move(Player *P);
//Melakukan move terhadap current unit
#endif