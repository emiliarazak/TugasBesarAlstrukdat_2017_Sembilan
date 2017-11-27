#include <stdio.h>
#include "player.h"
#include "unit.h"
#include "map.h"
#include "queue.h"
#include "stacklist.h"
#include "listpoint.h"

Player P1;
Player P2;

void CreatePlayer (Player *P,int id)
{
/* Kamus */
    Unit k;
/* Algoritma */
    Gold(*P)= 5000;
    CreateEmptyU(&Units(*P));
    CreateKing(&k);
    k.location=getTowerPoint(id);
    FirstU(Units(*P))=AlokasiU(k);
    CreateEmptyP(&Villages(*P));
    Income(*P)=0;
    UpKeep(*P)=0;
    Id(*P)=id;
    CurrentUnit(*P)=k;
}

void PrintAttribute (Player P)
{
/* Kamus */
/* Algoritma */
    printf ("Cash: %dG | Income: %dG | Upkeep: %dG\n", Gold(P),Income(P),UpKeep(P));
}


void GenerateUpkeep(Player *P)
/* Menghitung jumlah upkeep saat ini*/
{
/* Kamus */
    int sum ;
    addressU Pt;
/* Algoritma */
    sum = 0;
    Pt = FirstU(Units(*P));
    while (Pt != Nil){
        sum += GetUpKeepPrice(InfoU(Pt));
        Pt = NextU(Pt);
    }
    UpKeep(*P)=sum;
}

void GenerateIncome(Player *P)
{
    int sum=0;
    addressP Pt;
    Pt=FirstP(Villages(*P));
    while(Pt!=Nil){
        sum+=10;
        Pt=NextP(Pt);
    }
    Income(*P)=sum;
}

void PrintCurrentUnit(Player P)
/* Print unit yang sedang dipilih */
{
/* Kamus */
/* Algoritma */
    PrintUnit(CurrentUnit(P));
}

void Recruit (Player *P)
/* Command recruit */
{
/* Kamus */
    int x,y,id;
    int unit_id;
    Unit U;
/* Algoritma */
    if (IsKingInTower(Id(*P))){
        do {
            printf("\n");
            printf("Enter coordinate of empty castle: ");
            scanf("%d %d", &x, &y);
            id = getBangunanOwner(x,y);
            if (!IsCastleEmpty(x,y)||(id != Id(*P))){
                printf("The coordinate you give is not right\n");
                printf("You have to input a coordinate of your empty castle!\n");
                printf("\n");
            }
        } while (!IsCastleEmpty(x,y)||(id!=Id(*P)));

        printf("=== List of Recruits ===\n");
        printf("1. Archer || Health 500 || Attack 200 || Evasion 60%% || Movement Points 3 || Price 250 G \n");
        printf("2. Swordsman || Health 800 || Attack 300 || Evasion 20%% || Movement Points 4 || Price 200 G \n");
        printf("3. White Mage || Health 500 || Attack 100 || Evasion 10%% || Movement Points 5 || Price 400 G \n");

        printf("Enter no. of unit you want to recruit: ");
        do{
            scanf("%d", &unit_id);
            if(unit_id<1 || unit_id>3){
                printf("That's not a valid number, try again!!\nEnter no. of unit you want to recruit: ");
            }
        }while(unit_id <1 || unit_id >3);

        if(unit_id==1){
            if(Gold(*P)>=250){
                CreateArcher(&U);
                SetLocation(&U,x,y);
                Gold(*P)-=250;
                (U).mov_points=0;
                InsVFirstU(&Units(*P), U);
                PrintListU(Units(*P));
                printf("You have successfully recruited Archer!\n");
                GenerateUpkeep(P);
            }
            else{
                printf("You don't have enough money.\n");
            }
        }
        else {
                if(unit_id==2){
                    if(Gold(*P)>=200){
                        CreateSwordsman(&U);
                        SetLocation(&U, x, y);
                        Gold(*P)-=200;
                        (U).mov_points=0;
                        InsVFirstU(&Units(*P), U);
                        printf("You have successfully recruited Swordsman!\n");
                        GenerateUpkeep(P);
                    }
                    else{
                        printf("You don't have enough money.\n");
                    }
                }
                else {
                        if(unit_id==3){
                            if(Gold(*P)>=400){
                                CreateWhiteMage(&U);
                                SetLocation(&U, x,y);
                                Gold(*P)-=400;
                                (U).mov_points=0;
                                InsVFirstU(&Units(*P), U);
                                printf("You have successfully recruited White Mage\n");
                                GenerateUpkeep(P);
                            }
                            else{
                                printf("You don't have enough money.\n");
                            }
                        }
                    }
                }
        UpdateUnitMap(U.location,U.id,(*P).id);
    }
    else printf("Your King is not in the tower\n");
}

