#ifndef player_H
#define player_H

#include "boolean.h"
#include "listdp.h"

typedef struct
{
    int gold;
    List units;
    List villages;
    List castle;
    point tower;
    int income;
    int upKeep;
    char warna;
} Player;

#define Gold(P) (P).gold
#define Units(P) (P).units
#define Villages(P) (P).villages
#define Income(P) (P).income
#define UpKeep(P) (P).upKeep
#define Warna(P) (P).warna

void CreatePlayer (Player *P, char Warna);
//Membuat pemain baru pada saat awal permainan, dengan identitas warna adalah color

void PrintAttribute (Player P);
//Mencetak attribute gold, income, dan upkeep suatu pemain

#endif
