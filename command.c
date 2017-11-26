#include <stdio.h>
#include "command.h"
#include "stacklist.h"

Kata ComStart;
Kata ComLoad;
Kata ComMove;
Kata ComUndo;
Kata ComChange_Unit;
Kata ComRecruit;
Kata ComAttack;
Kata ComMap;
Kata ComInfo;
Kata ComEnd_Turn;
Kata ComSave;
Kata ComExit;
Player P,P1,P2;
boolean end =false;

Stack S ;

void StartGame()
{
    int X,Y;
    do{
        printf("Enter the size of map (X Y): ");
        scanf("%d",&X);
        scanf("%d",&Y);
        if ((Y<8)||(X<8)||(Y>100)||(X>100)){
            printf("The minimum size is 8x8 and the maximum is 100x100\n");
        }
    }while((Y<8)||(X<8)||(Y>100)||(X>100));

    InitMap(X,Y);
    CreatePlayer(&P1,1);
    CreatePlayer(&P2,2);
    CreateTurn (&QTurn,P1,P2);
    P=CurrentTurn(QTurn);
    initialkata();
    openingturn();
    readcommand();
}

void openingturn ()
{
    if(end) CurrentUnit(P).mov_points=CurrentUnit(P).max_mov_points;
    printf("\n\n");
    UpdateGiliranUnitMap(CurrentUnit(P).location,true);
    printf("Player %d's Turn\n",Id(P));
    PrintAttribute (P);
    PrintUnit(CurrentUnit(P));
    printf("\nYour input : ");
}

void execute ()
{
    if(IsKataSama (CKata,ComMove))
    {
        boolean found=false;
        addressU Pt;
        POINT lokasiawal=CurrentUnit(P).location;
        Move(&P);
        Pt= FirstU(Units(P));
        while(Pt!=Nil && !found)
        {
            if(EQ(lokasiawal,InfoU(Pt).location))
            {
                InfoU(Pt).location=CurrentUnit(P).location;
                InfoU(Pt).mov_points=CurrentUnit(P).mov_points;
                found=true;
            }
            else Pt=NextU(Pt);
        }
        end=false;
    }
    else if(IsKataSama (CKata,ComUndo))
    {
        Undo(&P);
        end=false;
    }
    else if(IsKataSama (CKata,ComChange_Unit))
    {
    CreateEmpty (&S);
        ChangeUnit(&P);
        end=false;
    }
    else if(IsKataSama (CKata,ComRecruit))
    {
    CreateEmpty (&S);
        Recruit (&P);
        end=false;
    }
    else if(IsKataSama (CKata,ComAttack))
    {
    CreateEmpty (&S);
    Player E = Enemy();
    AttackAndRetaliate(&P, &E);
    UpdatePlayer(P);
    printf("P1: \n"); PrintUnit(CurrentUnit(P));printf("\n");
    UpdatePlayer(E);
    printf("P2: \n"); PrintUnit(CurrentUnit(E));printf("\n");
    addressU U;
    U=FirstU(Units(E));
    printf("P2 List after update player:\n");
    while(U!=Nil){
        PrintUnit(InfoU(U));printf("\n");
        U=NextU(U);
    }
    }
    else if(IsKataSama (CKata,ComMap))
    {
        PrintMap();
        end=false;
    }
    else if(IsKataSama (CKata,ComInfo))
    {
        InfoMap();
        end=false;
    }
    else if(IsKataSama (CKata,ComEnd_Turn))
    {
    CreateEmpty (&S);
        RecoverGoldMove(&P);
        EndTurn (&P);
        P=CurrentTurn(QTurn);
        end =true;
    }
    else if(IsKataSama (CKata,ComSave))
    {
    CreateEmpty (&S);
        end=false;
    }
    else printf("Invalid command\n\n");
}

