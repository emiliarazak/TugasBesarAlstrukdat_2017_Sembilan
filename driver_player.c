#include "player.h"
#include "unit.h"
#include "boolean.h"
#include <stdio.h>

int main() {
    Player P1;
	CreatePlayer(&P1,1);
	printf("\nAtribut Player :\n");
	PrintAttribute(P1);
	printf("\nCurrent Unit Player :\n");
	PrintCurrentUnit(P1);
	printf("\nMerekrut Unit :\n")
	Recruit(&P1);
	printf("\nMengganti Current Unit\n")
	ChangeUnit(&P1);
	return 0;
}
