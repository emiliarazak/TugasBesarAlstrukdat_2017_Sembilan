/**
Filename: map.c (implementation of map.h)
Prepared by: Intan Nurjanah / 13516131
Created at: 16/11/2017
**/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "map.h"
#include "pcolor.h"

Map M;

/*** Selektor ***/
ElType getElmt(int x, int y){
/* Mengembalikan element dari di petak x dan y */	
	return M.Mem[x][y];
}

int getBangunanId(int x, int y){
/* Mengembalikan id bangunan di petak x dan y */
	return M.Mem[x][y].bangunan.id;
}

int getBangunanOwner(int x, int y){
/* Mengembalikan pemilik bangunan di petak x dan y */
	return M.Mem[x][y].bangunan.pemilik;
}

int getUnitId(int x, int y){
/* Mengembalikan id unit di petak x dan y */
	return M.Mem[x][y].unit.id;
}

int getUnitOwner(int x, int y){
/* Mengembalikan pemilik unit di petak x dan y */
	return M.Mem[x][y].unit.pemilik;
}

void MakeEmptyMap(int X, int Y){
/* Membuat petak normal sebanyak X * Y */
	int i,j;
	
	M.NAbsisEff = X;
	M.NOrdEff = Y;
	for(i = AbsisMin; i < M.NAbsisEff; i++){
		for(j = OrdMin; j < M.NOrdEff; j++){
			UpdateBangunanMap(MakePOINT(i, j), 0, 0);
			UpdateUnitMap(MakePOINT(i, j), 0, 0);
		}
	}
}

void InitMap(int X, int Y){
/* I.S: Ukuran Map terdefinisi */
/* Membuat Map untuk state awal permainan */	
	int cX, cY, i;
	MakeEmptyMap(X, Y);
	/* buat kerajaan player 1, ujung kiri-bawah */
	cX = AbsisMin + 1;
	cY = M.NOrdEff - 2;
	setBangunanKerajaan(cX, cY, 2);
	
	/* buat kerajaan player 2, ujung kanan-atas */
	cX = M.NAbsisEff - 2;
	cY = OrdMin + 1;
	setBangunanKerajaan(cX, cY, 1);
	
	setVillage(M.NOrdEff - 2);
}

void PrintMap(){
/* Mencetak Map secara keseluruhan */
	int i, j;
	printf("    ");
	for(j = OrdMin; j < M.NOrdEff; j++){
		PrintAngkaOrdinat(j);
	} printf("\n");
	for(i = AbsisMin; i < M.NAbsisEff; i++){
		printf("    ");
		for(j = OrdMin; j < M.NOrdEff; j++){
			printf("****"); /* garis atas */
		} printf("*\n    * ");
		for(j = OrdMin; j < M.NOrdEff; j++){ /* bangunan */
			printBangunan(getElmt(i, j).bangunan);
			printf(" * ");
		} 
		printf("\n");
		PrintAngkaAbsis(i); /* absis/baris */
		printf("* ");
		for(j = OrdMin; j < M.NOrdEff; j++){ /* unit */
			printUnit(getElmt(i, j).unit);
			printf(" * ");
		} printf("\n    *");
		for(j = OrdMin; j < M.NOrdEff; j++){ /* space */
			printf("   *");
		}
		printf("\n");
	}printf("    ");
	for(j = OrdMin; j < M.NOrdEff; j++){
		printf("****"); /* garis terbawah */
	} printf("*\n");
}

void PrintAngkaAbsis(int X){
/* Menampilkan angka yang ada disebelah kiri map */
	if(getDigit(X) == 2){
		printf(" %d ", X);
	}else{
		printf("  %d ", X);
	}
}

void PrintAngkaOrdinat(int Y){
/* Menampilkan angka diatas Map */
	if(getDigit(Y)==2){
		printf("  %d", Y);
	}else{
		printf("   %d", Y);
	}
}

