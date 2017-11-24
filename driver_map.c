#include <stdio.h>
#include "map.h"

void printBool(boolean b);

int main(){
	int N, M, X, Y;
	POINT P;
	do{
		printf("Masukan Ukuran Peta(X,Y): ");
		scanf("%d",&N);
		scanf("%d",&M);
		if ((N<8)||(M<8)||(N>100)||(M>100))
		{
			printf("Ukuran peta minimal 8x8 dan maksimal 100x100\n");
		}
	} 
	while((N<8)||(M<8)||(N>100)||(M>100));
	InitMap(N,M);
	PrintMap();
	
	printf("castle (1,5) empty: "); printBool(IsCastleEmpty(1, 5));
	printf("King in tower: "); printBool(IsKingInTower(2));
	printf("IsPosisiUjung (0,0): "); printBool(IsPosisiUjung(MakePOINT(0,0)));
	printf("IsPosisiUjung (0,7): "); printBool(IsPosisiUjung(MakePOINT(0,7)));
	printf("IsPosisiUjung (7,0): "); printBool(IsPosisiUjung(MakePOINT(7,0)));
	printf("IsPosisiUjung (7,7): "); printBool(IsPosisiUjung(MakePOINT(7,7)));
	printf("IsPosisiTerkiri (0,0): "); printBool(IsPosisiTerkiri(MakePOINT(0,0)));
	printf("IsPosisiTerkiri (1,0): "); printBool(IsPosisiTerkiri(MakePOINT(1,0)));
	printf("IsPosisiTerkanan (0,7): "); printBool(IsPosisiTerkanan(MakePOINT(0,7)));
	printf("IsPosisiTerkanan (1,7): "); printBool(IsPosisiTerkanan(MakePOINT(1,7)));
	printf("IsPosisiTeratas (0,7): "); printBool(IsPosisiPalingAtas(MakePOINT(0,7)));
	printf("IsPosisiTeratas (0,4): "); printBool(IsPosisiPalingAtas(MakePOINT(0,4)));
	printf("IsPosisiTerbawah (7,7): "); printBool(IsPosisiPalingBawah(MakePOINT(7,7)));
	printf("IsPosisiTerkanan (7,3): "); printBool(IsPosisiPalingBawah(MakePOINT(7,3)));
	
	return 0;
}

void printBool(boolean b){
	if(b){
		printf("true\n");
	}else{
		printf("false\n");
	}
}
