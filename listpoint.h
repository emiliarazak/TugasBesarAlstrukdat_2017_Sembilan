/* Nama File : listunit.c */
/* ADT List Linier */
/* By : Deborah Aprilia Josephine / 13516152 */

#ifndef listpoint_H
#define listpoint_H

#include "boolean.h"
#include "unit.h"
#include "point.h"

#define Nil NULL

/* Definisi Type Data */
typedef POINT infotypeP;
typedef struct tElmtlistP *addressP;
typedef struct tElmtlistP {
    infotypeP infoP;
    addressP nextP;
    addressP prevP;
} ElmtListP;
typedef struct {
    addressP FirstP;
    addressP LastP;
} ListP;


/* SELEKTOR */
#define InfoP(P) (P)->infoP
#define NextP(P) (P)->nextP
#define PrevP(P) (P)->prevP
#define FirstP(L) ((L).FirstP)
#define LastP(L) ((L).LastP)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyP (ListP L);
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyP (ListP *L);
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
addressP AlokasiP (infotypeP X);
/* Mengirimkan addressP hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressP tidak nil. */
/* Misalnya: menghasilkan P, maka Info1(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */

void DealokasiP (addressP P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressP P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressP SearchP (ListP L, infotypeP X);
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan addressP elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
//addressP Search2 (List L, infotypeP2 X);
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan addressP elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstP (ListP *L, infotypeP X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */

void InsVLastP (ListP *L, infotypeP X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstP (ListP *L, infotypeP *X);
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */

void DelVLastP (ListP *L, infotypeP *X);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstP (ListP *L, addressP P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressP P sebagai elemen pertama */

void InsertLastP (ListP *L, addressP P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

void InsertAfterP (ListP *L, addressP P, addressP Prec);
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */

void InsertBeforeP (ListP *L, addressP P, addressP Succ);
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstP (ListP *L, addressP *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */

void DelLastP (ListP *L, addressP *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
//void DelP1 (List *L, infotypeP1 X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddressP P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
//void DelP2 (List *L, infotypeP2 X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddressP P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */

void DelAfterP (ListP *L, addressP *Pdel, addressP Prec);
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

void DelBeforeP (ListP *L, addressP *Pdel, addressP Succ);
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */

void PrintListP (ListP L);
/* Prosedur ini digunakan untuk melakukan print List of Unit */
/* I.S. : L sembarang */
/* F.S : Tercetak list of unit */

#endif