void initialkata()
{
    ComStart.TabKata[1]='S';
    ComStart.TabKata[2]='t';
    ComStart.TabKata[3]='a';
    ComStart.TabKata[4]='r';
    ComStart.TabKata[5]='t';
    ComStart.Length=5;
    ComMove.TabKata[1]='M';
    ComMove.TabKata[2]='o';
    ComMove.TabKata[3]='v';
    ComMove.TabKata[4]='e';
    ComMove.Length=4;
    ComUndo.TabKata[1]='U';
    ComUndo.TabKata[2]='n';
    ComUndo.TabKata[3]='d';
    ComUndo.TabKata[4]='o';
    ComUndo.Length=4;
    ComChange_Unit.TabKata[1]='C';
    ComChange_Unit.TabKata[2]='h';
    ComChange_Unit.TabKata[3]='a';
    ComChange_Unit.TabKata[4]='n';
    ComChange_Unit.TabKata[5]='g';
    ComChange_Unit.TabKata[6]='e';
    ComChange_Unit.TabKata[7]='_';
    ComChange_Unit.TabKata[8]='U';
    ComChange_Unit.TabKata[9]='n';
    ComChange_Unit.TabKata[10]='i';
    ComChange_Unit.TabKata[11]='t';
    ComChange_Unit.Length=11;
    ComRecruit.TabKata[1]='R';
    ComRecruit.TabKata[2]='e';
    ComRecruit.TabKata[3]='c';
    ComRecruit.TabKata[4]='r';
    ComRecruit.TabKata[5]='u';
    ComRecruit.TabKata[6]='i';
    ComRecruit.TabKata[7]='t';
    ComRecruit.Length=7;
    ComAttack.TabKata[1]='A';
    ComAttack.TabKata[2]='t';
    ComAttack.TabKata[3]='t';
    ComAttack.TabKata[4]='a';
    ComAttack.TabKata[5]='c';
    ComAttack.TabKata[6]='k';
    ComAttack.Length=6;
    ComMap.TabKata[1]='M';
    ComMap.TabKata[2]='a';
    ComMap.TabKata[3]='p';
    ComMap.Length=3;
    ComInfo.TabKata[1]='I';
    ComInfo.TabKata[2]='n';
    ComInfo.TabKata[3]='f';
    ComInfo.TabKata[4]='o';
    ComInfo.Length=4;
    ComEnd_Turn.TabKata[1]='E';
    ComEnd_Turn.TabKata[2]='n';
    ComEnd_Turn.TabKata[3]='d';
    ComEnd_Turn.TabKata[4]='_';
    ComEnd_Turn.TabKata[5]='T';
    ComEnd_Turn.TabKata[6]='u';
    ComEnd_Turn.TabKata[7]='r';
    ComEnd_Turn.TabKata[8]='n';
    ComEnd_Turn.Length=8;
    ComSave.TabKata[1]='S';
    ComSave.TabKata[2]='a';
    ComSave.TabKata[3]='v';
    ComSave.TabKata[4]='e';
    ComSave.Length=4;
    ComExit.TabKata[1]='E';
    ComExit.TabKata[2]='x';
    ComExit.TabKata[3]='i';
    ComExit.TabKata[4]='t';
    ComExit.Length=4;
}

void readcommand()
{
    FILE * pita;
    char command [20];
    scanf("%s",command);
    pita=fopen("pitakar.txt","w");
    fprintf(pita,"%s.",command);
    fclose(pita);
    STARTKATA();
    printf("winningcheck : %d\n", winningcheck() );
    while (!IsKataSama (CKata,ComExit) && (winningcheck()==0)){
        execute();
        openingturn ();
        scanf("%s",command);
        pita=fopen("pitakar.txt","w");
        fprintf(pita,"%s.",command);
        fclose(pita);
        STARTKATA();
    }
    printf("\n\n=== EXIT ===\n\n");
}

