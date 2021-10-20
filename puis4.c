#include <stdio.h>
#include <stdlib.h>
int end_game, tour, rep_c, player, end = 0;
char c;

void tiret(void){
  int i=0;
  while(i<13){
    i++;
    printf("-");
  }
}
void display(void) {
  tiret();
  for (int r = 0; r < NBR; r++)
    {
      printf("\n");
      for(int c = 0; c < NBC; c++)
	{
	  printf("%c ",gamearray[r][c]);
	}
   }
  printf("\n");
  tiret();
  printf("\n");
}

void init(void){
  printf("HELLO!\nWELCOME TO PUISSANCE 4!!\nThe game size is 6x7\n\n");
  for(int r=0;r<NBR;r++) {
    for(int c=0;c<NBC;c++) {
      gamearray[r][c] = '.';
    }
  }
  display();
}

int clean(){
  while ((rep_c = getchar()) !='\n' && rep_c != EOF);
  return 1;
}

int pion_in_tab(int col_pion, int player){
  if (gamearray[0][col_pion-1] !='.'){
    display();
    do{
      printf("[player %d] : This column is full please choose another one ! (1 to 7)\n", player+1);
    }while (((scanf("%d%c", &rep_c, &c)!=2 || c!='\n') && clean()) || rep_c<1 || rep_c >7) ;
  }
  else {
    for(int r = NBR-1 ; r>=0 ; r--) {
      if (gamearray[r][col_pion-1]=='.'){
        gamearray[r][col_pion-1] = token[player];
	tour = 1;
	break;
	}
    }
  }
}

int main (void){
  init();
  while (end_game ==0) {
    
    do{
      printf("[player %d] : Please chose a column to play ! (1 to 7)\n", player+1);
    }while (((scanf("%d%c", &rep_c, &c)!=2 || c!='\n') && clean()) || rep_c<1 || rep_c >7) ;
    while(tour == 0){
      pion_in_tab(rep_c, player);
    }
    display();
    if (player == 0){
      player = 1;
    }
    else {
      player = 0;
    }
    tour = 0;
    end += 1;
    if (end == 42){
      printf("Sorry but it's a draw this time !\n");
      end_game = 1;
    }
  }
}


