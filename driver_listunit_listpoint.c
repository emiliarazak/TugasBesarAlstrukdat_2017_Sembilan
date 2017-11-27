/* Driver List */

#include <stdio.h>
#include <stdlib.h>
#include "listunit.h"
#include "listpoint.h"
#include "unit.h"
#include "point.h"

int main (){
/* Kamus */
	POINT P1, P2, Pdel ;
	Unit U1, U2 ;
	addressP Ap, Ap2;
	ListP LP ;
	ListU LU ;
/* Algoritma */
	printf("TESTING LIST POINT\n");
	Absis(P1) = 1;
	Ordinat(P1) = 2;
	Absis(P2) = 3;
	Ordinat(P2) = 4 ;
	CreateEmptyP(&LP);

	printf("\n");
	printf("Ins V First : \n");
	InsVFirstP(&LP,P1);
	PrintListP(LP);
	
	printf("\n");
	printf("Ins V Last : \n");
	InsVLastP(&LP,P2);
	PrintListP(LP);

	printf("\n");
	printf("Del V First :\n");
	DelVFirstP(&LP,&Pdel);
	PrintListP(LP);
	printf("\n");
	printf("Absis di hapus : %d , Ordinat di hapus : %d\n", Absis(Pdel), Ordinat(Pdel));

	printf("\n");
	printf("Del V Last :\n");
	DelVFirstP(&LP,&Pdel);
	PrintListP(LP);
	printf("\n");
	printf("Absis di hapus : %d , Ordinat di hapus : %d\n", Absis(Pdel), Ordinat(Pdel));

	CreateEmptyU(&LU);
	PrintListU(LU);
	CreateArcher(&U1);
	InsVLastU(&LU,U1);
	
	CreateSwordsman(&U2);
	InsVLastU(&LU,U2);
	PrintListU(LU);

	return 0;
}