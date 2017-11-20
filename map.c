/**
Filename: map.c (implementation of map.h)
Prepared by: Intan Nurjanah / 13516131
Created at: 16/11/2017
**/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Map.h"
#include "pcolor.h"

ElType getElmt(Map M, int x, int y){
/* Mengembalikan element dari di petak x dan y */	
	return M.Mem[x][y];
}

int getBangunanId(Map M, int x, int y){
/* Mengembalikan id bangunan di petak x dan y */
	return M.Mem[x][y].bangunan.id;
}

int getBangunanOwner(Map M, int x, int y){
/* Mengembalikan pemilik bangunan di petak x dan y */
	return M.Mem[x][y].bangunan.pemilik;
}

int getUnitId(Map M, int x, int y){
/* Mengembalikan id unit di petak x dan y */
	return M.Mem[x][y].unit.id;
}

int getUnitOwner(Map M, int x, int y){
/* Mengembalikan pemilik unit di petak x dan y */
	return M.Mem[x][y].unit.pemilik;
}

Map CreateEmptyMap(int X, int Y){
/* Membuat petak normal sebanyak X * Y */
	Map M;
	int i,j;
	
	AbsisEff(M) = X;
	OrdEff(M) = Y;
	for(i = AbsisMin; i < AbsisEff(M); i++){
		for(j = OrdMin; j < OrdEff(M); j++){
			UpdateBangunanMap(&M, MakePOINT(i, j), 0, 0);
			UpdateUnitMap(&M, MakePOINT(i, j), 0, 0);
		}
	}
	return M;
}

void InitMap(Map * M){
/* I.S: Ukuran Map terdefinisi */
/* Membuat Map untuk state awal permainan */	
	int cX, cY, i;
	
	/* buat kerajaan player 1, ujung kiri-bawah */
	cX = AbsisMin + 1;
	cY = OrdEff(*M) - 2;
	setBangunanKerajaan(M, cX, cY, 1);
	
	/* buat kerajaan player 2, ujung kanan-atas */
	cX = AbsisEff(*M) - 2;
	cY = OrdMin + 1;
	setBangunanKerajaan(M, cX, cY, 2);
	
	setVillage(M, OrdEff(*M) - 2);
}

Map LoadMapFromFile(){
/* I.S: file terdefinisi */	
	/* PrintMapWithTurn */
	
	
}

void PrintMap(Map M){
/* Mencetak Map secara keseluruhan */
	int i, j;
	printf("   ");
	for(j = OrdMin; j < OrdEff(M); j++){
		printf("  %d ", j); /* ordinat/kolom */
	} printf("\n");
	for(i = AbsisMin; i < AbsisEff(M); i++){
		printf("   ");
		for(j = OrdMin; j < OrdEff(M); j++){
			printf("****"); /* garis atas */
		} printf("*\n   * ");
		for(j = OrdMin; j < OrdEff(M); j++){ /* bangunan */
			printBangunan(getElmt(M, i, j).bangunan);
			printf(" * ");
		} printf("\n %d * ", i); /* absis/baris */
		for(j = OrdMin; j < OrdEff(M); j++){ /* unit */
			printUnit(getElmt(M, i, j).unit);
			printf(" * ");
		} printf("\n   *");
		for(j = OrdMin; j < OrdEff(M); j++){ /* space */
			printf("   *");
		}
		printf("\n");
	}printf("   ");
	for(j = OrdMin; j < OrdEff(M); j++){
		printf("****"); /* garis terbawah */
	} printf("*\n");
}

void printBangunan(BangunanMap bangunan){
/* Mencetak bangunan dengan warna tertentu */
	char b;
	b = getId(1, bangunan.id);
	switch(bangunan.pemilik){
		case 1: print_blue(b);
		case 2: print_red(b);
		default: printf("%c", b);
	}
}

void printUnit(UnitMap unit){
/* Mencetak unit dengan warna tertentu */	
	char b;
	b = getId(2, unit.id);
	if(unit.giliran){
		print_green(b);
	}else{
		switch(unit.pemilik){
			case 1: print_blue(b);
			case 2: print_red(b);
			default: printf("%c", b);
		}
	}
}

void UpdateUnitMap(Map * M, POINT P, int newId, int pemilik){
/* I.S: map sudah diinisialisasi */
/* x dan y adalah posisi absis dan ordinat yang baru */
/* newId adalah id unit yang baru */
/* isi dari newId: (1) King, (2) Archer, (3) Swordsman, (4) White Mage, (0) blank */
/* Mengubah posisi dari unit yang ada di map */
	(*M).Mem[Absis(P)][Ordinat(P)].unit.id = newId;
	(*M).Mem[Absis(P)][Ordinat(P)].unit.pemilik = pemilik;
}

