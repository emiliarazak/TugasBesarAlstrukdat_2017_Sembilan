/* Driver Queue */
#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "queue.h"
#include "map.h"
#include "pcolor.h"
#include "point.h"
#include "unit.h"
#include "stacklist.h"
#include "listpoint.h"
#include "listunit.h"

int main(){
/* Kamus */
	Queue QTurn ;
	Player P1, P2 ;

/* Algoritma */
	CreatePlayer(&P1,1);
	CreatePlayer(&P2,2);
	CreateEmptyQ(&QTurn,2);
	AddQ(&QTurn,P1);
	AddQ(&QTurn,P2);
	printf("Current Turn Id: %d\n", Id(InfoHead(QTurn)));
	printf("Enemy Id: %d\n", Id(InfoTail(QTurn)));
	/* End Turn Tanpa Update Giliran Map */
	Player temp;
    DelQ(&QTurn,&temp);
    addressU U = FirstU(Units(P1));
    while (U!=Nil){
        InfoU(U).mov_points = InfoU(U).max_mov_points;
        InfoU(U).atk_chance = true; 
        U = NextU(U);
    }
    //UpdateGiliranUnitMap(CurrentUnit(*P).location,false);
            AddQ(&QTurn,temp);

	printf("Current Turn Id: %d\n", Id(InfoHead(QTurn)));
	printf("Enemy Id: %d\n", Id(InfoTail(QTurn)));

	return 0;
}