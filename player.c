#include <stdio.h>
#include "player.h"
#include "unit.h"
#include "listunit.h"
//#include "listpoint.h"

void CreatePlayer (Player *P, char color)
{
    Unit k;
    Gold(*P)= 5000;
    CreateEmptyU(&Units(*P));
    CreateKing(&k);
    FirstU(Units(*P))=AlokasiU(k);
    CreateEmptyP(&Villages(*P));
    Income(*P)=0;
    UpKeep(*P)=0;
    Warna(*P)=color;
}

void PrintAttribute (Player P)
{   
    printf ("Cash: %dG | Income: %dG | Upkeep: %dG\n", Gold(P),Income(P),UpKeep(P));
}

//menghitung jumlah upkeep saat ini
void GenerateUpkeep(Player *P) {
    int sum=0;
    address Pt;
    Pt=FirstU(Units(*P));
    while(Pt!=Nil){
        sum+=GetUpKeepPrice(InfoU(Pt));
        Pt=NextU(Pt);
    }
    UpKeep(*P)=sum;
}

//print unit yang sedang dipilih
void PrintCurrentUnit(Player P) {
    printf("Unit: ");
    PrintUnit(CurrentUnit(P));
}

//Command recruit
void Recruit (Player *P) {
    //Cek King sedang berada pada tower//
    printf("Enter coordinate of empty castle: ");
    int x,y;
    //validasi empty castle//
    scanf("%d %d", &x, &y);

    printf("=== List of Recruits ===\n");
    printf("1. Archer | Health 500 | Attack 200 | Evasion 60% | Movement Points 3 | Price 250 G \n");
    printf("2. Swordsman | Health 800 | Attack 300 | Evasion 20% | Movement Points 4 | Price 200 G \n");
    printf("3. White Mage | Health 500 | Attack 100 | Evasion 10% | Movement Points 5 | Price 400 G \n");
    int unit_id;
    printf("Enter no. of unit you want to recruit: ");
    do{
        scanf("%d", unit_id);
        if(unit_id<1 || unit_id>3){
            printf("That's not a valid number, try again!!\n");
        }
    }while(unit_id<1 || unit_id>3);

    Unit U;
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
    else if(unit_id==2){
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
    else if(unit_id=3){
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
    InsVLastU(&Units(*P), U);
}
//Menampilkan secara rinci unit yang dimiliki pemain dan pemain dapat memilih unit
void ChangeUnit(Player *P) {
    int i=1;
    address Pt;
    Pt=FirstU(Units(*P));
    printf("===List of Units===\n");
    while(Pt!=Nil){
        printf("%d. ", i);
        PrintUnit(InfoU(Pt));
        Pt=NextU(Pt);
    }
    int unit_id;
    printf("Please enter the no of unit you want to select: ");scanf("%d", &unit_id);
    i=1;
    Pt=FirstU(Units(*P));
    boolean found=false;
    while(Pt!=Nil && !found){
        if(i==unit_id){
            found=true;
        }
        else{
            Pt=NextU(Pt);
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
//Melakukan move terhadap current unit
void Move(Player *P) {
    int x,y;
    printf("Please enter cell's coordinate x y: ");
    scanf("%d %d", &x, &y);
    //Validasi koordinat --butuh map
    POINT coordinate;
    coordinate=MakePOINT(x,y);
    MoveUnit(&CurrentUnit(*P), coordinate);
}

