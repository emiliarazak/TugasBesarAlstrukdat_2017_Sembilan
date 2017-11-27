/* Nama File : listunit.c */
/* ADT List Linier */
/* By : Deborah Aprilia Josephine / 13516152 */

#include "listunit.h"
#include "point.h"
#include "unit.h"
#include <stdlib.h>
#include <stdio.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyU (ListU L)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
    return ((FirstU(L)==Nil)&&(LastU(L)==Nil));
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyU (ListU *L)
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
/* Kamus */
/* Algoritma */
    FirstU(*L) = Nil;
    LastU(*L) = Nil;
}

/****************** Manajemen Memori ******************/
addressU AlokasiU (infotypeU X)
/* Mengirimkan addressU hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressU tidak nil. */
/* Misalnya: menghasilkan P, maka Info1(P)=X, Next(P)=Nil, PrevU(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
{
/* Kamus */
    addressU P;
/* Algoritma */
    P = (addressU) malloc (sizeof(ElmtListU));
    if (P!=Nil) {
        InfoU(P) = X;
        NextU(P) = Nil;
        PrevU(P) = Nil;
        return P;
    }
    else {
        return Nil;
    }
}

void DealokasiU (addressU P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressU P */
{
    free(P);
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstU (ListU *L, infotypeU X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
/* Kamus */
    addressU P;
/* Algoritma */
    P = AlokasiU(X);
    if (P!=Nil) {
        InsertFirstU(L,P);
    }
}

void InsVLastU (ListU *L, infotypeU X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
/* Kamus */
    addressU P ;
/* Algoritma */
    P = AlokasiU(X);
    if (P!=Nil){
        InsertLastU(L,P);
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstU (ListU *L, infotypeU *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
/* Kamus */
    addressU P ;
/* Algoritma */
    DelFirstU(L,&P);
    if (P!=Nil){
        *X = InfoU(P);
        DealokasiU(P);
    }
}

void DelVLastU (ListU *L, infotypeU *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
/* Kamus */
    addressU P;
/* Algoritma */
    if (NextU(FirstU(*L))==Nil){
        *X = InfoU(FirstU(*L));
        CreateEmptyU(L);
    }
    else {
        DelLastU(L,&P);
        if (P!=Nil){
            *X = InfoU(P);
            DealokasiU(P);
        }
    }
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstU (ListU *L, addressU P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressU P sebagai elemen pertama */
{
/* Kamus */
/* Algoritma */
    if (FirstU(*L)!= Nil){
        NextU(P) = FirstU(*L);
        PrevU(P) = PrevU(FirstU(*L)) ;
        PrevU(FirstU(*L)) = P ;
        FirstU(*L) = P ;
    }
    else {
        FirstU(*L) = P;
        LastU(*L) = P;
    }
}

void InsertLastU (ListU *L, addressU P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
/* Kamus */
/* Algoritma */
    if (FirstU(*L)==Nil){
        InsertFirstU(L,P);
    }
    else {
        NextU(P) = NextU(LastU(*L));
        PrevU(P) = LastU(*L);
        NextU(LastU(*L)) = P ;
        LastU(*L) = P ;
    }
}

void InsertAfterU (ListU *L, addressU P, addressU Prec)
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
/* Kamus */
   /* addressU i ;
/* Algoritma 
    //Mencari Prec dan i = NextU(Prec)
    i = FirstU(*L);
    while (PrevU(i) != Prec) {
        i = NextU(i);
    }
    if (i != Nil){
        PrevU(P) = Prec ;
        NextU(P) = i;
        NextU(Prec) = P ;
        PrevU(i) = P;
    }
    else{
        InsertLastU(L,P);
    }*/

    if(NextU(Prec)!=Nil){
        PrevU(NextU(Prec))=P;
    }
    else{
        LastU(*L)=P;
    }
    
    NextU(P)=NextU(Prec);
    PrevU(P)=Prec;
    NextU(Prec)=P;
}

void InsertBeforeU (ListU *L, addressU P, addressU Succ)
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */
{
/* Kamus */
    addressU i ;
/* Algoritma */
    //Mencari Succ dan i = PrevU(Succ)
    i = FirstU(*L);
    while (NextU(i) != Succ) {
        i = NextU(i);
    }
    if (i!=Nil){
        PrevU(P) = i ;
        NextU(P) = Succ;
        PrevU(Succ) = P ;
        NextU(i) = P;
    }
    else{
        InsertFirstU(L,P);
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstU (ListU *L, addressU *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* FirstU element yg baru adalah suksesor elemen pertama yang lama */
{
/* Kamus */
/* Algoritma */
    addressU temp=FirstU(*L);
    (*P)=FirstU(*L);
    FirstU(*L)=NextU(FirstU(*L));
}

void DelLastU (ListU *L, addressU *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* LastU element baru adalah predesesor elemen pertama yg lama, jika ada */
{
/* Kamus */
/* Algoritma */
    *P = LastU(*L);
    if (NextU(FirstU(*L))==Nil){
        CreateEmptyU(L);
    }
    else {
        LastU(*L) = PrevU(LastU(*L));
        NextU(LastU(*L)) = Nil;
        PrevU(*P) = Nil;
        NextU(*P) = Nil;
    }
}

void DelAfterU (ListU *L, addressU *Pdel, addressU Prec)
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus NextU(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
/* Kamus */
/* Algoritma */
	*Pdel=NextU(Prec);
	if(*Pdel!=Nil)
	{
		NextU(Prec)=NextU(*Pdel);
	}
    /*if(NextU(NextU(Prec))!=Nil){
        *Pdel=NextU(Prec);
        NextU(Prec)=NextU(*Pdel);
        PrevU(NextU(*Pdel))=Prec;
        NextU(*Pdel)=Nil;
        PrevU(*Pdel)=Nil;
    }
    else{
        DelLastU(L, Pdel);
    }*/
}

void DelBeforeU (ListU *L, addressU *Pdel, addressU Succ)
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus PrevU(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
/* Kamus */
/* Algoritma */
    *Pdel = PrevU(Succ);
    if (*Pdel == FirstU(*L)) {
        DelFirstU(L,Pdel);
    }
    else {
        if (*Pdel!=Nil){
            PrevU(Succ) = PrevU(*Pdel);
            NextU(PrevU(*Pdel)) = Succ;
            PrevU(*Pdel) = Nil;
            NextU(*Pdel) = Nil;
        }
    }
}

void PrintListU (ListU L)
/* Prosedur ini digunakan untuk melakukan print List of Unit */
/* I.S. : L sembarang */
/* F.S : Tercetak list of unit */
{
/* Kamus */
    addressU P;
    int i;
    Unit U;
    POINT T ;
/* Algoritma */
    printf("== List of Units ==\n");
    if (!IsEmptyU(L)){
        P = FirstU(L);
        i = 1;
        while (P!=Nil){
            U = InfoU(P);
            T = GetLocation(U);
            printf("%d. ", i);
            if (U.id == 1) {
                printf("King (%d,%d) | Health %d/%d \n", T.X, T.Y, U.health, U.max_health);
            }
            else {
                if (U.id ==2 ){
                    printf("Archer (%d,%d) | Health %d/%d \n", T.X, T.Y, U.health, U.max_health);
                }
                else {
                    if (U.id ==3){
                        printf("Swordsman (%d,%d) | Health %d/%d \n", T.X, T.Y, U.health, U.max_health);
                    }
                    else {
                        if (U.id == 4){
                            printf("White Mage (%d,%d) | Health %d/%d \n", T.X, T.Y, U.health, U.max_health);
                        }
                    }
                }
            }
            P = NextU(P);
            i++;
        }
    }
} 
