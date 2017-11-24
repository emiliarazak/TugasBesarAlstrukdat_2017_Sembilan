/* File: point.c */
/* Tanggal: 29 Agustus 2017 */
/* *** Implementasi ABSTRACT DATA TYPE POINT *** */

#include "point.h"
#include <stdio.h>
#include <math.h>
/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
/* Membentuk sebuah POINT dari komponen-komponennya */
POINT MakePOINT (int X, int Y) {
	POINT p;

	Absis(p)=X;
	Ordinat(p)=Y;

	return p;
}


/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
void BacaPOINT (POINT * P) {
	float X, Y;
	scanf("%f %f", &X, &Y);
	Absis(*P)=X;
	Ordinat(*P)=Y;

}

/* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */
void TulisPOINT (POINT P) {
	printf("(%d,%d)", Absis(P), Ordinat(P));
}


/* *** Kelompok operasi relasional terhadap POINT *** */
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
boolean EQ (POINT P1, POINT P2) {
	return (Absis(P1)==Absis(P2) && Ordinat(P1)==Ordinat(P2));
}

/* Mengirimkan true jika P1 tidak sama dengan P2 */
boolean NEQ (POINT P1, POINT P2) {
	return (Absis(P1)!=Absis(P2) && Ordinat(P1)!=Ordinat(P2));
}


/* *** Kelompok menentukan di mana P berada *** */
/* Menghasilkan true jika P adalah titik origin */
boolean IsOrigin (POINT P) {
	return (Absis(P)==0 && Ordinat(P)==0);
}
/* Menghasilkan true jika P terletak Pada sumbu X */
boolean IsOnSbX (POINT P) {
	return (Ordinat(P)==0);
}
/* Menghasilkan true jika P terletak pada sumbu Y */
boolean IsOnSbY (POINT P) {
	return (Absis(P)==0);
}
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */

int Kuadran (POINT P) {
	if (Absis(P)>0 && Ordinat(P)>0){
		return 1;
	}
	else if(Absis(P)<0 && Ordinat(P)>0) {
		return 2;
	}
	else if(Absis(P)<0 && Ordinat(P)<0) {
		return 3;
	}
	else if(Absis(P)>0 && Ordinat(P)<0) {
		return 4;
	}
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
/* Mengirim salinan P dengan absis ditambah satu */
POINT NextX (POINT P) {
	return (MakePOINT(Absis(P)+1, Ordinat(P)));
}
/* Mengirim salinan P dengan ordinat ditambah satu */
POINT NextY (POINT P) {
	return (MakePOINT(Absis(P), Ordinat(P)+1));
}
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
POINT PlusDelta (POINT P, float deltaX, float deltaY) {
	return (MakePOINT(Absis(P) + deltaX, Ordinat(P) + deltaY));
}
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
POINT MirrorOf (POINT P, boolean SbX) {
	if (SbX) {
		return (MakePOINT(Absis(P), -Ordinat(P)));
	}
	else {
		return (MakePOINT(-Absis(P), Ordinat(P)));
	}
}
/* Menghitung jarak P ke (0,0) */
float Jarak0 (POINT P) {
	return (sqrt(Absis(P)*Absis(P)+Ordinat(P)*Ordinat(P)));
}
/* Menghitung panjang garis yang dibentuk P1 dan P2 */
/* Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis. */
/* Tuliskan spec fungsi yang lebih tepat. */
float Panjang (POINT P1, POINT P2) {
	return (sqrt((Absis(P2)-Absis(P1))*(Absis(P2)-Absis(P1))+(Ordinat(P2)-Ordinat(P1))*(Ordinat(P2)-Ordinat(P1))));
}
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
void Geser (POINT *P, float deltaX, float deltaY) {
	Absis(*P)+=deltaX;
	Ordinat(*P)+=deltaY;

}
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
void GeserKeSbY (POINT *P) {
	Absis(*P)=0;
}

/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
void GeserKeSbX (POINT *P) {
	Ordinat(*P)=0;

}
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
void Mirror (POINT *P, boolean SbX) {
	if (SbX) {
		Ordinat(*P)=-Ordinat(*P);
	}
	else {
		Absis(*P)=-Absis(*P);
	}

}
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) */
void Putar (POINT *P, float Sudut) {
	float X, Y;
	X=Absis(*P); Y=Ordinat(*P);
	Absis(*P)=X*cos(Sudut)-Y*sin(Sudut);
	Ordinat(*P)=X*sin(Sudut)+Y*cos(Sudut);
}
