/**
Filename: map.h
Prepared by: Intan Nurjanah / 13516131
Created at: 16/11/2017
**/

/* ADT Map */
/* Implementasi dengan menggunakan array dua dimensi */

#ifndef _MAP_H_
#define _MAP_H_

#include <stdio.h>
#include "boolean.h"
#include "point.h"

/* Ukuran minimum dan maksimum baris dan kolom */
#define AbsisMin 0
#define AbsisMax 100
#define OrdMin 0
#define OrdMax 100

typedef struct{
	int id; /* untuk bangunan: (1) Tower, (2) Castel, (3) Village, (0) blank */
	int pemilik; /* pemilik bangunan: 0 bila tanpa pemilik */
} BangunanMap;

typedef struct{
	int id; /* untuk unit: (1) King, (2) Archer, (3) Swordsman, (4) White Mage, (0) blank */
	int pemilik;
	boolean giliran;
} UnitMap;

typedef struct {
	BangunanMap bangunan;
	UnitMap unit;
} ElType; 

typedef struct { 
	ElType Mem[AbsisMax+1][OrdMax+1];
    int NAbsisEff; /* banyaknya/ukuran absis yg terdefinisi */
	int NOrdEff; /* banyaknya/ukuran ordinat yg terdefinisi */
} Map;

extern Map M;

/*** Selektor ***/
ElType getElmt(int x, int y);
/* Mengembalikan element dari di petak x dan y */

int getBangunanId(int x, int y);
/* Mengembalikan id bangunan di petak x dan y */

int getBangunanOwner(int x, int y);
/* Mengembalikan pemilik bangunan di petak x dan y */

int getUnitId(int x, int y);
/* Mengembalikan id unit di petak x dan y */

int getUnitOwner(int x, int y);
/* Mengembalikan pemilik unit di petak x dan y */


/*** Untuk tampilan map ***/
void MakeEmptyMap(int X, int Y);
/* Membuat petak normal sebanyak X * Y */

void InitMap(int X, int Y);
/* Membuat map dengan ukuran X * Y */

void PrintMap();
/* Mencetak Map secara keseluruhan */

void PrintAngkaAbsis(int X);
/* Menampilkan angka yang ada disebelah kiri map */

void PrintAngkaOrdinat(int Y);
/* Menampilkan angka diatas Map */

void printBangunan(BangunanMap bangunan);
/* Mencetak bangunan dengan warna tertentu */

void printUnit(UnitMap unit);
/* Mencetak unit dengan warna tertentu */	

void UpdateUnitMap(POINT P, int newId, int pemilik);
/* I.S: map sudah diinisialisasi */
/* x dan y adalah posisi absis dan ordinat yang baru */
/* newId adalah id unit yang baru */
/* isi dari newId: (1) King, (2) Archer, (3) Swordsman, (4) White Mage, (0) blank */
/* Mengubah posisi dari unit yang ada di map */

void UpdateBangunanMap(POINT P, int newId, int pemilik);
/* I.S: map sudah diinisialisasi */
/* x dan y adalah posisi absis dan ordinat yang baru */
/* newId adalah id bangunan yang baru */
/* isi dari newId: (1) Tower, (2) Castel, (3) Village, (0) blank */
/* Mengubah posisi dari bangunan yang ada di map */

void UpdateGiliranUnitMap(POINT P, boolean giliran);
/* Mengganti giliran dari unit pada point P */

void setBangunanKerajaan(int cX, int cY, int playerId);
/* Membuat bangunan kerajaan milik player dengan id playerId */
/* cX adalah absis tower dan cY adalah ordinat tower */

void setVillage(int numVillage);
/* I.S: ukuran peta sudah diinisialisasi */
/* Meletakkan village tanpa pemilik secara random 
   tanpa mengganggu letak kerajaan */

POINT getRandomPoint();
/* mencari point yang masih kosong secara random */

char getId(int tipe, int id);
/* Mengembalikan tanda untuk bangunan atau unit */

int getDigit(int X);
/* Mengembalikan digit dari angka X */


/*** Untuk keperluan move ***/
boolean IsPosisiTerkiri(POINT P);
/* Mengembalikan true bila posisi (x, _) ada di pinggir kiri map */

boolean IsPosisiTerkanan(POINT P);
/* Mengembalikan true bila posisi (x, _) ada di pinggir kanan map */

boolean IsPosisiPalingAtas(POINT P);
/* Mengembalikan true bila posisi (_, y) ada di paling atas map */

boolean IsPosisiPalingBawah(POINT P);
/* Mengembalikan true bila posisi (_, y) ada di paling bawah map */

boolean IsKingInTower(int playerId);
/* Mengembalikan true jika King berada di tower miliknya */

boolean IsCastleEmpty(int x, int y);
/* Memeriksa apakah castle tersebut kosong */

boolean IsNoUnit(int x, int y);
/* Mengembalikan true bila dalam x dan y tidak ada unit */	
boolean IsPointInMap(int x, int y);
/* Mengembalikan true jika (x,y) terdapat di map */

POINT getKingPoint(int playerId);
/* Mengembalikan point <x,y> dimana King milik playerId berada */

POINT getTowerPoint(int playerId);
/* Mengembalikan point <x,y> dimana tower milik playerId berada */

#endif
