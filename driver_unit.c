#include "unit.h"
#include "boolean.h"
#include "point.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
	Unit W, S;
	CreateWhiteMage(&W);
	//printf("Max Health: %d\n", (A).max_health);
	//(A).health-=220;
	//printf("Health: %d\n", (A).health);
	CreateSwordsman(&S);
	printf("Swordsman Health: %d\n", (S).health);
	printf("White Mage Health: %d\n", (W).health);
	printf("White Mage attack: %d\n", (W).attack);
	Attack(W, &S);
	printf("Swordsman Health: %d\n", (S).health);
	printf("Swordsman Attack: %d\n", (S).attack);
	Retaliate(S, &W);
	printf("White Mage Health: %d\n", (W).health);
	return 0;
}