void printBangunan(BangunanMap bangunan){
/* Mencetak bangunan dengan warna tertentu */
	char b;
	b = getId(1, bangunan.id);
	switch(bangunan.pemilik){
		case 1: print_blue(b); break;
		case 2: print_red(b); break;
		default: printf("%c", b); break;
	}
}

void printUnit(UnitMap unit){
/* Mencetak unit dengan warna tertentu */	
	char b;
	b = getId(2, unit.id);
	if(unit.giliran){
		print_green(b);
	}else{
		switch(unit.pemilik){
			case 1: print_blue(b); break;
			case 2: print_red(b); break;
			default: printf("%c", b); break;
		}
	}
}

void UpdateUnitMap(POINT P, int newId, int pemilik){
/* I.S: map sudah diinisialisasi */
/* x dan y adalah posisi absis dan ordinat yang baru */
/* newId adalah id unit yang baru */
/* isi dari newId: (1) King, (2) Archer, (3) Swordsman, (4) White Mage, (0) blank */
/* Mengubah posisi dari unit yang ada di map */
	(M).Mem[Absis(P)][Ordinat(P)].unit.id = newId;
	(M).Mem[Absis(P)][Ordinat(P)].unit.pemilik = pemilik;
}

void UpdateGiliranUnitMap(POINT P, boolean giliran){
/* Mengganti giliran dari unit pada point P */
	(M).Mem[Absis(P)][Ordinat(P)].unit.giliran = giliran;
}

void UpdateBangunanMap(POINT P, int newId, int pemilik){
/* I.S: map sudah diinisialisasi */
/* x dan y adalah posisi absis dan ordinat yang baru */
/* newId adalah id bangunan yang baru */
/* isi dari newId: (1) Tower, (2) Castel, (3) Village, (0) blank */
/* Mengubah posisi dari bangunan yang ada di map */
	(M).Mem[Absis(P)][Ordinat(P)].bangunan.id = newId;
	(M).Mem[Absis(P)][Ordinat(P)].bangunan.pemilik = pemilik;
}

void setBangunanKerajaan(int cX, int cY, int playerId){
/* membuat bangunan kerajaan milik player dengan id playerId */
/* cX adalah absis tower dan cY adalah ordinat tower */
	/* castle */
	UpdateBangunanMap(MakePOINT(cX, cY - 1), 2, playerId);
	UpdateBangunanMap(MakePOINT(cX, cY + 1), 2, playerId);
	UpdateBangunanMap(MakePOINT(cX - 1, cY), 2, playerId);
	UpdateBangunanMap(MakePOINT(cX + 1, cY), 2, playerId);
	/* tower */
	UpdateBangunanMap(MakePOINT(cX, cY), 1, playerId);
	/* king */
	UpdateUnitMap(MakePOINT(cX, cY), 1, playerId);
}

void setVillage(int numVillage){
/* I.S: ukuran peta sudah diinisialisasi */
/* meletakkan village tanpa pemilik secara random 
   tanpa mengganggu letak kerajaan */
    int i;
    for(i = 0; i < numVillage; i++){
		UpdateBangunanMap(getRandomPoint(), 3, 0);
	}
}

POINT getRandomPoint(){
/* mencari point yang masih kosong secara random */
	int x, y;
	
    srand(time(NULL));
    x = M.NAbsisEff - 2;
	y = OrdMin + 1;
    while(getBangunanId(x, y) != 0){
		x = rand() % (M.NAbsisEff - 1);
		y = rand() % (M.NOrdEff - 1);
	}
	return MakePOINT(x, y);
}

char getId(int tipe, int id){
/* Mengembalikan tanda untuk bangunan atau unit */
	char c;
	if(tipe == 1){ // untuk bangunan
		switch(id){
			case 1: c = 'T'; break;
			case 2: c = 'C'; break;
			case 3: c = 'V'; break;
			default : c = ' '; break;
		}
	}else if(tipe == 2){ // untuk unit
		switch(id){
			case 1: c = 'K'; break;
			case 2: c = 'A'; break;
			case 3: c = 'S'; break;
			case 4: c = 'W'; break;
			default : c = ' '; break;
		}
	}
	return c;
}

