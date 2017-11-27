#include <stdio.h>
#include "map.h"

void printBool(boolean b);

int main(){
	int X, Y;
	POINT P;
	
	do{
		printf("Masukan Ukuran Peta(X,Y): ");
		scanf("%d",&X);
		scanf("%d",&Y);
		if ((X<8)||(Y<8)||(X>100)||(Y>100)){
			printf("Ukuran peta minimal 8x8 dan maksimal 100x100\n");
		}
	}while((X<8)||(Y<8)||(X>100)||(Y>100));
	
	InitMap(X,Y);
	int cX = M.NAbsisEff - 3;
	int cY = OrdMin + 1;
	UpdateUnitMap(MakePOINT(cX, cY), 2, 2);
	
	PrintMap();
	
	printf("castle (1,5) empty: "); printBool(IsCastleEmpty(1, 5));
	printf("King player 2 in tower: "); printBool(IsKingInTower(2));
	printf("IsPosisiTerkiri (0,0): "); printBool(IsPosisiTerkiri(MakePOINT(0,0)));
	printf("IsPosisiTerkiri (1,0): "); printBool(IsPosisiTerkiri(MakePOINT(1,0)));
	printf("IsPosisiTerkanan (0,7): "); printBool(IsPosisiTerkanan(MakePOINT(0,7)));
	printf("IsPosisiTerkanan (1,7): "); printBool(IsPosisiTerkanan(MakePOINT(1,7)));
	printf("IsPosisiTeratas (0,7): "); printBool(IsPosisiPalingAtas(MakePOINT(0,7)));
	printf("IsPosisiTeratas (0,4): "); printBool(IsPosisiPalingAtas(MakePOINT(0,4)));
	printf("IsPosisiTerbawah (7,7): "); printBool(IsPosisiPalingBawah(MakePOINT(7,7)));
	printf("IsPosisiTerkanan (7,3): "); printBool(IsPosisiPalingBawah(MakePOINT(7,3)));

	
	P = getKingPoint(1);
	printf("Posisi King player 1: (%d, %d)\n", Absis(P), Ordinat(P));
	
	printf("IsCastleEmpty(%d, %d) : ", cX, cY); printBool(IsCastleEmpty(cX, cY));
	printf("IsNoUnit in (%d,%d): ", cX,cY); printBool(IsNoUnit(cX, cY));
	printf("(3, 11) ada di Map: "); printBool(IsPointInMap(3, 11));
	printf("(1, 1) ada di Map: "); printBool(IsPointInMap(1, 1));
	
	P = getTowerPoint(2);
	printf("Point tower player 2: (%d, %d)\n\n", Absis(P),Ordinat(P)); 

	return 0;
}

void printBool(boolean b){
	if(b){
		printf("true\n");
	}else{
		printf("false\n");
	}
}
