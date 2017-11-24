#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "boolean.h"
#include "mesinkar.h"

#define NMax 50
#define BLANK ' '

typedef struct {
	char TabKata[NMax+1]; /* container penyimpan kata, indeks yang dipakai [1..NMax] */
    int Length;
} Kata;

/* State Mesin Kata */
boolean EndKata;
Kata CKata;

void IgnoreBlank(){
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
	while ((CC == BLANK)&&(CC != MARK))
		ADV();
}

void SalinKata(){
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
	int i = 1;
	while ((i<=NMax)&&(CC!=MARK)&&(CC!=BLANK)){
		CKata.TabKata[i] = CC;
		ADV();
		i++;
	}
	CKata.Length = i-1;
	IgnoreBlank();
}

void STARTKATA(){
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
	START();
	IgnoreBlank();
	EndKata = (CC == MARK);
	if (!(EndKata))
		SalinKata();
}

void ADVKATA(){
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */
	IgnoreBlank();
	if (CC==MARK)
		EndKata = true;
	else
		SalinKata();
}

boolean IsKataSama (Kata K1, Kata K2){
/* Mengembalikan true jika K1 = K2; dua kata dikatakan sama jika
   panjangnya sama dan urutan karakter yang menyusun kata juga sama.
   Dua kata kosong adalah kata yang sama. */
   int i;
   boolean issama = true;
   if (K1.Length == K2.Length){
	   i = 1;
	   while ((i<=K1.Length)&&issama){
		   if ((K1.TabKata[i])!=(K2.TabKata[i])){
			   issama = false;
		   }
		   else i++;
	   }
   }
   else issama = false;

   return issama;
}

#endif
