#include <stdio.h>
#include "player.h"
#include "unit.h"

void CreatePlayer (Player *P, char color)
{
    Unit k;
    Gold(*P)= 5000;
    CreateEmptyUnit(&Units(*P));
    CreateKing(&k);
    First(Units(*P))=Alokasi1(k);
    CreateEmptyProperty(&Villages(*P));
    Income(*P)=0;
    UpKeep(*P)=0;
    Warna(*P)=color;
    L
}

void PrintAttribute (Pemain P)
{
    printf ("Cash: %dG | Income: %dG | Upkeep: %dG\n", Gold(P),Income(P),UpKeep(P));
}

