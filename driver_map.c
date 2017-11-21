#include <stdio.h>
#include "map.h"

int main(){
	int N,M;
	do{
		printf("Masukan Ukuran Peta(X,Y): ");
		scanf("%d",&N);
		scanf("%d",&M);
		if ((N<8)||(M<8)||(N>20)||(M>20))
		{
			printf("Ukuran peta minimal 8x8 dan maksimal 20x20\n");
		}
	} 
	while((N<8)||(M<8)||(N>20)||(M>20));
	InitMap(N,M);
	PrintMap();
	return 0;
}
