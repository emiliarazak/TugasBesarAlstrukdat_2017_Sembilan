/* Nama		: Deborah Aprilia Josephine */
/* NIM		: 13516152 */
/* Topik	: Mesin Kata */
/* Tanggal	: 28 September 2017 */
/* Deskripsi: Digunakan untuk menghitung biaya telegram */

#include <stdio.h>
#include "boolean.h"
#include "mesinkar.h"
#include "mesinkata.h"

/* Kamus */
	int countreg, countpjg, i, total;
	Kata titik, koma ;
	int harga ;

/* Algoritma */
int main (){
	/* Kata TITIK */
	titik.TabKata[1] = 'T';
	titik.TabKata[2] = 'I';
	titik.TabKata[3] = 'T';
	titik.TabKata[4] = 'I';
	titik.TabKata[5] = 'K';
	titik.Length=5;

	/* Kata KOMA */
	koma.TabKata[1] = 'K';
	koma.TabKata[2] = 'O';
	koma.TabKata[3] = 'M';
	koma.TabKata[4] = 'A';
	koma.Length=4;

	countpjg = 0;
	countreg = 0;
	total = 0 ;
	
	STARTKATA();
	while (!EndKata) {
		total += 1;
		if (IsKataSama(CKata,titik)){
			printf(".");
		}
		else{
		      if (IsKataSama(CKata,koma)){
					printf(","); 
		      }
		      else{
					if (CKata.Length>=10){
						countpjg +=1;
					}
					else{
						countreg +=1;
					}

					for (i=1;i<=CKata.Length;i++){
						printf("%c", CKata.TabKata[i]);
					}
		      }
		}
		
		ADVKATA();
		if ((!EndKata)&&(!IsKataSama(CKata,titik))&&(!IsKataSama(CKata,koma))){
			printf(" ");
		}
	}
	
	printf("\n");
	printf("%d\n",countreg);
	printf("%d\n",countpjg);
	if (total>10){
		harga = (((countreg*1000)+(countpjg*1500))*0.9);
		printf("%d", harga);
	}
	else{
		harga = ((countreg*1000)+(countpjg*1500));
		printf("%d", harga);
	}
	
	printf("\n");

	return 0;	
}