void ChangeUnit(Player *P)
/* Menampilkan secara rinci unit yang dimiliki pemain dan pemain dapat memilih unit */
{
/* Kamus */
    int i ;
    addressU Pt;
    int unit_id;
    boolean found ;
/* Algoritma */
    i = 1;
    Pt = FirstU(Units(*P));
    printf("\n=== List of Units ===\n");
    while(Pt!=Nil){
        printf("%d. ", i);
        PrintUnit(InfoU(Pt));
        printf("\n");
        i ++ ;
        Pt = NextU(Pt);
    }
    do {
        printf("\nPlease enter the no of unit you want to select: ");
        scanf("%d", &unit_id);
        i = 1;
        Pt = FirstU(Units(*P));
        found = false;
        while(Pt!=Nil && !found){
            if(i == unit_id){
                found = true;
            }
            else{
                i ++ ;
                Pt = NextU(Pt);
            }
        }
        if (found) {
            printf("You are now selecting ");
            if(InfoU(Pt).id==1){
                printf("King.\n");
            }
            else if(InfoU(Pt).id==2){
                printf("Archer.\n");
            }
            else if(InfoU(Pt).id==3){
                printf("Swordsman.\n");
            }
            else if(InfoU(Pt).id==4){
                printf("White Mage.\n");
            }
            UpdateGiliranUnitMap(CurrentUnit(*P).location,false);
            CurrentUnit(*P)=InfoU(Pt);
            UpdateGiliranUnitMap(CurrentUnit(*P).location,true);
        }
        else {
            printf("The no of unit you're selecting is not in the list of unit\n");
            printf("Enter the no of unit again!\n");
        }
    } while (!found);
}


void Move(Player *P) {
    boolean tembus;
    int x,y,i,jarak;
    POINT coordinate;
    if (CurrentUnit(*P).mov_points == 0){
        printf("You have no movement points! Change to other unit!\n");
    }
    else {
        PrintMap();
        do
        {
            printf("Please enter cell's coordinate x y: ");
            scanf("%d %d", &x, &y);
            if (x<0 || x> M.NAbsisEff || y<0 || y>M.NOrdEff){
                printf("The cell's coordinate you entered is not in the map!\n");
                printf("Enter the cell's coordinate in range of map\n");
            }
        }
        while (x<0 || x> M.NAbsisEff || y<0 || y>M.NOrdEff);
        coordinate=MakePOINT(x,y);
        if (IsNoUnit(x,y))
        {
            if(x==Absis(CurrentUnit(*P).location))
            {
                jarak=abs(Ordinat(CurrentUnit(*P).location)-y);
                if(jarak<=CurrentUnit(*P).mov_points)
                {
                    tembus = false;
                    i=Ordinat(CurrentUnit(*P).location);
                    while (!tembus && i!=y)
                    {
                        if(y<i) i--;
                        else i++;
                        if(!IsNoUnit(x,i)) tembus=true;
                    }
                    if (!tembus)
                    {
                        Push (&S,CurrentUnit(*P).location);
                        UpdateUnitMap(CurrentUnit(*P).location,0,0);
                        SetLocation(&CurrentUnit(*P),x,y);
                        CurrentUnit(*P).mov_points-=jarak;
                        printf("You have successfully moved to ");
                        TulisPOINT (coordinate);
                        printf("\n");
                        UpdateUnitMap(coordinate, CurrentUnit(*P).id,Id(*P));
                        if(getBangunanId(x,y)==3)
			{
				CurrentUnit(*P).mov_points=0;
				AkuisisiVillage(P,coordinate);
    		    	}
                    }
                    else printf("You can't move there\n");
                }
                else printf("You can't move there\n");
            }
            else if(y==Ordinat(CurrentUnit(*P).location))
            {
                jarak=abs(Absis(CurrentUnit(*P).location)-x);
                if(jarak<=CurrentUnit(*P).mov_points)
                {
                    tembus = false;
                    i=Absis(CurrentUnit(*P).location);
                    while (!tembus && i!=x)
                    {
                        if(x<i) i--;
                        else i++;
                        if(!IsNoUnit(i,y)) tembus=true;
                    }
                    if (!tembus)
                    {
                        Push (&S,CurrentUnit(*P).location);
                        UpdateUnitMap(CurrentUnit(*P).location,0,0);
                        SetLocation(&CurrentUnit(*P),x,y);
                        CurrentUnit(*P).mov_points-=jarak;
                        printf("You have successfully moved to ");
                        TulisPOINT (coordinate);
                        printf("\n");
                        UpdateUnitMap(coordinate, CurrentUnit(*P).id,Id(*P));
                        if(getBangunanId(x,y)==3)
			{
				CurrentUnit(*P).mov_points=0;
				AkuisisiVillage(P,coordinate);
    		    	}
                    }
                    else printf("You can't move there\n");
                }
            }
            else printf("You can't move there\n");
        }
        else
        {
            printf("You can't move there\n");
        if(getUnitOwner(x,y)==Id(*P)) printf("Your ");
        else printf("Enemy's ");
        if(getUnitId(x,y)==1) printf("King ");
        else if(getUnitId(x,y)==2) printf("Archer ");
        else if(getUnitId(x,y)==3) printf("Swordsman ");
        else printf("White Mage");
        printf("is there\n");
        }
    }
}