void UpdateBangunanMap(Map * M, POINT P, int newId, int pemilik){
/* I.S: map sudah diinisialisasi */
/* x dan y adalah posisi absis dan ordinat yang baru */
/* newId adalah id bangunan yang baru */
/* isi dari newId: (1) Tower, (2) Castel, (3) Village, (0) blank */
/* Mengubah posisi dari bangunan yang ada di map */
	(*M).Mem[Absis(P)][Ordinat(P)].bangunan.id = newId;
	(*M).Mem[Absis(P)][Ordinat(P)].bangunan.pemilik = pemilik;
}

/*** Untuk keperluan move ***/
boolean IsPosisiTerkiri(Map M, POINT P){
/* Mengembalikan true bila posisi (x, _) ada di pinggir kiri map */
/* tapi bukan di ujung map */
	return (Ordinat(P) == OrdMin && !IsPosisiUjung(M, P));
}

boolean IsPosisiTerkanan(Map M, POINT P){
/* Mengembalikan true bila posisi (x, _) ada di pinggir kanan map */
/* tapi bukan di ujung map */
	return (Ordinat(P) == OrdEff(M) && !IsPosisiUjung(M, P));
}

boolean IsPosisiPalingAtas(Map M, POINT P){
/* Mengembalikan true bila posisi (_, y) ada di paling atas map */
/* tapi bukan di ujung map */
	return (Absis(P) == AbsisMin && !IsPosisiUjung(M, P));
}

boolean IsPosisiPalingBawah(Map M, POINT P){
/* Mengembalikan true bila posisi (_, y) ada di paling bawah map */
/* tapi bukan di ujung map */
	return (Absis(P) == AbsisEff(M) && !IsPosisiUjung(M, P));
}

boolean IsPosisiUjung(Map M, POINT P){
/* Mengembalikan true bila posisi (x, y) ada di ujung map */
	return ((Absis(P) == AbsisMin || Absis(P) == AbsisEff(M)) && 
		(Ordinat(P) == OrdMin || Ordinat(P) == OrdEff(M)));
}

POINT * getCastle(Map M, int id){
/* Mengembalikan castle yang dimiliki oleh player dengan id tertentu */
/* untuk next update.. */
	POINT * castle;
	int i, j, k;
	k = 0;
	for(i = AbsisMin; i < AbsisEff(M) ; i++){
		for(j = OrdMin; j < OrdEff(M); j++){
			if(getBangunanId(M, i, j) == 2 && getBangunanOwner(M, i, j) == id){
				castle[k] = MakePOINT(i, j);
			}
		}
	}
	return castle;
}

char getId(int tipe, int id){
/* Mengembalikan tanda untuk bangunan atau unit */
	char c;
	if(tipe == 1){ // untuk bangunan
		switch(id){
			case 1: c = 'T'; break;
			case 2: c = 'C'; break;
			case 3: c = 'V'; break;
			default : c = ' '; break;
		}
	}else if(tipe == 2){ // untuk unit
		switch(id){
			case 1: c = 'K'; break;
			case 2: c = 'A'; break;
			case 3: c = 'S'; break;
			case 4: c = 'W'; break;
			default : c = ' '; break;
		}
	}
	return c;
}

void setBangunanKerajaan(Map * M, int cX, int cY, int playerId){
/* membuat bangunan kerajaan milik player dengan id playerId */
/* cX adalah absis tower dan cY adalah ordinat tower */
	/* castle */
	UpdateBangunanMap(M, MakePOINT(cX, cY - 1), 2, playerId);
	UpdateBangunanMap(M, MakePOINT(cX, cY + 1), 2, playerId);
	UpdateBangunanMap(M, MakePOINT(cX - 1, cY), 2, playerId);
	UpdateBangunanMap(M, MakePOINT(cX + 1, cY), 2, playerId);
	/* tower */
	UpdateBangunanMap(M, MakePOINT(cX, cY), 1, playerId);
	/* king */
	UpdateUnitMap(M, MakePOINT(cX, cY), 1, playerId);
}

void setVillage(Map * M, int numVillage){
/* I.S: ukuran peta sudah diinisialisasi */
/* meletakkan village tanpa pemilik secara random 
   tanpa mengganggu letak kerajaan */
    int i;
    for(i = 0; i < numVillage; i++){
		UpdateBangunanMap(M, getRandomPoint(*M), 3, 0);
	}
}

POINT getRandomPoint(Map M){
/* mencari point yang masih kosong secara random */
	int x, y;
	
    srand(time(NULL));
    x = AbsisEff(M) - 2;
	y = OrdMin + 1;
    while(getBangunanId(M, x, y) != 0){
		x = rand() % (AbsisEff(M) - 1);
		y = rand() % (OrdEff(M) - 1);
	}
	return MakePOINT(x, y);
}
