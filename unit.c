/*File unit.c/
/By: Emilia Andari Razak/13515056*/
/*Last updated: 10-11-2017 08:52 */

#include "boolean.h"
#include "point.h"

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
	return (X.health==0);
}

/*Mengirimkan kondisi kesempatan menyerang Unit X*/
boolean CanAttack(Unit X) {
	return (X.atk_chance);
}

/*Menentukan letak unit*/
void SetLocation(Unit *X, float x, float y);

/*Mengembalikan lokasi Unit X*/
POINT GetLocation(Unit X);

/*Memindahkan unit ke suatu koordinat*/
void MoveUnit(Unit *X, Point final_coordinate);

/*Unit X melakukan serangan terhadap unit Y*/
/*Implementasi probabilitas*/
void Attack(Unit *X, Unit *Y);

/*Unit X melakukan retaliation terhadap unit Y*/
/*Implementasi probabilitas*/
void Retaliate(Unit *X, Unit *Y);

/*Unit X melakukan heal terhadap unit Y*/
/*Prekondisi: Adjacent, hanya bisa dilakukan oleh white mage id=4*/
void Heal(Unit X, Unit *Y);
