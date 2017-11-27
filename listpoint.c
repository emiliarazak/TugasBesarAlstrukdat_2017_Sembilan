/* Nama File : listunit.c */
/* ADT List Linier */
/* By : Deborah Aprilia Josephine / 13516152 */

#include "listpoint.h"
#include "point.h"
#include <stdlib.h>
#include <stdio.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyP (ListP L)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
    return ((FirstP(L)==Nil)&&(LastP(L)==Nil));
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyP (ListP *L)
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
    FirstP(*L) = Nil;
    LastP(*L) = Nil;
}

/****************** Manajemen Memori ******************/
addressP AlokasiP (infotypeP X)
/* Mengirimkan addressP hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressP tidak nil. */
/* Misalnya: menghasilkan P, maka Info1(P)=X, NextP(P)=Nil, PrevP(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
{
/* Kamus */
    addressP P;
/* Algoritma */
    P = (addressP) malloc (sizeof(ElmtListP));
    if (P!=Nil) {
        InfoP(P) = X;
        NextP(P) = Nil;
        PrevP(P) = Nil;
        return P;
    }
    else {
        return Nil;
    }
}

void DealokasiP (addressP P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressP P */
{
    free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressP SearchP (ListP L, infotypeP X)
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan addressP elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
//addressP Search2 (List L, infotypeP2 X);
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan addressP elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
/* Kamus */
    boolean found ;
    addressP P ;
/* Algoritma */
    if(IsEmptyP(L)) {
        return Nil;
    }
    else {
        found = false;
        P = FirstP(L);
        while((P!=Nil)&&!found){
            if ((InfoP(P).X == X.X)&&(InfoP(P).Y == X.Y)) {
                found = true;
            }
            else {
                P = NextP(P);
            }
        }

        if (found){
            return P;
        }
        else {
            return Nil;
        }
    }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstP (ListP *L, infotypeP X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
/* Kamus */
    addressP P;
/* Algoritma */
    P = AlokasiP(X);
    if (P!=Nil) {
        InsertFirstP(L,P);
    }
}

void InsVLastP (ListP *L, infotypeP X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
/* Kamus */
    addressP P ;
/* Algoritma */
    P = AlokasiP(X);
    if (P!=Nil){
        InsertLastP(L,P);
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstPP (ListP *L, infotypeP *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
/* Kamus */
    addressP P ;
/* Algoritma */
    DelFirstP(L,&P);
    if (P!=Nil){
        *X = InfoP(P);
        DealokasiP(P);
    }
}

void DelVLastP (ListP *L, infotypeP *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
/* Kamus */
    addressP P;
/* Algoritma */
    if (NextP(FirstP(*L))==Nil){
        *X = InfoP(FirstP(*L));
        CreateEmptyP(L);
    }
    else {
        DelLastP(L,&P);
        if (P!=Nil){
            *X = InfoP(P);
            DealokasiP(P);
        }
    }
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstP (ListP *L, addressP P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressP P sebagai elemen pertama */
{
/* Kamus */
/* Algoritma */
    if (FirstP(*L)!= Nil){
        NextP(P) = FirstP(*L);
        PrevP(P) = PrevP(FirstP(*L)) ;
        PrevP(FirstP(*L)) = P ;
        FirstP(*L) = P ;
    }
    else {
        FirstP(*L) = P;
        LastP(*L) = P;
    }
}

void InsertLastP (ListP *L, addressP P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
/* Kamus */
/* Algoritma */
    if (FirstP(*L)==Nil){
        InsertFirstP(L,P);
    }
    else {
        NextP(P) = NextP(LastP(*L));
        PrevP(P) = LastP(*L);
        NextP(LastP(*L)) = P ;
        LastP(*L) = P ;
    }
}

void InsertAfterP (ListP *L, addressP P, addressP Prec)
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
/* Kamus */
    addressP i ;
/* Algoritma */
    //Mencari Prec dan i = NextP(Prec)
    i = FirstP(*L);
    while (PrevP(i) != Prec) {
        i = NextP(i);
    }
    if (i != Nil){
        PrevP(P) = Prec ;
        NextP(P) = i;
        NextP(Prec) = P ;
        PrevP(i) = P;
    }
    else{
        InsertLastP(L,P);
    }
}

void InsertBeforeP (ListP *L, addressP P, addressP Succ)
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */
{
/* Kamus */
    addressP i ;
/* Algoritma */
    //Mencari Succ dan i = PrevP(Succ)
    i = FirstP(*L);
    while (NextP(i) != Succ) {
        i = NextP(i);
    }
    if (i!=Nil){
        PrevP(P) = i ;
        NextP(P) = Succ;
        PrevP(Succ) = P ;
        NextP(i) = P;
    }
    else{
        InsertFirstP(L,P);
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstP (ListP *L, addressP *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* FirstP element yg baru adalah suksesor elemen pertama yang lama */
{
/* Kamus */
/* Algoritma */
    *P = FirstP(*L);
    if (NextP(FirstP(*L))==Nil){
        CreateEmptyP(L);
    }
    else {
        FirstP(*L) = NextP(FirstP(*L));
        PrevP(FirstP(*L)) = Nil;
        PrevP(*P) = Nil;
        NextP(*P) = Nil;
    }
}

void DelLastP (ListP *L, addressP *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* LastP element baru adalah predesesor elemen pertama yg lama, jika ada */
{
/* Kamus */
/* Algoritma */
    *P = LastP(*L);
    if (NextP(FirstP(*L))==Nil){
        CreateEmptyP(L);
    }
    else {
        LastP(*L) = PrevP(LastP(*L));
        NextP(LastP(*L)) = Nil;
        PrevP(*P) = Nil;
        NextP(*P) = Nil;
    }
}

void DelAfterP (ListP *L, addressP *Pdel, addressP Prec)
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus NextP(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
/* Kamus */
/* Algoritma */
    *Pdel = NextP(Prec);
    if (*Pdel == LastP(*L)){
        DelLastP(L,Pdel);
    }
    else{
        if (*Pdel!=Nil){
            NextP(Prec) = NextP(*Pdel);
            PrevP(NextP(*Pdel)) = Prec;
            PrevP(*Pdel) = Nil;
            NextP(*Pdel) = Nil;
        }
    }
}

void DelBeforeP (ListP *L, addressP *Pdel, addressP Succ)
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus PrevP(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
/* Kamus */
/* Algoritma */
    *Pdel = PrevP(Succ);
    if (*Pdel == FirstP(*L)) {
        DelFirstP(L,Pdel);
    }
    else {
        if (*Pdel!=Nil){
            PrevP(Succ) = PrevP(*Pdel);
            NextP(PrevP(*Pdel)) = Succ;
            PrevP(*Pdel) = Nil;
            NextP(*Pdel) = Nil;
        }
    }
}

void PrintListP (ListP L)
/* Prosedur ini digunakan untuk melakukan print List of Unit */
/* I.S. : L sembarang */
/* F.S : Tercetak list of unit */
{
/* Kamus */
    addressP P;
    int i;
    POINT Prop;
/* Algoritma */
    printf("== List of Property ==\n");
    if (!IsEmptyP(L)){
        P = FirstP(L);
        i = 1;
        while (P!=Nil){
            Prop = InfoP(P);
            printf("%d. ", i);
            printf("(%d,%d)\n", InfoP(P).X, InfoP(P).Y);
            P = NextP(P);
            i++;
        }
    }
}
