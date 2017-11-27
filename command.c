#include <stdio.h>
#include "command.h"
#include "player.h"
#include "mesinkata.h"
#include "queue.h"
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
Kata CommNextUnit;
boolean end =false;

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
    CommNextUnit.TabKata[1]='N';
    CommNextUnit.TabKata[2]='e';
    CommNextUnit.TabKata[3]='x';
    CommNextUnit.TabKata[4]='t';
    CommNextUnit.TabKata[5]='_';
    CommNextUnit.TabKata[6]='U';
    CommNextUnit.TabKata[7]='n';
    CommNextUnit.TabKata[8]='i';
    CommNextUnit.TabKata[9]='t';
    CommNextUnit.Length=9;
}

void StartGame()
{
	Player P1,P2;
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
    initialkata();
    openingturn();
    readcommand();
}

void openingturn ()
{
	/* Algoritma */
    if(end) 
    {
        CurrentUnit(InfoHead(QTurn)).mov_points=CurrentUnit(InfoHead(QTurn)).max_mov_points;
        CurrentUnit(InfoHead(QTurn)).atk_chance=true;
    }
    printf("\n\n");
    UpdateGiliranUnitMap(CurrentUnit(InfoHead(QTurn)).location,true);
    printf("Player %d's Turn\n",Id(InfoHead(QTurn)));
    PrintAttribute (InfoHead(QTurn));
    PrintUnit(CurrentUnit(InfoHead(QTurn)));
    printf("\nYour input : ");
}

void execute ()
{
	/* Algoritma */
	printf("\n");
	HealPlayer(&InfoHead(QTurn));
    if(IsKataSama (CKata,ComMove))
    {
        boolean found=false;
        addressU Pt;
        POINT lokasiawal=CurrentUnit(InfoHead(QTurn)).location;
        Move(&InfoHead(QTurn));
        Pt= FirstU(Units(InfoHead(QTurn)));
        while(Pt!=Nil && !found)
        {
            if(EQ(lokasiawal,InfoU(Pt).location))
            {
                InfoU(Pt).location=CurrentUnit(InfoHead(QTurn)).location;
                InfoU(Pt).mov_points=CurrentUnit(InfoHead(QTurn)).mov_points;
                found=true;
            }
            else Pt=NextU(Pt);
        }
        end=false;
    }
    else if(IsKataSama (CKata,ComUndo))
    {
        Undo(&InfoHead(QTurn));
        end=false;
    }
    else if(IsKataSama (CKata,ComChange_Unit))
    {
    CreateEmpty (&S);
        ChangeUnit(&InfoHead(QTurn));
        end=false;
    }
    else if(IsKataSama (CKata,ComRecruit))
    {
    CreateEmpty (&S);
        Recruit (&InfoHead(QTurn));
        end=false;
    }
    else if(IsKataSama (CKata,ComAttack))
    {
    CreateEmpty (&S);
    AttackAndRetaliate(&InfoHead(QTurn), &InfoTail(QTurn));
    end=false;
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
        RecoverGoldMove(&InfoHead(QTurn));
        EndTurn (&InfoHead(QTurn));
        end =true;
    }
    else if(IsKataSama (CKata,ComSave))
    {
        CreateEmpty (&S);
        end=false;
    }
    else if (IsKataSama(CKata,CommNextUnit)){
        NextUnit(&InfoHead(QTurn));
        end = false ;
    }
    else printf("Invalid command\n");
}

void readcommand()
{
	/* Kamus */
    FILE * pita;
    char command [20];
    /* Algoritma */
    scanf("%s",command);
    pita=fopen("pitakar.txt","w");
    fprintf(pita,"%s.",command);
    fclose(pita);
    STARTKATA();
    while (!IsKataSama (CKata,ComExit) && winningcheck()==0){
        execute();
        if (winningcheck()==1) printf("\n=== GAME OVER ===\n\nCongratulation Player 1! You win the game!\nSorry Player 2, You lose! :(\n\n");
        else if (winningcheck()==2) printf("\n=== GAME OVER ===\n\nCongratulation Player 1! You win the game!\nSorry Player 2, You lose! :(\n\n");
        else if (IsKataSama(CKata,ComExit)) printf("\n\n=== EXIT ===\n\n");
        else 
        {
        	openingturn ();
	        scanf("%s",command);
	        pita=fopen("pitakar.txt","w");
	        fprintf(pita,"%s.",command);
	        fclose(pita);
	        STARTKATA();
        }
    }
    printf("\n\n=== EXIT ===\n\n");
}

