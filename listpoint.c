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
address AlokasiP (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info1(P)=X, NextP(P)=Nil, PrevP(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
{
/* Kamus */
    address P;
/* Algoritma */
    P = (address) malloc (sizeof(ElmtListP));
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

void DealokasiP (address P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address SearchP (ListP L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
//address Search2 (List L, infotype2 X);
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
/* Kamus */
    boolean found ;
    address P ;
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
void InsVFirstP (ListP *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
/* Kamus */
    address P;
/* Algoritma */
    P = AlokasiP(X);
    if (P!=Nil) {
        InsertFirstP(L,P);
    }
}

void InsVLastP (ListP *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
/* Kamus */
    address P ;
/* Algoritma */
    P = AlokasiP(X);
    if (P!=Nil){
        InsertLastP(L,P);
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstPP (ListP *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
/* Kamus */
    address P ;
/* Algoritma */ 
    DelFirstPP(L,&P);
    if (P!=Nil){        
        *X = InfoP(P);
        DealokasiP(P);
    }   
}

void DelVLastP (ListP *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
/* Kamus */
    address P;
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
void InsertFirstP (ListP *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
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

void InsertLastP (ListP *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
/* Kamus */
/* Algoritma */
    if (FirstP(*L)==Nil){
        InsertFirstPP(L,P);
    }
    else {
        NextP(P) = NextP(LastP(*L));
        PrevP(P) = LastP(*L); 
        NextP(LastP(*L)) = P ;
        LastP(*L) = P ;
    }
}

void InsertAfterP (ListP *L, address P, address Prec)
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
/* Kamus */
    address i ;
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

void InsertBeforeP (ListP *L, address P, address Succ)
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */
{
/* Kamus */
    address i ;
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
        InsertFirstPP(L,P);
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstP (ListP *L, address *P)
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

void DelLastPP (ListP *L, address *P)
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

void DelAfterP (ListP *L, address *Pdel, address Prec)
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

void DelBeforeP (ListP *L, address *Pdel, address Succ)
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
    address P;
    int i;
    POINT Prop;
/* Algoritma */
    printf("== List of Property ==\n");
    if (!IsEmptyP(L)){
        P = FirstP(L);
        i = 1;
        while (P!=Nil){
            Prop = InfoP(P);
            //L = GetLocation(U); 
            printf("%d. ", i);
            /*
            if (U.id == 1) {
                printf("King (%d,%d) | Health %d\n", L.X, L.Y, U.health);
            }
            else {
                if (U.id ==2 ){
                    printf("Archer (%d,%d) | Health %d\n", L.X, L.Y, U.health);
                }
                else {
                    if (U.id ==3){
                        printf("Swordsman (%d,%d) | Health %d\n", L.X, L.Y, U.health);
                    }
                    else {
                        if (U.id == 4){
                            printf("White Mage (%d,%d) | Health %d\n", L.X, L.Y, U.health);
                        }
                    }
                }
            }
            */
            printf("(%d,%d)\n", InfoP(P).X, InfoP(P).Y);
            P = NextP(P);
            i++;
        }
    }	
}