void Undo(Player *P)
{
/* Kamus */
    infotypeS X;
    int x,y,jarak;
/* Algoritma */
    if(!IsEmpty(S))
    {
        Pop(&S,&X);
        x = Absis(X);
        y = Ordinat(X);
        jarak = abs(Ordinat(CurrentUnit(*P).location)-y)+abs(Absis(CurrentUnit(*P).location)-x);
        UpdateUnitMap(CurrentUnit(*P).location, 0, 0);
        UpdateUnitMap(MakePOINT(x,y), CurrentUnit(*P).id,Id(*P));
        SetLocation(&CurrentUnit(*P),x,y);
        CurrentUnit(*P).mov_points+=jarak;
    }
    else
    {
        printf("You can't move back\n");
    }
}

/* DEBO edit yang info sama Turn, tolong dicekk yaa thankss :) */
void InfoMap (){
/* Kamus */
    int x, y;
    ElType I ;
/* Algoritma */
    do {
        printf("Enter the coordinate of the cell: "); scanf("%d %d", &x, &y);
        if ((x>M.NAbsisEff) || (x<0) || (y>M.NOrdEff || (y<0))) {
            printf("You have to enter the coordinate x in range of [0..%d] and coordinate y in range of [0..%d]\n", M.NAbsisEff, M.NOrdEff);
        }
    } while ((x>M.NAbsisEff) && (x<0) && (y>M.NOrdEff) && (y<0));
    I = getElmt(x,y);
    printf("\n");
    printf("== Cell Info ==\n");
    switch (I.bangunan.id) {
        case 1 : printf("Tower\n"); break ;
        case 2 : printf("Castle\n"); break ;
        case 3 : printf("Village\n"); break ;
        case 0 : printf("There is no building\n"); break ;
    }
    switch (I.bangunan.pemilik) {
        case 1 : printf("Owned by Player 1\n"); break ;
        case 2 : printf("Owned by Player 2\n"); break ;
        case 0 : if (I.bangunan.id >0 ){printf("No one own this village\n");}; break ;
    }
    printf("\n");
    printf("== Unit Info ==\n");
    switch (I.unit.id) {
        case 1 : printf("King\n"); break;
        case 2 : printf("Archer\n"); break;
        case 3 : printf("Swordsman\n"); break;
        case 4 : printf("White Mage\n"); break;
        case 0 : printf("There is no unit in here\n"); break ;
    }
    switch (I.unit.pemilik) {
        case 1 : printf("Owned by Player 1\n"); break;
        case 2 : printf("Owned by Player 2\n"); break;
        case 0 : break;
    }
}

void AkuisisiVillage(Player *P, POINT Loc)
{
    if (getBangunanOwner(Absis(Loc),Ordinat(Loc))==0)
    {
        UpdateBangunanMap(Loc,3,Id(*P));
        InsVFirstP(&Villages(*P),Loc);
        GenerateIncome(P);
    }
}

void NextUnit(Player *P){
    Unit U = CurrentUnit(*P);
    addressU A = FirstU(Units(*P));
    boolean found = false;
    while (A!=Nil && !found){ // mencari A
        if (EQ(U.location,InfoU(A).location)){
            found = true;
        }
        else {
            A = NextU(A);
        }
    }
    if (NextU(A)!=Nil){//dia bukan di akhir
        A=NextU(A);
        while (NextU(A)!=Nil && ((!InfoU(A).atk_chance) && InfoU(A).mov_points==0)){
            A = NextU(A);
        }
	if(InfoU(A).mov_points!=0 || InfoU(A).atk_chance) CurrentUnit(*P) = InfoU(A);
    }
    else { //kalau sudah di akhir, kembali ke first dulu
        A = FirstU(Units(*P));
        if(InfoU(A).mov_points == 0 && !InfoU(A).atk_chance){
            do{
                A = NextU(A);
            } while(A != Nil && (InfoU(A).mov_points == 0 && (!InfoU(A).atk_chance)));
            if(A == Nil || EQ(InfoU(A).location,CurrentUnit(*P).location)){
                printf("You have no available unit \n");
            }else{
                CurrentUnit(*P) = InfoU(A);
            }
        }else{
            CurrentUnit(*P) = InfoU(A);
        }
    }
}

void RecoverGoldMove (Player *P)
{
    addressU Pt;
    Pt= FirstU(Units(*P));
    while(Pt!=Nil)
    {
        InfoU(Pt).mov_points=InfoU(Pt).max_mov_points;
        Pt=NextU(Pt);
    }
    Gold(*P)=Gold(*P)+Income(*P)-UpKeep(*P);
}
