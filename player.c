#include <stdio.h>
#include "player.h"
#include "unit.h"
#include "listunit.h"
#include "map.h"
#include "queue.h"
#include "stacklist.h"
//#include "listpoint.h"

void CreatePlayer (Player *P)
{
/* Kamus */
    Unit k;
/* Algoritma */
    Gold(*P)= 5000;
    CreateEmptyU(&Units(*P));
    CreateKing(&k);
    FirstU(Units(*P))=AlokasiU(k);
    CreateEmptyP(&Villages(*P));
    Income(*P)=0;
    UpKeep(*P)=0;
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


void PrintCurrentUnit(Player P) 
/* Print unit yang sedang dipilih */
{
/* Kamus */
/* Algoritma */
    printf("Unit: ");
    PrintUnit(CurrentUnit(P));
}

void Recruit (Player *P) 
/* Command recruit */
{
/* Kamus */
    int x,y;
    int unit_id;
    Unit U;
/* Algoritma */
    if (IsKingInTower(Id(*P))){
        do {
            printf("Enter coordinate of empty castle: ");
            scanf("%d %d", &x, &y);
        } while (!IsCastleEmpty(x,y));
        
        printf("=== List of Recruits ===\n");
        printf("1. Archer | Health 500 | Attack 200 | Evasion 60% | Movement Points 3 | Price 250 G \n");
        printf("2. Swordsman | Health 800 | Attack 300 | Evasion 20% | Movement Points 4 | Price 200 G \n");
        printf("3. White Mage | Health 500 | Attack 100 | Evasion 10% | Movement Points 5 | Price 400 G \n");
        
        printf("Enter no. of unit you want to recruit: ");
        do{
            scanf("%d", &unit_id);
            if(unit_id<1 || unit_id>3){
                printf("That's not a valid number, try again!!\n");
            }
        }while(unit_id <1 || unit_id >3);

        if(unit_id==1){
            if(Gold(*P)>=250){
                CreateArcher(&U);
                SetLocation(&U,x,y);
                Gold(*P)-=250;
                (U).mov_points=0;
                printf("You have successfully recruited Archer!\n");
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
                        printf("You have successfully recruited Swordsman!\n");
                    }
                    else{
                        printf("You don't have enough money.\n");
                    }
                }
                else {   
                        if(unit_id=3){
                            if(Gold(*P)>=400){
                                CreateWhiteMage(&U);
                                SetLocation(&U, x,y);
                                Gold(*P)-=400;
                                (U).mov_points=0;
                                printf("You have successfully recruited White Mage\n");
                            }
                            else{
                                printf("You don't have enough money.\n");
                            }
                        }
                    }
                }
        InsVLastU(&Units(*P), U);
    }
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
    printf("===List of Units===\n");
    while(Pt!=Nil){
        printf("%d. ", i);
        PrintUnit(InfoU(Pt));
        Pt = NextU(Pt);
    }
    
    printf("Please enter the no of unit you want to select: ");
    scanf("%d", &unit_id);
    i = 1;
    Pt = FirstU(Units(*P));
    found = false;
    while(Pt!=Nil && !found){
        if(i == unit_id){
            found = true;
        }
        else{
            Pt = NextU(Pt);
        }
    }
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
    CurrentUnit(*P)=InfoU(Pt);
}


void Move(Player *P, Map M) {
/* Melakukan move terhadap current unit */
/* Kamus */
    int x,y;
    Stack S ;
    POINT coordinate;
/* Algoritma */
    PrintMap(M);
    printf("Please enter cell's coordinate x y: ");
    scanf("%d %d", &x, &y);
    if (IsNoUnit(x,y))
    {
        coordinate = MakePOINT(x,y);
        Push(&S,coordinate);
        MoveUnit(&CurrentUnit(*P),coordinate);
        printf("You have successfully moved to ");
        TulisPOINT (coordinate);
        printf("\n");
    }
    else
    {
        printf("You can’t move there\n");
    }
}

void Undo(Player *P)
{
/* Kamus */
    infotypeS X;
    int x,y;
/* Algoritma */
    if(!IsEmptyS(S))
    {
        Pop(&S,&X);
        x = Ordinat(X);
        y = Absis(X);
        SetLocation(&CurrentUnit(*P),x,y);
    }
    else
    {
        printf("You can't move back\n");
    }
}

/* DEBO edit yang info sama Turn, tolong dicekk yaa thankss :) */
void InfoMap (Map M){
/* Kamus */
    int x, y;
    ElType I ;
/* Algoritma */
    do {
        printf("Enter the coordinate of the cell: "); scanf("%d %d", &x, &y); 
        if ((x>AbsisEff(M)) || (x<0) || (y>OrdEff(M) || (y<0))) {
            printf("You have to enter the coordinate x in range of [0..%d] and coordinate y in range of [0..%d]\n", AbsisEff(M), OrdEff(M));
        }
    } while ((x>AbsisEff(M)) && (x<0) && (y>OrdEff(M)) && (y<0)); 
    I = getElmt(M,x,y);
    printf("== Cell Info ==\n");
    switch (I.bangunan.id) {
        case 1 : printf("Tower\n"); break ;
        case 2 : printf("Castle\n"); break ;
        case 3 : printf("Village\n"); break ;
        case 0 : printf("There is nothing here\n"); break ;
    }
    switch (I.bangunan.pemilik) {
        case 1 : printf("Owned by Player 1\n"); break ; 
        case 2 : printf("Owned by Player 2\n"); break ;
        case 0 : printf("No one own this cell\n"); break ;
    }

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
        case 0 : printf("No one own this cell\n"); break;
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

Player CurrentTurn (Queue QTurn)
/* Prosedur ini untuk mengembalikan player mana yang saat ini mendapat giliran bermain */ 
{
/* Kamus */
/* Algoritma */
    if (MaxEl(QTurn)!=0){
        return (Head(QTurn));
    }
}

void EndTurn (Queue QTurn)
/* Prosedur ini untuk melakukan pergantian giliran antar pemain */
{
/* Kamus */
    Player CurrPlayer;
/* Algoritma */
    CurrPlayer = CurrentTurn(QTurn);
    DelQ(&QTurn,&CurrPlayer);
    AddQ(&QTurn,CurrPlayer);
}