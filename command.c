#include <stdio.h>
#include "command.h"

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

void StartGame()
{
    int X,Y;
    printf("Enter the size of the map : ");
    scanf("%d %d",&X,&Y);
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
    printf("\n\n");
    printf("Player %d's Turn\n",Id(P));
    PrintAttribute (P);
    PrintUnit(CurrentUnit(P));
    printf("\nYour input : ");
}

void execute ()
{
    if(IsKataSama (CKata,ComMove)) Move(&P);
    else if(IsKataSama (CKata,ComUndo)) Undo(&P);
    else if(IsKataSama (CKata,ComChange_Unit)) ChangeUnit(&P);
    else if(IsKataSama (CKata,ComRecruit)) Recruit (&P);
    //else if(IsKataSama (CKata,ComAttack)) /*command attack*/ ;
    else if(IsKataSama (CKata,ComMap)) PrintMap();
    else if(IsKataSama (CKata,ComInfo)) InfoMap();
    else if(IsKataSama (CKata,ComEnd_Turn))
    {
        EndTurn (P);
        P = CurrentTurn(QTurn);
    }
    else if(IsKataSama (CKata,ComSave));
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
    while (!IsKataSama (CKata,ComExit))
    {
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
