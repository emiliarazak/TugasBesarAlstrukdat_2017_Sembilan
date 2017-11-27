#include "stacklist.h"
#include <stdio.h>
#include "point.h"

//cara compile: gcc -o driver_stacklist driver_stacklist.c stacklist.c point.c
int main() {
	Stack Sl;

	CreateEmpty(&Sl);
	if(IsEmpty(Sl)){
		printf("Create Empty berhasil\n");
	}
	printf("\n");
	printf("Masukkan elemen(poin) yang ingin dimasukkan ke stack: ");
	int X, Y;
	scanf("%d %d", &X, &Y);
	POINT poin;
	poin=MakePOINT(X,Y);
	address P;
	Alokasi(&P, poin);
	if(P!=Nil){
		printf("Alokasi berhasil\n");
		Push(&Sl, poin);
		printf("Hasil pop: ");
		POINT pop;
		Pop(&Sl, &pop);
		TulisPOINT(pop);
		printf("\n");
	}
	return 0;
}