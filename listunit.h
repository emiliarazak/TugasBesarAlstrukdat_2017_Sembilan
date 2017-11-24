/* Nama File : listunit.c */
/* ADT List Linier */
/* By : Deborah Aprilia Josephine / 13516152 */

#ifndef listunit_H
#define listunit_H

#include "boolean.h"
#include "unit.h"
#include "point.h"
#include <stdlib.h>

#define Nil NULL

/* Definisi Type Data */
typedef Unit infotypeU;
typedef struct tElmtlistU *addressU;
typedef struct tElmtlistU {
    infotypeU infoU;
    addressU nextU;
    addressU prevU;
} ElmtListU;
typedef struct {
    addressU FirstU;
    addressU LastU;
} ListU;


/* SELEKTOR */
#define InfoU(P) (P)->infoU
#define NextU(P) (P)->nextU
#define PrevU(P) (P)->prevU
#define FirstU(L) ((L).FirstU)
#define LastU(L) ((L).LastU)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyU (ListU L);
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyU (ListU *L);
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
addressU AlokasiU (infotypeU X);
/* Mengirimkan addressU hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressU tidak nil. */
/* Misalnya: menghasilkan P, maka Info1(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */

void DealokasiU (addressU P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressU P */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstU (ListU *L, infotypeU X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */

void InsVLastU (ListU *L, infotypeU X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstU (ListU *L, infotypeU *X);
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */

void DelVLastU (ListU *L, infotypeU *X);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstU (ListU *L, addressU P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressU P sebagai elemen pertama */

void InsertLastU (ListU *L, addressU P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

void InsertAfterU (ListU *L, addressU P, addressU Prec);
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */

void InsertBeforeU (ListU *L, addressU P, addressU Succ);
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstU (ListU *L, addressU *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */

void DelLastU (ListU *L, addressU *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
//void DelP1 (List *L, infotypeU1 X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddressU P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
//void DelP2 (List *L, infotypeU2 X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddressU P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */

void DelAfterU (ListU *L, addressU *Pdel, addressU Prec);
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

void DelBeforeU (ListU *L, addressU *Pdel, addressU Succ);
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */

void PrintListU (ListU L);
/* Prosedur ini digunakan untuk melakukan print List of Unit */
/* I.S. : L sembarang */
/* F.S : Tercetak list of unit */

#endif
