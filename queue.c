/* Nama		: Deborah Aprilia Josephine */
/* NIM		: 13516152 */
/* Topik	: Queue Variasi III */
/* Tanggal	: 30 September 2017 */
/* Deskripsi: ADT Queue beserta Primitifnya */

#include "boolean.h"
#include "queue.h"
#include <stdlib.h>
#include <stdio.h>
#include "player.h"

/* ********* Prototype ********* */
boolean IsEmptyQ (Queue Q){
/* Mengirim true jika Q kosong: lihat definisi di atas */
/* Kamus */
/* Algoritma */
	return ((Head(Q)==Nil)&&(Tail(Q)==Nil));
}

boolean IsFullQ (Queue Q){
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
/* Kamus */
/* Algoritma */
	return (NBElmtQ(Q) == MaxEl(Q));
}

int NBElmtQ (Queue Q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
/* Kamus */
/* Algoritma */
	if (IsEmpty(Q)){
		return 0;
	}
	else {
		if (Head(Q)<=Tail(Q)){
			return (Tail(Q)-Head(Q)+1);
		}
		else { 
			return (MaxEl(Q)-Head(Q)+Tail(Q)+1); 
		}
	}
}

/* *** Kreator *** */
void CreateEmptyQ (Queue * Q, int Max){
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
/* Kamus */
/* Algoritma */
	(*Q).T = (infotypeQ *) malloc ((Max+1) * sizeof(infotypeQ)) ;
	if ((*Q).T != NULL ){
		MaxEl(*Q) = Max ;
		Head(*Q) = Nil ;
		Tail(*Q) = Nil ;
	}
	else {
		MaxEl(*Q) = 0;
	}
}

/* *** Destruktor *** */
void DeAlokasiQ(Queue * Q){
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
/* Kamus */
/* Algoritma */
	free ((*Q).T);
	MaxEl(*Q) = 0;
}

/* *** Primitif Add/Delete *** */
void AddQ (Queue * Q, infotypeQ X){
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
/* Kamus */
/* Algoritma */
	if (IsEmptyQ(*Q)){
		Head(*Q) = 1 ;
		Tail(*Q) = 1 ;
		InfoTail(*Q) = X;
	}
	else {
		if (!IsFullQ(*Q)){
			if (Tail(*Q)==MaxEl(*Q)){
				Tail(*Q) = 1;
			}
			else {
				Tail(*Q)++;
			}
			InfoTail(*Q) = X;
		}
	}

}

void DelQ (Queue * Q, infotypeQ * X){
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */
/* Kamus */
	int max ;
/* Algoritma */
	*X = InfoHead(*Q);
	if (NBElmt(*Q)==1){
		Head(*Q) = Nil ;
		Tail(*Q) = Nil ;
	}
	else {
		if (Head(*Q)==MaxEl(*Q)){
			Head(*Q)=1;
		}
		else {
			Head(*Q)++;
		}
	}
}
