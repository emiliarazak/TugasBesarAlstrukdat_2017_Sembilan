/*File unit.c/
/By: Emilia Andari Razak/13515056*/
/*Last updated: 16-11-2017 19:21 */

#include "boolean.h"
#include "point.h"
#include "unit.h"
#include "player.h"
#include "map.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*Create Unit*/
/*Create King, Inisialisasi semua attribute dengan attribute
yang dimiliki King*/
void CreateKing(Unit *k) {
	Unit K;

	K.id=1;
	K.max_health=1000;
	K.health=K.max_health;
	K.attack=100;
	K.heal=0;
	K.max_mov_points=5;
	K.mov_points=K.max_mov_points;
	K.atk_type=1;
	K.atk_chance=true;
	POINT P;
	P=MakePOINT(0,0);
	K.location=P;
	K.evasion=0.1;
	K.recruitment_price=0;
	K.upkeep_price=0;

	*k=K;
}

/*Create Archer, Inisialisasi semua attribute dengan attribute
yang dimiliki Archer*/
void CreateArcher(Unit *a) {
	Unit A;

	A.id=2;
	A.max_health=500;
	A.health=A.max_health;
	A.attack=200;
	A.heal=0;
	A.max_mov_points=3;
	A.mov_points=A.max_mov_points;
	A.atk_type=2;
	A.atk_chance=true;
	POINT P;
	P=MakePOINT(0,0);
	A.location=P;
	A.evasion=0.6;
	A.recruitment_price=250;
	A.upkeep_price=25;

	*a=A;
}

/*Create Swordsman, Inisialisasi semua attribute dengan attribute
yang dimiliki Swordsman*/
void CreateSwordsman(Unit *s) {
	Unit S;

	S.id=3;
	S.max_health=800;
	S.health=S.max_health;
	S.attack=300;
	S.heal=0;
	S.max_mov_points=4;
	S.mov_points=S.max_mov_points;
	S.atk_type=1;
	S.atk_chance=true;
	POINT P;
	P=MakePOINT(0,0);
	S.location=P;
	S.evasion=0.2;
	S.recruitment_price=200;
	S.upkeep_price=20;

	*s=S;
}

/*Create WhiteMage, Inisialisasi semua attribute dengan attribute
yang dimiliki WhiteMage*/
void CreateWhiteMage(Unit *w) {
	Unit W;

	W.id=4;
	W.max_health=500;
	W.health=W.max_health;
	W.attack=100;
	W.heal=400;
	W.max_mov_points=5;
	W.mov_points=W.max_mov_points;
	W.atk_type=1;
	W.atk_chance=true;
	POINT P;
	P=MakePOINT(0,0);
	W.location=P;
	W.evasion=0.1;
	W.recruitment_price=400;
	W.upkeep_price=40;

	*w=W;

}

/*Mengirimkan kondisi kematian Unit X*/
boolean IsDead(Unit X) {
	return ((X).health==0);
}

/*Mengirimkan kondisi kesempatan menyerang Unit X*/
boolean CanAttack(Unit X) {
	return ((X).atk_chance);
}

/*Menentukan letak unit*/
void SetLocation(Unit *X, int x, int y) {
	POINT P;
	P=MakePOINT(x,y);
	(*X).location=P;
}

/*Mengembalikan lokasi Unit X*/
POINT GetLocation(Unit X) {
	return (X.location);
}

/*Mengembalikan upkeep price Unit X*/
int GetUpKeepPrice(Unit X) {
	return ((X).upkeep_price);
}

/*Mengembalikan recruitment price Unit X*/
int GetRecruitmentPrice(Unit X) {
	return ((X).recruitment_price);
}

/*Memindahkan unit ke suatu koordinat*/
/*Prekondisi: final_coordinate terdefinisi*/
void MoveUnit(Unit *X, POINT final_coordinate) {
	POINT P;
	P=(*X).location;

	int jarakX, jarakY, jarak;
	jarakX=Absis(final_coordinate)-Absis(P);
	if(jarakX<0){
		jarakX=-jarakX;
	}
	jarakY=Ordinat(final_coordinate)-Ordinat(P);
	if(jarakY<0){
		jarakY=-jarakY;
	}
	jarak=jarakX+jarakY;

	if((*X).mov_points-jarak>=0){
		SetLocation(X,Absis(final_coordinate),Ordinat(final_coordinate));
	}
}