void AttackAndRetaliate(Player *A, Player *B){
    /* Kamus */
    POINT UnitLoc, EnemyLoc;
    int choice;
    int i;
    ListU LEnemy;
    addressU U;
    boolean found;
    /* Algoritma */
    UnitLoc = CurrentUnit(*A).location;
    CreateEmptyU(&LEnemy);
    U = FirstU(Units(*B));
    while (U != Nil){
        EnemyLoc = GetLocation(InfoU(U));
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
    /* Menampilkan Seluruh Kemungkinan Musuh yang dapat Diserang */
    if(CanAttack(CurrentUnit(*A))){
        if(!IsEmptyU(LEnemy)){
            PrintListEnemy(LEnemy, &choice);
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
            addressU Pt;
            addressU Prec;
            found=false;
            Pt=FirstU(Units(*B));
            Prec=Nil;
            while(Pt!=Nil && !found){
                if(Absis(GetLocation(InfoU(Pt)))==Absis(GetLocation(InfoU(U))) &&
						Ordinat(GetLocation(InfoU(Pt)))==Ordinat(GetLocation(InfoU(U)))){
                    found=true;
                }
                else{
                    Prec=Pt;
                    Pt=NextU(Pt);
                }
            }
            addressU Pu;
            addressU PrecU;
            found=false;
            PrecU=Nil;
            Pu=FirstU(Units(*A));
            while(Pu!=Nil && !found){
                if(Absis(GetLocation(InfoU(Pu)))==Absis(GetLocation(CurrentUnit(*A))) && 
						Ordinat(GetLocation(InfoU(Pu)))==Ordinat(GetLocation(CurrentUnit(*A)))){
                    found=true;
                }
                else{
                    PrecU=Pu;
                    Pu=NextU(Pu);
                }
            }
            Attack(&CurrentUnit(*A), &InfoU(U));
            if(IsDead(InfoU(U))){
                printf("Enemy has been slain!\n");
		UpdateUnitMap(InfoU(U).location,0,0);
             }
	    else Retaliate(InfoU(U), &CurrentUnit(*A));
            if(Prec!=Nil){
                DelAfterU(&Units(*B), &Pt, Prec);
                if(!IsDead(InfoU(U))){
                    CurrentUnit(*B)=InfoU(U);
                    InsertAfterU(&Units(*B), U, Prec);       
                }
                else{
			CurrentUnit(*B)=InfoU(FirstU(Units(*B)));
			UpdateUnitMap(InfoU(U).location,0,0);
                }
            }
            else{
                DelFirstU(&Units(*B), &Pt);
                if(!IsDead(InfoU(U))){
                    CurrentUnit(*B)=InfoU(U);
                    InsertFirstU(&Units(*B), U);
                }
                else{
			if(FirstU(Units(*B))!=Nil)
                	CurrentUnit(*B)=InfoU(FirstU(Units(*B)));
			UpdateUnitMap(InfoU(U).location,0,0);
                }
            }
            Unit X = CurrentUnit(*A);
            addressU UX;
            UX=AlokasiU(X);
             if(PrecU!=Nil){
                DelAfterU(&Units(*A), &Pu, PrecU);
                if(!IsDead(InfoU(UX))){
                    CurrentUnit(*A)=InfoU(UX);
                    InsertAfterU(&Units(*A), UX, PrecU);
                }
                else{
                	CurrentUnit(*A)=InfoU(FirstU(Units(*A)));
			UpdateUnitMap(InfoU(UX).location,0,0);
                }
            }
            else{
                DelFirstU(&Units(*A), &Pu);
                if(!IsDead(InfoU(UX))){
                    CurrentUnit(*A)=InfoU(UX);
                    InsertFirstU(&Units(*A), UX);
                }
                else{
                	CurrentUnit(*A)=InfoU(FirstU(Units(*A)));
			UpdateUnitMap(InfoU(UX).location,0,0);
                }
            }
        }
        else{
            printf("\n");
            printf("There are no enemies to attack!!\n");
        }
    }
    else{
        printf("\n");
        printf("You already attacked!\n");
    }
 }

void PrintListEnemy (ListU L, int *choice){
	/* Kamus */
    int i;
    addressU P ;
    Unit U;
    POINT T;
	/* Algoritma */
    printf("\n");
    printf("Please select enemy you want to attack:\n");
    if (!IsEmptyU(L)){
        i = 1 ;
        P = FirstU(L);
        while (P!=Nil){
            U = InfoU(P);
            T = GetLocation(U);
            printf("%d. ", i);
        
            if (U.id==1) {
                printf("King (%d,%d) | Health %d/%d \n", T.X, T.Y, U.health, U.max_health);
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
            
            printf("\n");
            P = NextU(P);
            i++;
            
        }
        int c;
        do {
            printf("Select enemy you want to attack : "); scanf("%d", &c);
            if (c<0 || c>i){
                printf("The number you entered is not in list!\n");
            }
        } while (c<0 || c>i);
        *choice=c;
        
    }
}

void HealPlayer(Player *P){
    addressU W;
    W=FirstU(Units(*P));
    /* searching whitemagenya dulu */
    while(W!=Nil){
        if(InfoU(W).id==4){
            addressU U;
            U=FirstU(Units(*P));
            /* searching units yang adjacent */
            while(U!=Nil){
                if (Absis(GetLocation(InfoU(W))) == Absis(GetLocation(InfoU(U)))-1 && 
						Ordinat(GetLocation(InfoU(W))) == Ordinat(GetLocation(InfoU(U)))){
                    Heal(InfoU(W), &InfoU(U));
					if(EQ(GetLocation(InfoU(U)),GetLocation(CurrentUnit(*P))))
						CurrentUnit(*P).health=CurrentUnit(*P).max_health;
                }else if (Absis(GetLocation(InfoU(W))) == Absis(GetLocation(InfoU(U)))+1 && 
						Ordinat(GetLocation(InfoU(W))) == Ordinat(GetLocation(InfoU(U)))){
                    Heal(InfoU(W), &InfoU(U));
					if(EQ(GetLocation(InfoU(U)),GetLocation(CurrentUnit(*P)))) 
						CurrentUnit(*P).health=CurrentUnit(*P).max_health;
                }else if (Absis(GetLocation(InfoU(W))) == Absis(GetLocation(InfoU(U))) && 
						Ordinat(GetLocation(InfoU(W))) == Ordinat(GetLocation(InfoU(U)))-1){
                    Heal(InfoU(W), &InfoU(U));
					if(EQ(GetLocation(InfoU(U)),GetLocation(CurrentUnit(*P))))
						CurrentUnit(*P).health=CurrentUnit(*P).max_health;
				}else if (Absis(GetLocation(InfoU(W))) ==  Absis(GetLocation(InfoU(U))) && 
						Ordinat(GetLocation(InfoU(W))) == Ordinat(GetLocation(InfoU(U)))+1){
					Heal(InfoU(W), &InfoU(U));
					if(EQ(GetLocation(InfoU(U)),GetLocation(CurrentUnit(*P))))
						CurrentUnit(*P).health=CurrentUnit(*P).max_health;
				}
				U=NextU(U);
			}	
        }
        W=NextU(W);
    }
}

int winningcheck () {
	/* kamus */
    boolean found1 = false, found2 = false;
    addressU Pt1 = FirstU(Units(InfoHead(QTurn)));
    
    /* Algoritma */
    while (Pt1 != Nil && !found1)
    {
        if(InfoU(Pt1).id == 1)
        {
            found1 = true;
        }
        else Pt1 = NextU(Pt1);
    }
    addressU Pt2 = FirstU(Units(InfoTail(QTurn)));
    while (Pt2 != Nil && !found2)
    {
        if(InfoU(Pt2).id == 1)
        {
            found2 = true;
        }
        else Pt2 = NextU(Pt2);
    }
    if(found1 && found2)
		return 0;
    else if(found1 && !found2)
		return Id(InfoHead(QTurn));
    else 
		return Id(InfoTail(QTurn));
}