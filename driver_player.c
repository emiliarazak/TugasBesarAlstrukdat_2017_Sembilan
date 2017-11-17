#include "player.h"
#include "unit.h"
#include "boolean.h"
#include <stdio.h>

int main() {
	printf("Player 1's turn");
	Player P1;
	CreatePlayer(&P1, 'r');
	GenerateUpkeep(&P1);
	PrintAttribute(P1);
	PrintCurrentUnit(P1);

	string input;
	do{
		printf("Your input: ");
		scanf("%s", input);
		if(input=="RECRUIT"){
			Recruit(&P1);
		}
		else if(input=="CHANGE_UNIT"){
			ChangeUnit(&P1);
		}
		else if(input=="MOVE"){
			Move(&P1);
		}
	}while(input!="end");
	
	return 0;
}