int getDigit(int X){
/* Menghasilkan digit dari X */
	int N = X;
	int Digit = 0;
	if(N == 0){
		Digit=1;
	}else{
		while(N > 0){
			N = N / 10;
			Digit++;
		}
	}
	return Digit;	
}

/*** Untuk keperluan move ***/
boolean IsPosisiTerkiri(POINT P){
/* Mengembalikan true bila posisi (x, _) ada di pinggir kiri map */
/* tapi bukan di ujung map */
	return (Ordinat(P) == OrdMin && !IsPosisiUjung(P));
}

boolean IsPosisiTerkanan(POINT P){
/* Mengembalikan true bila posisi (x, _) ada di pinggir kanan map */
/* tapi bukan di ujung map */
	return (Ordinat(P) == (M.NOrdEff-1) && !IsPosisiUjung(P));
}

boolean IsPosisiPalingAtas(POINT P){
/* Mengembalikan true bila posisi (_, y) ada di paling atas map */
/* tapi bukan di ujung map */
	return (Absis(P) == AbsisMin && !IsPosisiUjung(P));
}

boolean IsPosisiPalingBawah(POINT P){
/* Mengembalikan true bila posisi (_, y) ada di paling bawah map */
/* tapi bukan di ujung map */
	return (Absis(P) == (M.NAbsisEff-1) && !IsPosisiUjung(P));
}

boolean IsPosisiUjung(POINT P){
/* Mengembalikan true bila posisi (x, y) ada di ujung map */
	return ((Absis(P) == AbsisMin || Absis(P) == (M.NAbsisEff-1)) && 
		(Ordinat(P) == OrdMin || Ordinat(P) == (M.NOrdEff-1)));
}

boolean IsKingInTower(int playerId){
/* Mengembalikan true jika King berada di tower miliknya */
	int cX, cY; 
	if(playerId == 1){
		cX = M.NAbsisEff - 2;
		cY = OrdMin + 1;
	}else{
		cX = AbsisMin + 1;
		cY = M.NOrdEff - 2;
	} return (getUnitId(cX, cY) == 1); // king ada di tower
}

boolean IsCastleEmpty(int x, int y){
/* Memeriksa apakah castle tersebut kosong */
	return (getUnitId(x, y) == 0) && (getBangunanId(x, y) == 2);
}

boolean IsNoUnit(int x, int y){
/* Mengembalikan true bila dalam x dan y tidak ada unit */	
	return (getUnitId(x, y) == 0);
}

POINT * getCastle(int id){
/* Mengembalikan castle yang dimiliki oleh player dengan id tertentu */
/* untuk next update.. */
	POINT * castle;
	int i, j, k;
	k = 0;
	for(i = AbsisMin; i < M.NAbsisEff ; i++){
		for(j = OrdMin; j < M.NOrdEff; j++){
			if(getBangunanId(i, j) == 2 && getBangunanOwner(i, j) == id){
				castle[k] = MakePOINT(i, j);
			}
		}
	}
	return castle;
}

POINT getKingPoint(int playerId){
/* Mengembalikan point <x,y> dimana King milik playerId berada */
	POINT P;
	int i, j;
	P = MakePOINT(0, 0);
	for(i = 0; i < M.NAbsisEff; i++){
		for(j = 0; j < M.NOrdEff; j++){
			if(getUnitId(i, j) == 1){
				if(getUnitOwner(i, j) == playerId)
					P = MakePOINT(i, j);
			}
		}
	}
	return P;
}

POINT getTowerPoint(int playerId){
/* Mengembalikan point <x,y> dimana tower milik playerId berada */
	int cX, cY; 
	if(playerId == 1){
		cX = M.NAbsisEff - 2;
		cY = OrdMin + 1;
	}else{
		cX = AbsisMin + 1;
		cY = M.NOrdEff - 2;
	}
	return MakePOINT(cX, cY);
}
