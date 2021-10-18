#include <stdio.h>
#include <stdlib.h>


int NBR=6, NBC=7;

int gamearray[6][7];

int tiret(void){
  int i=0;
  while(i<13){
    i++;
    printf("-");
  }
}

int init(void){
  printf("HELLO!\nWELCOME TO PUISSANCE 4!!\nThe game size is 6x7\n\n");
  tiret();
  int r, c;
  for(r=0;r<NBR;r++) {
    printf("\n");
    for(c=0;c<NBC;c++) {
      printf("%c ",gamearray[r][c] = '.');
    }
  }
  printf("\n");
  tiret();
  printf("\n1 2 3 4 5 6 7\n");
  return 0;
}

int main(void){
  init();
}
