#include "mesinkata.h"
#include "mesinkar.h"
#include "boolean.h"
#include <stdio.h>

int main() {
	Kata Start;
	Kata Load;
	Kata Move;
	Kata Undo;
	Kata Change_Unit;
	Kata Recruit;
	Kata Attack;
	Kata Map;
	Kata Info;
	Kata End_Turn;
	Kata Save;
	Kata Exit;
	Move.TabKata[0]='M';
	Move.TabKata[1]='o';
	Move.TabKata[2]='v';
	Move.TabKata[3]='e';
	Undo.TabKata[0]='U';
	Undo.TabKata[1]='n';
	Undo.TabKata[2]='d';
	Undo.TabKata[3]='o';
	Change_Unit.TabKata[0]='C';
	Change_Unit.TabKata[1]='h';
	Change_Unit.TabKata[2]='a';
	Change_Unit.TabKata[3]='n';
	Change_Unit.TabKata[4]='g';
	Change_Unit.TabKata[5]='e';
	Change_Unit.TabKata[6]=' ';
	Change_Unit.TabKata[7]='U';
	Change_Unit.TabKata[8]='n';
	Change_Unit.TabKata[9]='i';
	Change_Unit.TabKata[10]='t';
	Recruit.TabKata[0]='R';
	Recruit.TabKata[1]='e';
	Recruit.TabKata[2]='c';
	Recruit.TabKata[3]='r';
	Recruit.TabKata[4]='u';
	Recruit.TabKata[5]='i';
	Recruit.TabKata[6]='t';
	Attack.TabKata[0]='A';
	Attack.TabKata[1]='t';
	Attack.TabKata[2]='t';
	Attack.TabKata[3]='a';
	Attack.TabKata[4]='c';
	Attack.TabKata[5]='k';
	Map.TabKata[0]='M';
	Map.TabKata[1]='a';
	Map.TabKata[2]='p';
	Info.TabKata[0]='I';
	Info.TabKata[1]='n';
	Info.TabKata[2]='f';
	Info.TabKata[3]='o';
	End_Turn.TabKata[0]='E';
	End_Turn.TabKata[1]='n';
	End_Turn.TabKata[2]='d';
	End_Turn.TabKata[3]=' ';
	End_Turn.TabKata[4]='T';
	End_Turn.TabKata[5]='u';
	End_Turn.TabKata[6]='r';
	End_Turn.TabKata[7]='n';
	Save.TabKata[0]='S';
	Save.TabKata[1]='a';
	Save.TabKata[2]='v';
	Save.TabKata[3]='e';
	Exit.TabKata[0]='E';
	Exit.TabKata[1]='x';
	Exit.TabKata[2]='i';
	Exit.TabKata[3]='t';
	STARTKATA();
	boolean command
	command = false

	if ((IsKataSama(CKata,Start))){
		command = true;
	}
	else if ((IsKataSama(CKata,Load))){
		command =true;
	}
	else if ((IsKataSama(CKata,Move))){
		command =true;
	}
	else if ((IsKataSama(CKata,Undo))){
		command =true;
	}
	else if ((IsKataSama(CKata,Change_Unit))){
		command =true;
	}
	else if ((IsKataSama(CKata,Recruit))){
		command =true;
	}
	else if ((IsKataSama(CKata,Attack))){
		command =true;
	}
	else if ((IsKataSama(CKata,Map))){
		command =true;
	}
	else if ((IsKataSama(CKata,Info))){
		command =true;
	}
	else if ((IsKataSama(CKata,End_Turn))){
		command =true;
	}
	else if ((IsKataSama(CKata,Save))){
		command =true;
	}
	else if ((IsKataSama(CKata,Exit))){
		command =true;
	}
	else{
		command = false;
	}
	return 0;
}