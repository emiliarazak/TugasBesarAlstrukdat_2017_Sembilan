/*File unit.h/
/By: Emilia Andari Razak/13515056*/
/*Last updated: 08-11-2017 11:00*/

#ifndef unit_H
#define unit_H

#include "boolean.h"
#include "point.h"

/*Definisi Tipe Data*/
typedef struct {
	const int id;
	/*	id==1: King
		id==2: Archer
		id==3: Swordsman
		id==4: White Mage*/
	const int max_health;
	int health;
	int attack;
	const int max_mov_points;
	int mov_points;
	const int atk_type;
	/* 	atk_type==1 : melee
		atk_type==2	: ranged*/
	boolean atk_chance;
	//Point location;
	const int recruitment_price;
}Unit;

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

/*Memindahkan unit ke suatu koordinat*/
void MoveUnit(Unit *X, Point final_coordinate);

/*Unit X melakukan serangan terhadap unit Y*/
/*Implementasi probabilitas*/
void Attack(Unit *X, Unit *Y);

/*Unit X melakukan retaliation terhadap unit Y*/
/*Implementasi probabilitas*/
void Retaliate(Unit *X, Unit *Y);
#endif