/*Unit X melakukan serangan terhadap unit Y*/
/*Implementasi probabilitas*/
/*Prekondisi: Adjacent*/
void Attack(Unit *X, Unit *Y) {
	if(CanAttack(*X)){
		int r;
		srand(time(NULL));
		/* random int between 1 and 10 */
		r = rand()%10+1;
		int chance = (*Y).evasion*10;
		chance = 10-chance;
		if(r<=chance){
			(*Y).health -= (*X).attack;
			if((*X).id==1){
				printf("King has dealt %d damage!\n", (*X).attack);
			}
			else if((*X).id==2){
				printf("Archer has dealt %d damage!\n", (*X).attack);
			}
			else if((*X).id==3){
				printf("Swordsman has dealt %d damage!\n", (*X).attack);
			}
			else if((*X).id==4){
				printf("White Mage has dealt %d damage!\n", (*X).attack);
			}
		}
		else{
			if((*X).id==1){
				printf("King's attack missed!\n");
			}
			else if((*X).id==2){
				printf("Archer's attack missed!\n");
			}
			else if((*X).id==3){
				printf("Swordman's attack missed!\n");
			}
			else if((*X).id==4){
				printf("White Mage's attack missed!\n");
			}
		}
		(*X).atk_chance = false;
		//printf("r: %d\n", r);
		//printf("chance: %d\n", chance);
	}

}

/*Unit X melakukan retaliation terhadap unit Y*/
/*Implementasi probabilitas*/
/*Prekondisi: Adjacent*/
void Retaliate(Unit X, Unit *Y) {
	if(!IsDead(X)){
		if((X).id == 1){
			int r;
			srand(time(NULL));
			/* random int between 1 and 10 */
			r = rand()%10+1;
			int chance = (*Y).evasion*10;
			chance = 10-chance;
			if(r <= chance){
				(*Y).health -= X.attack;
				printf("King returns %d damage!\n", X.attack);
			}
			else{
				printf("King's retaliation missed!\n");
			}
			//printf("r: %d\n", r);
			//printf("chance: %d\n", chance);
		}
		else{
			if((X).atk_type == (*Y).atk_type){
				int r;
				srand(time(NULL));
				/* random int between 1 and 10 */
				r = rand()%10+1;
				int chance = (*Y).evasion*10;
				chance = 10-chance;
				if(r <= chance){
					(*Y).health -= X.attack;
					if(X.id==2){
						printf("Archer returns %d damage!\n", X.attack);
					}
					else if(X.id==3){
						printf("Swordsman returns %d damage!\n", X.attack);
					}
					else if(X.id==4){
						printf("White Mage returns %d damage!\n", X.attack);
					}
				}
				else{
					if(X.id==2){
						printf("Archer's retaliation missed!\n");
					}
					else if(X.id==3){
						printf("Swordsman's retaliation missed!\n");
					}
					else if(X.id==4){
						printf("White Mage's retaliation missed!\n");
					}
				}
				//printf("r: %d\n", r);
				//printf("chance: %d\n", chance);
			}
		}

	}
}

/*Unit X melakukan heal terhadap unit Y*/
/*Prekondisi: Adjacent*/
void Heal(Unit X, Unit *Y) {
	if((X).id==4){
		(*Y).health+=(X).heal;
		if((*Y).health>(*Y).max_health){
			(*Y).health=(*Y).max_health;
		}
	}
}

/*Print attribute: lokasi, health/maxhealth, movement points, can_attack*/
void PrintUnit(Unit X) {
	printf("Unit: ");
	if((X).id==1){
		printf("King ");
	}
	else if((X).id==2){
		printf("Archer ");
	}
	else if((X).id==3){
		printf("Swordsman ");
	}
	else if((X).id==4){
		printf("White Mage ");
	}

	printf("(%d,%d)", Absis(GetLocation(X)), Ordinat(GetLocation(X)));
	printf(" | ");
	printf("Health ");
	printf("%d/%d", (X).health, (X).max_health);
	printf(" | ");
	printf("Movement Point: ");
	printf("%d", (X).mov_points);
	printf(" | ");
	printf("Can Attack: ");
	if(CanAttack(X)){
		printf("Yes");
	}
	else{
		printf("No");
	}
}
