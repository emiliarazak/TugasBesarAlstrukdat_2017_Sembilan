
#include "queue.h"
#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

Queue QTurn;

/* ********* Prototype ********* */
boolean IsEmptyQ (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
    return ((Head(Q)==Nihil)&&(Tail(Q)==Nihil));
}

boolean IsFull (Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
    return (NBElmt(Q)==MaxEl(Q));
}

int NBElmt (Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
    if (IsEmptyQ (Q)) return 0;
    else if (Tail(Q)<Head(Q))
    {
        return (Tail(Q)-Head(Q)+1+MaxEl(Q));
    }
    else return (Tail(Q)-Head(Q)+1);
}

/* *** Kreator *** */
void CreateEmptyQ (Queue * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
    (*Q).T= (infotype*) malloc ((Max+1)*sizeof(infotype));
    if ((*Q).T!=NULL)
    {
        Head(*Q)=Nihil;
        Tail(*Q)=Nihil;
        MaxEl(*Q)=Max;
    }
    else MaxEl(*Q)=0;
}

/* *** Destruktor *** */
void DeAlokasi(Queue * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
    MaxEl(*Q)=0;
    free((*Q).T);
}

/* *** Primitif AddQ/DelQete *** */
void AddQ (Queue * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
{
    if (IsEmptyQ (*Q))
    {
        Head(*Q)=1;
    }
    Tail(*Q)=(Tail(*Q)+1);
    if (Tail(*Q)>MaxEl(*Q))
    {
        Tail(*Q)=Tail(*Q)%MaxEl(*Q);
    }
    InfoTail(*Q)=X;
}

void DelQ (Queue * Q, infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = Nihilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{
    *X=InfoHead(*Q);
    if(Head(*Q)==Tail(*Q))
    {
        Head(*Q)= Nihil;
        Tail(*Q)= Nihil;
    }
    else
    {
        Head(*Q)=(Head(*Q)+1);
        if (Head(*Q)>MaxEl(*Q))
        {
            Head(*Q)=Head(*Q)%MaxEl(*Q);
        }
    }
}

void CreateTurn (Queue *QTurn, Player P1, Player P2)
/* Prekondisi : P1 dan P2 sudah terisi atributnya */
/* Prosedur ini untuk membuat sebuah giliran yang pertama adalah giliran Player 1 dan yang kedua adalah giliran Player 2 */
{
/* Kamus */
/* Algoritma */
    CreateEmptyQ(QTurn,2);
    AddQ(QTurn,P1);
    AddQ(QTurn,P2);
}

Player CurrentTurn ()
/* Prosedur ini untuk mengembalikan player mana yang saat ini mendapat giliran bermain */
{
/* Kamus */
/* Algoritma */
    if (MaxEl(QTurn)!=0){
        return (InfoHead(QTurn));
    }
}

Player Enemy ()
/* Prosedur ini untuk mengembalikan player mana yang saat ini mendapat giliran bermain */
{
/* Kamus */
/* Algoritma */
    if (MaxEl(QTurn)!=0){
        return (InfoTail(QTurn));
    }
}

void EndTurn (Player *P)
/* Prosedur ini untuk melakukan pergantian giliran antar pemain */
{
    Player temp;
    DelQ(&QTurn,&temp);
    addressU U = FirstU(Units(*P));
    while (U!=Nil){
        InfoU(U).mov_points = InfoU(U).max_mov_points;
        InfoU(U).atk_chance = true; 
        U = NextU(U);
    }
    UpdateGiliranUnitMap(CurrentUnit(*P).location,false);
            AddQ(&QTurn,temp);
}
