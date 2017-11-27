#include <stdio.h>
#include "command.h"

int main()
{
    char jwb;
    printf("=== BATTLE FOR OLYMPIA ===\n\n");
    do{
		printf("Start a new game (y/n)? ");
		scanf("%c",&jwb);
		printf("\n\n");
		if(jwb == 'y')
			StartGame();
		else if(jwb == 'n')
			printf ("\n\n=== EXIT ===\n");
		else
			printf ("\n\nInvalid Answer!\n");
	}while(jwb != 'y' && jwb != 'n');
    return 0;
}
