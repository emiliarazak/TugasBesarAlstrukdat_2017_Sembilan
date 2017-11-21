/* File: point.c */
/* Tanggal: 29 Agustus 2017 */
/* NIM/Nama: 13516131/Intan Nurjanah*/
/* *** Realisasi ABSTRACT DATA TYPE POINT *** */

#include <stdio.h>
#define _USE_MATH_DEFINES
/*#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif*/

#include <math.h>
#include "boolean.h"
#include "point.h"

/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (int X, int Y){
	POINT p;
	Absis(p) = X;
	Ordinat(p) = Y;
	return p;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void BacaPOINT (POINT * P){ 
	float x, y;
	scanf("%f %f", &x, &y);
	*P = MakePOINT(x,y);
}

void TulisPOINT (POINT P){
	printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2){
	return ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)));
}

boolean NEQ (POINT P1, POINT P2){
	return ((Absis(P1) != Absis(P2)) || (Ordinat(P1) != Ordinat(P2)));
}

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P){
	return ((Absis(P) == 0) && (Ordinat(P) == 0));
}

boolean IsOnSbX (POINT P){
	return (Ordinat(P) == 0);
}

boolean IsOnSbY (POINT P){
	return (Absis(P) == 0);
}

int Kuadran (POINT P){
	//P tidak terletak di sumbu atau di titik 0
	int K;
	if (Absis(P) < 0){ // di kiri sbx
		K = 3;
		if (Ordinat(P) > 0){
			K = 2;
		}
	}else{ // di kanan sbx
		K = 4;
		if (Ordinat(P) > 0){
			K = 1;
		}
	}
	return K;
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */                           
POINT NextX (POINT P){
	return PlusDelta(P, 1, 0);
}   

POINT NextY (POINT P){
	return PlusDelta(P, 0, 1);
}   

POINT PlusDelta (POINT P, float deltaX, float deltaY){
	return (MakePOINT(Absis(P) + deltaX, Ordinat(P) + deltaY));
}

POINT MirrorOf (POINT P, boolean SbX){
	POINT P2;
	if (SbX){
		if (Ordinat(P) != 0){ //digeser kalau bukan 0
			P2 = MakePOINT(Absis(P), (Ordinat(P) * (-1)));
		}else{
			P2 = MakePOINT(Absis(P), 0);
		}
	}else{
		if (Absis(P) != 0){
			P2 = MakePOINT((Absis(P) * (-1)), Ordinat(P));
		}else{
			P2 = MakePOINT(0, (Ordinat(P)));
		}
	}
	return P2;
}

float Jarak0 (POINT P){
	return (float) (sqrt((Absis(P) * Absis(P)) + (Ordinat(P) * Ordinat(P))));
}

float Panjang (POINT P1, POINT P2){
/* Menghitung panjang garis yang dibentuk P1 dan P2 */
/* Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis. */
/* Tuliskan spec fungsi yang lebih tepat. */
	float x, y;
	x = Absis(P1) - Absis(P2); //tak peduli positif atau negatif karena pada akhirnya dikuadratkan
	y = Ordinat(P1) - Ordinat(P2);
	return (float) (sqrt((x * x) + (y * y)));
}

void Geser (POINT *P, float deltaX, float deltaY){
	Absis(*P) = Absis(*P) + deltaX;
	Ordinat(*P) = Ordinat(*P) + deltaY;
}

void GeserKeSbX (POINT *P){
	Ordinat(*P) = 0;
}

void GeserKeSbY (POINT *P){
	Absis(*P) = 0;
}

void Mirror (POINT *P, boolean SbX){
	if (SbX){
		if (Ordinat(*P) != 0){
			Ordinat(*P) = Ordinat(*P) * (-1);
		}
	}else{
		if (Absis(*P) != 0){
			Absis(*P) = Absis(*P) * (-1);
		}
	}
}

void Putar (POINT *P, float Sudut){
	//asumsi diputar berlawanan arah jarum jam dan sudut derajat
	double rad;
	rad = (Sudut * M_PI * (-1))/180.0 ;
	Absis(*P) = (float) ((Absis(*P)*cos(rad)) - (Ordinat(*P)*sin(rad)));
	Ordinat(*P) = (float) ((Absis(*P)*sin(rad)) + (Ordinat(*P)*cos(rad)));
}
