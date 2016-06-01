#include <stdio.h>
#include <stdlib.h>
void giveHelp(void);
void giveHelp(void){
  printf("To travel to a place type the location name in CAPS\n");
  printf("Type STATS to view your stats.\nType INV to view your inventory.\n");
  printf("Type anything to continue");
  char thing[100];
  scanf("%s", thing);
}



