/*File unit.h/
/By: Emilia Andari Razak/13515056*/
/*Last updated: 16-11-2017 19:21*/

#ifndef unit_H
#define unit_H

#include "boolean.h"
#include "point.h"

/*Definisi Tipe Data*/
typedef struct {
	int id;
	/*	id==1: King
		id==2: Archer
		id==3: Swordsman
		id==4: White Mage*/
	int max_health;
	int health;
	/*damage*/
	int attack;
	/*selain white mage bernilai 0*/
	int heal;
	int max_mov_points;
	int mov_points;
	int atk_type;
	/* 	atk_type==1 : melee
		atk_type==2	: ranged*/
	boolean atk_chance;
	POINT location;
	/*Untuk implementasi probabilitas serangan, evasion=kemungkinan menghindar*/
	float evasion;
	int recruitment_price;
	int upkeep_price;
} Unit;


/*Create Unit*/
/*Create King, Inisialisasi semua attribute dengan attribute
yang dimiliki King*/
void CreateKing(Unit *k);

/*Create Archer, Inisialisasi semua attribute dengan attribute
yang dimiliki Archer*/
void CreateArcher(Unit *a);

/*Create Swordsman, Inisialisasi semua attribute dengan attribute
yang dimiliki Swordsman*/
void CreateSwordsman(Unit *s);

/*Create WhiteMage, Inisialisasi semua attribute dengan attribute
yang dimiliki WhiteMage*/
void CreateWhiteMage(Unit *w);

/*Mengirimkan kondisi kematian Unit X*/
boolean IsDead(Unit X);

/*Mengirimkan kondisi kesempatan menyerang Unit X*/
boolean CanAttack(Unit X);

/*Menentukan letak unit*/
void SetLocation(Unit *X, int x, int y);

/*Mengembalikan lokasi Unit X*/
POINT GetLocation(Unit X);

/*Mengembalikan upkeep price Unit X*/
int GetUpKeepPrice(Unit X);

/*Mengembalikan recruitment price Unit X*/
int GetRecruitmentPrice(Unit X);

/*Memindahkan unit ke suatu koordinat*/
/*Prekondisi: final_coordinate terdefinisi*/
void MoveUnit(Unit *X, POINT final_coordinate);

/*Unit X melakukan serangan terhadap unit Y*/
/*Implementasi probabilitas*/
/*Prekondisi: Adajcent*/
void Attack(Unit X, Unit *Y);

/*Unit X melakukan retaliation terhadap unit Y*/
/*Implementasi probabilitas*/
/*Prekondisi: Adajcent*/
void Retaliate(Unit X, Unit *Y);

/*Unit X melakukan heal terhadap unit Y*/
/*Prekondisi: Adjacent, hanya bisa dilakukan oleh white mage id=4*/
void Heal(Unit X, Unit *Y);

/*Print attribute: lokasi, health/maxhealth, movement points, can_attack*/
void PrintUnit(Unit X);
#endif
