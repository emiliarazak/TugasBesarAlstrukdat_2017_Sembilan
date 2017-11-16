/* ADT Map */
/* Implementasi dengan menggunakan array dua dimensi */

#ifndef _MAP_H_
#define _MAP_H_

#include <stdio.h>
#include "boolean.h"
#include "point.h"

/* Ukuran minimum dan maksimum baris dan kolom */
#define AbsisMin 1
#define AbsisMax 15
#define OrdMin 1
#define OrdMax 15

typedef struct {
	int id_bangunan; /* untuk bangunan: (1) Tower, (2) Castel, (3) Village, (0) blank */
	int id_unit; /* untuk unit: (1) King, (2) Archer, (3) Swordsman, (4) White Mage, (0) blank */
	int id_pemilik; /* pemilik bangunan: 0 bila tanpa pemilik */
} ElType; 

typedef struct { 
	ElType Mem[AbsisMax+1][OrdMax+1];
    int NAbsisEff; /* banyaknya/ukuran absis yg terdefinisi */
	int NOrdEff; /* banyaknya/ukuran ordinat yg terdefinisi */
} Map;

#define AbsisEff(M) (M).NAbsisEff
#define OrdEff(M) (M).NOrdEff

#define Bangunan(M, P) (M).Mem[(Absis(P))][(Ordinat(P))].id_bangunan;
#define Unit(M, P) (M).Mem[(Absis(P))][(Ordinat(P))].id_unit;
#define Pemilik(M, P) (M).Mem[(Absis(P))][(Ordinat(P))].id_pemilik;

#define Bangunan(M, x, y) (M).Mem[(x)][(y)].id_bangunan;
#define Unit(M, x, y) (M).Mem[(x)][(y)].id_unit;
#define Pemilik(M, x, y) (M).Mem[(x)][(y)].id_pemilik;

/* buat array untuk menggambarkan jenis unit dan bangunan */
/* untuk next update.. */

Map CreateEmptyMap(int X, int Y);
/* Membuat petak normal sebanyak X * Y */

Map InitMap(int X, int Y);
/* Membuat map dengan ukuran X * Y */

void PrintMap(Map M);
/* Mencetak Map secara keseluruhan */

void UpdateUnitMap(Map M, POINT P, int newId);
/* I.S: map sudah diinisialisasi */
/* x dan y adalah posisi absis dan ordinat yang baru */
/* newId adalah id unit yang baru */
/* isi dari newId: (1) King, (2) Archer, (3) Swordsman, (4) White Mage, (0) blank */
/* Mengubah posisi dari unit yang ada di map */

void UpdateBangunanMap(Map M, POINT P, int newId);
/* I.S: map sudah diinisialisasi */
/* x dan y adalah posisi absis dan ordinat yang baru */
/* newId adalah id bangunan yang baru */
/* isi dari newId: (1) Tower, (2) Castel, (3) Village, (0) blank */
/* Mengubah posisi dari bangunan yang ada di map */

void UpdatePemilik(Map M, POINT P, int newId);
/* I.S: map sudah diinisialisasi */
/* x dan y adalah posisi absis dan ordinat yang baru */
/* newId adalah id pemilik yang baru */
/* isi dari newId: (0) tanpa pemilik, (1) player 1, (2) player 2, dst */
/* Mengubah pemilik petak yang ada di map */

/*** Untuk keperluan move ***/
boolean IsPosisiTerkiri(Map M, POINT P);
/* Mengembalikan true bila posisi (x, _) ada di pinggir kiri map */
/* tapi bukan di ujung map */

boolean IsPosisiTerkanan(Map M, POINT P);
/* Mengembalikan true bila posisi (x, _) ada di pinggir kanan map */
/* tapi bukan di ujung map */

boolean IsPosisiPalingAtas(Map M, POINT P);
/* Mengembalikan true bila posisi (_, y) ada di paling atas map */
/* tapi bukan di ujung map */

boolean IsPosisiPalingBawah(Map M, POINT P);
/* Mengembalikan true bila posisi (_, y) ada di paling bawah map */
/* tapi bukan di ujung map */

boolean IsPosisiUjung(Map M, POINT P);
/* Mengembalikan true bila posisi (x, y) ada di ujung map */

POINT * getCastle(Map M);
/* Mengembalikan castle yang dimiliki oleh player nya */

char getId(int tipe, int id);
/* Mengembalikan tanda untuk bangunan atau unit */

#endif
