#include <stdio.h>
#include "command.h"

int main()
{
    char yes;
    printf("=== BATTLE FOR OLYMPIA ===\n\nStart a new game y/n? ");
    scanf("%c",&yes);
    printf("\n\n");
    if(yes=='y') StartGame();
    else printf ("\n\n=== EXIT ===\n");
    return 0;
}
