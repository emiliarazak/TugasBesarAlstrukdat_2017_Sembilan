#include <stdio.h>
#include "listunit.h"
#include "unit.h"
#include "point.h"
#include "math.h"
int main(){
	ListU Lu ;
	Unit A, S ;
	CreateEmptyU(&Lu);
	PrintListU(Lu);
	CreateArcher(&A);
	InsVLastU(&Lu,A);
	CreateSwordsman(&S);
	InsVLastU(&Lu,S);
	PrintListU(Lu);
}