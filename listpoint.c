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
    return ((First(L)==Nil)&&(Last(L)==Nil));
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyP (ListP *L)
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
    First(*L) = Nil;
    Last(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address AlokasiP (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info1(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
{
/* Kamus */
    address P;
/* Algoritma */
    P = (address) malloc (sizeof(ElmtList));
    if (P!=Nil) {
        Info(P) = X;
        Next(P) = Nil;
        Prev(P) = Nil;
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
        P = First(L);
        while((P!=Nil)&&!found){
            if ((Info(P).X == X.X)&&(Info(P).Y == X.Y)) { 
                found = true;
            }
            else {
                P = Next(P);
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
void DelVFirstP (ListP *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
/* Kamus */
    address P ;
/* Algoritma */ 
    DelFirstP(L,&P);
    if (P!=Nil){        
        *X = Info(P);
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
    if (Next(First(*L))==Nil){
        *X = Info(First(*L));
        CreateEmptyP(L);
    }   
    else {
        DelLastP(L,&P);
        if (P!=Nil){
            *X = Info(P);
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
    if (First(*L)!= Nil){
        Next(P) = First(*L);
        Prev(P) = Prev(First(*L)) ;
        Prev(First(*L)) = P ;
        First(*L) = P ;
    }
    else {
        First(*L) = P;
        Last(*L) = P;
    }
}

void InsertLastP (ListP *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
/* Kamus */
/* Algoritma */
    if (First(*L)==Nil){
        InsertFirstP(L,P);
    }
    else {
        Next(P) = Next(Last(*L));
        Prev(P) = Last(*L); 
        Next(Last(*L)) = P ;
        Last(*L) = P ;
    }
}

void InsertAfterP (ListP *L, address P, address Prec)
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
/* Kamus */
    address i ;
/* Algoritma */
    //Mencari Prec dan i = Next(Prec)
    i = First(*L);
    while (Prev(i) != Prec) {
        i = Next(i);
    }
    if (i != Nil){
        Prev(P) = Prec ;
        Next(P) = i; 
        Next(Prec) = P ;
        Prev(i) = P;
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
    //Mencari Succ dan i = Prev(Succ)
    i = First(*L);
    while (Next(i) != Succ) {
        i = Next(i);
    }
    if (i!=Nil){
        Prev(P) = i ;
        Next(P) = Succ; 
        Prev(Succ) = P ;
        Next(i) = P;
    }
    else{
        InsertFirstP(L,P);
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstP (ListP *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
/* Kamus */
/* Algoritma */
    *P = First(*L);
    if (Next(First(*L))==Nil){
        CreateEmptyP(L);
    }
    else {
        First(*L) = Next(First(*L));
        Prev(First(*L)) = Nil;
        Prev(*P) = Nil;
        Next(*P) = Nil;
    }
}

void DelLastP (ListP *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
{
/* Kamus */
/* Algoritma */
    *P = Last(*L);
    if (Next(First(*L))==Nil){
        CreateEmptyP(L);
    }
    else {
        Last(*L) = Prev(Last(*L));
        Next(Last(*L)) = Nil;
        Prev(*P) = Nil;
        Next(*P) = Nil;
    }
}

void DelAfterP (ListP *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
/* Kamus */
/* Algoritma */
    *Pdel = Next(Prec);
    if (*Pdel == Last(*L)){
        DelLastP(L,Pdel);
    }
    else{
        if (*Pdel!=Nil){
            Next(Prec) = Next(*Pdel);
            Prev(Next(*Pdel)) = Prec;
            Prev(*Pdel) = Nil;
            Next(*Pdel) = Nil;
        }
    }
}

void DelBeforeP (ListP *L, address *Pdel, address Succ)
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
/* Kamus */
/* Algoritma */
    *Pdel = Prev(Succ);
    if (*Pdel == First(*L)) {
        DelFirstP(L,Pdel);
    }
    else {
        if (*Pdel!=Nil){
            Prev(Succ) = Prev(*Pdel);
            Next(Prev(*Pdel)) = Succ;
            Prev(*Pdel) = Nil;
            Next(*Pdel) = Nil;
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
        P = First(L);
        i = 1;
        while (P!=Nil){
            Prop = Info(P);
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
            printf("(%d,%d)\n", Info(P).X, Info(P).Y);
            P = Next(P);
            i++;
        }
    }	
}