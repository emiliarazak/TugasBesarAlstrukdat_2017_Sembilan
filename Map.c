#include <stdio.h>
#include "Map.h"

Map CreateEmptyMap(int X, int Y){
/* Membuat petak normal sebanyak X * Y */
	Map M;
	int i,j;
	
	AbsisEff(M) = X;
	OrdEff(M) = Y;
	for(i = 1; i < AbsisEff(M); i++){
		for(j = 1; j < OrdEff(M); j++){
			Bangunan(M, i, j) = 0;
			Unit(M, i, j) = 0;
			Pemilik(M, i, j) = 0;
		}
	}
}

Map InitMap(int X, int Y){
/* Membuat map dengan ukuran X * Y */
/* algoritma untuk next update.. */
}

void PrintMap(Map M){
/* Mencetak Map secara keseluruhan */
	int i, j;
	for(i = 1; i < AbsisEff(M); i++){
		for(j = 1; j < OrdEff(M); j++){
			printf(" %s ", getId(1, Bangunan(M, i, j)));
		} printf("\n");
		for(j = 1; j < OrdEff(M); j++){
			printf(" %s ", getId(2, Bangunan(M, i, j)));
		} printf("\n");
		for(j = 1; j < OrdEff(M); j++){
			printf("   ");
		}
		printf("\n");
	}
}

void UpdateUnitMap(Map M, POINT P, int newId){
/* I.S: map sudah diinisialisasi */
/* x dan y adalah posisi absis dan ordinat yang baru */
/* newId adalah id unit yang baru */
/* isi dari newId: (1) King, (2) Archer, (3) Swordsman, (4) White Mage, (0) blank */
/* Mengubah posisi dari unit yang ada di map */
	Unit(M, P) = newId;
}

void UpdateBangunanMap(Map M, POINT P, int newId){
/* I.S: map sudah diinisialisasi */
/* x dan y adalah posisi absis dan ordinat yang baru */
/* newId adalah id bangunan yang baru */
/* isi dari newId: (1) Tower, (2) Castel, (3) Village, (0) blank */
/* Mengubah posisi dari bangunan yang ada di map */
	Bangunan(M, P) = newId;
}

void UpdatePemilik(Map M, POINT P, int newId){
/* I.S: map sudah diinisialisasi */
/* x dan y adalah posisi absis dan ordinat yang baru */
/* newId adalah id pemilik yang baru */
/* isi dari newId: (0) tanpa pemilik, (1) player 1, (2) player 2, dst */
/* Mengubah pemilik petak yang ada di map */
	Pemilik(M, P) = newId;
}

/*** Untuk keperluan move ***/
boolean IsPosisiTerkiri(Map M, POINT P){
/* Mengembalikan true bila posisi (x, _) ada di pinggir kiri map */
/* tapi bukan di ujung map */
	return (Absis(P) == AbsisMin && !IsPosisiUjung(M, P));
}

boolean IsPosisiTerkanan(Map M, POINT P){
/* Mengembalikan true bila posisi (x, _) ada di pinggir kanan map */
/* tapi bukan di ujung map */
	return (Absis(P) == AbsisEff(M) && !IsPosisiUjung(M, P));
}

boolean IsPosisiPalingAtas(Map M, POINT P){
/* Mengembalikan true bila posisi (_, y) ada di paling atas map */
/* tapi bukan di ujung map */
	return (Ordinat(P) == OrdMin && !IsPosisiUjung(M, P));
}

boolean IsPosisiPalingBawah(Map M, POINT P){
/* Mengembalikan true bila posisi (_, y) ada di paling bawah map */
/* tapi bukan di ujung map */
	return (Ordinat(P) == OrdEff(M) && !IsPosisiUjung(M, P));
}

boolean IsPosisiUjung(Map M, POINT P){
/* Mengembalikan true bila posisi (x, y) ada di ujung map */
	return ((Absis(P) == AbsisMin || Absis(P) == AbsisEff(M)) && 
		(Ordinat(P) == OrdMin || Ordinat(P) == OrdEff(M)));
}

POINT * getCastle(Map M){
/* Mengembalikan castle yang dimiliki oleh player nya */
/* untuk next update.. */
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
}
