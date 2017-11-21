#include <stdio.h>
#include "map.h"

void setGameOver();
/* mengembalikan ke state awal */

void actionCommand();
/* menjalankan perintah dari inputan */

void refresh();
/* merefresh tampilan setelah ada command */

boolean new, load, gameOver;
	
int main(){
	int N,M;
	char * command;
	setGameOver();
	scanf("%s", command);
	if(command == "load"){
		
	}else if(command == "start"){
		do{
			printf("Insert the size of map (X, Y): ");
			scanf("%d",&N);
			scanf("%d",&M);
			if ((N<8)||(M<8)||(N>100)||(M>100)){
				printf("The minimum size is 8x8 and the maximum is 100x100\n");
			}
		} 
		while((N<8)||(M<8)||(N>100)||(M>100));
		InitMap(N,M);
		PrintMap();
		
		while(!gameOver){
			//baca input
			refresh();
		}
	}else{
		printf("You have to load or start a new game to play!\n");
	}
	
	return 0;
}

void setGameOver(){
	new = true;
	load = true;
	gameOver = false;
}

void refresh(){
}

void actionCommand(){
/* menjalankan perintah dari inputan */
	
}