void AttackAndRetaliate(Player *P1, Player *P2){
    POINT UnitLoc, EnemyLoc;
    int choice;
    int i;
    ListU LEnemy;
    addressU U;
    boolean found;
    /* Algoritma */
    UnitLoc = CurrentUnit(*P1).location;
    printf("UnitLoc: (%d,%d)", Absis(UnitLoc), Ordinat(UnitLoc));
    CreateEmptyU(&LEnemy);
    printf("step 1\n");
    U = FirstU(Units(*P2));
    while (U != Nil){
        EnemyLoc = GetLocation(InfoU(U));
        printf("EnemyLoc: (%d,%d)", Absis(EnemyLoc), Ordinat(EnemyLoc));
        if (Absis(EnemyLoc) == Absis(UnitLoc)-1 && Ordinat(EnemyLoc)==Ordinat(UnitLoc)){
            InsVFirstU(&LEnemy,InfoU(U));
        }
        else if (Absis(EnemyLoc) == Absis(UnitLoc)+1 && Ordinat(EnemyLoc)==Ordinat(UnitLoc)){
            InsVFirstU(&LEnemy,InfoU(U));
        }
        else if (Absis(EnemyLoc) == Absis(UnitLoc) && Ordinat(EnemyLoc)==Ordinat(UnitLoc)-1){
            InsVFirstU(&LEnemy,InfoU(U));
        }
        else if (Absis(EnemyLoc) ==  Absis(UnitLoc) && Ordinat(EnemyLoc)==Ordinat(UnitLoc)+1){
            InsVFirstU(&LEnemy,InfoU(U));
        }
        U=NextU(U);
    }
    printf("Step 2\n");
    printf("List Enemies: \n");
    PrintListU(LEnemy);
    /* Menampilkan Seluruh Kemungkinan Musuh yang dapat Diserang */
    if(CanAttack(CurrentUnit(*P1))){
        if(!IsEmptyU(LEnemy)){
            // printf("Please select enemy you want to attack : \n");
            PrintListEnemy(LEnemy, &choice);
            printf("step 3\n");
            /* Memilih Unit yang ingin diserang */
            i = 1 ;
            U = FirstU(LEnemy);
            found = false ;
            while(U!=Nil && !found){
                if (i != choice){
                    U = NextU(U);
                    i++;
                }
                else {
                    found = true;
                }
            }
            printf("step 4\n");
            addressU P;
            addressU Prec;
            found=false;
            P=FirstU(Units(*P2));
            Prec=Nil;
            while(P!=Nil && !found){
                if(Absis(GetLocation(InfoU(P)))==Absis(GetLocation(InfoU(U))) && Ordinat(GetLocation(InfoU(P)))==Ordinat(GetLocation(InfoU(U)))){
                    found=true;
                }
                else{
                    Prec=P;
                    P=NextU(P);
                }
            }
            printf("step 5\n");
            Attack(&CurrentUnit(*P1), &InfoU(U));
            printf("step 6\n");
            if(IsDead(InfoU(U))){
                printf("Enemy has been slain!\n");
             }
            Retaliate(InfoU(U), &CurrentUnit(*P1));
            printf("step 7\n");
            if(Prec!=Nil){
                DelAfterU(&Units(*P2), &P, Prec);
                if(!IsDead(InfoU(U))){
                    InsertAfterU(&Units(*P2), U, Prec);
                    CurrentUnit(*P2)=InfoU(U);
                }
            }
            else{
                DelFirstU(&Units(*P2), &P);
                if(!IsDead(InfoU(U))){
                    InsertFirstU(&Units(*P2), U);
                    CurrentUnit(*P2)=InfoU(U);
                }
                printf("P2, yang diupdate: \n");PrintUnit(InfoU(FirstU(Units(*P2))));printf("\n");
            }
            printf("step 8\n");
            /*printf("P1:\n");PrintUnit(CurrentUnit(*P1)); printf("\n");
            addressU Pu;
            Pu=FirstU(Units(*P2));
            found=false;
            while(Pu!=Nil && !found){
                if(Absis(GetLocation(InfoU(Pu)))==Absis(GetLocation(InfoU(U))) && Ordinat(GetLocation(InfoU(Pu)))==Ordinat(GetLocation(InfoU(U)))){
                    found=true;
                }
                Pu=NextU(Pu);
            }
            printf("P2:\n");PrintUnit(InfoU(Pu));printf("\n");*/
            printf("P2 List Units:\n");
            addressU Pu;
            Pu=FirstU(Units(*P2));
            while(Pu!=Nil){
                PrintUnit(InfoU(Pu));printf("\n");
                Pu=NextU(Pu);
            }
            printf("step finish\n");
        }
        else{
            printf("There are no enemies to attack!!\n");
        }
    }
    else{
        printf("You already attacked!\n");
    }
    UpdatePlayer(*P1);
    PrintUnit(CurrentUnit(*P1));
    UpdatePlayer(*P2);
    PrintUnit(InfoU(U));
}

void PrintListEnemy (ListU L, int *choice){
/* Kamus */
    int i;
    addressU P ;
    Unit U;
    POINT T;
/* Algoritma */
    printf("Please select enemy you want to attack:\n");
    printf("step 2.1\n");
    if (!IsEmptyU(L)){
        i = 1 ;
        P = FirstU(L);
        printf("step 2.2\n");
        while (P!=Nil){
            U = InfoU(P);
            T = GetLocation(U);
            printf("%d. ", i);
            printf("step 2.3\n");
            if (U.id==1) {
                printf("King (%d,%d) | Health %d/%d", T.X, T.Y, U.health, U.max_health);
            }
            else if (U.id==2){
                printf("Archer (%d,%d) | Health %d/%d \n", T.X, T.Y, U.health, U.max_health);
            }
            else if (U.id==3){
                printf("Swordsman (%d,%d) | Health %d/%d \n", T.X, T.Y, U.health, U.max_health);
            }
            else if (U.id==4){
                printf("White Mage (%d,%d) | Health %d/%d \n", T.X, T.Y, U.health, U.max_health);
            }
            printf("step 2.4\n");
            /*if ((U.id ==1)||(U.atk_type == CurrentUnit(*P).atk_type)) {
                printf(" (Retaliates)\n");
            }*/
            P = NextU(P);
            i++;
            printf("step 2.5\n");
        }
        int c;
        do {
            printf("step 2.6\n");
            printf("Select enemy you want to attack : \n"); scanf("%d", &c);
            if (c<0 || c>i){
                printf("The number you entered is not in list!\n");
            }
        } while (c<0 || c>i);
        *choice=c;
        printf("step 2.7\n");
    }
   }

int winningcheck () {
    boolean found1 = false, found2 = false;
    addressU Pt1 = FirstU(Units(P1));
    while (Pt1 != Nil && !found1)
    {
        if(InfoU(Pt1).id == 1)
        {
            found1 = true;
        }
        else Pt1 = NextU(Pt1);
    }
    addressU Pt2 = FirstU(Units(P2));
    while (Pt2 != Nil && !found2)
    {
        if(InfoU(Pt2).id == 1)
        {
            found2 = true;
        }
        else Pt2 = NextU(Pt2);
    }
    if(found1 && found2) return 0;
    else if(found1 && !found2) return 1;
    else return 2;
}