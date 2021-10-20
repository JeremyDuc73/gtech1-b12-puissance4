#include <stdio.h>
#include <stdlib.h>
char token[] = "OX";
char gamearray[6][7];
int NBR=6, NBC=7;
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
  for(int r =1; r<NBC+1;r++){
    printf("%d ",r);
  }
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

int win=0;
void win_vertical(void){
  for(int r=0;r<NBR-3;r++) {
    for(int c=0;c<NBC;c++) {
      if (gamearray[r][c]==token[player] && gamearray[r+1][c]==token[player] && gamearray[r+2][c]==token[player] && gamearray[r+3][c]==token[player]){
	win=1;
      }
    }
  }
}


void win_horizontal(void){
  for(int r=0;r<NBR;r++) {
    for(int c=0;c<NBC-3;c++) {
      if (gamearray[r][c]==token[player] && gamearray[r][c+1]==token[player] && gamearray[r][c+2]==token[player] && gamearray[r][c+3]==token[player]){
	win=1;
      }
    }
  }
}


void win_diagonal_left(void){
  for(int r=0;r<NBR-3;r++) {
    for(int c=0;c<NBC-3;c++) {
      if (gamearray[r][c]==token[player] && gamearray[r+1][c+1]==token[player] && gamearray[r+2][c+2]==token[player] && gamearray[r+3][c+3]==token[player]){
        win = 1;
      }
    }
  }
}

void win_diagonal(void){
  for(int r=0;r<NBR-3;r++) {
    for(int c=NBC; c>2 ;c--) {
      if (gamearray[r][c]==token[player] && gamearray[r+1][c-1]==token[player] && gamearray[r+2][c-2]==token[player] && gamearray[r+3][c-3]==token[player]){
	win = 1;
      }
    }
  }
}

void verify_win(void){
  win_vertical();
  win_horizontal();
  win_diagonal_left();
  win_diagonal();
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
    verify_win();
    
    if (win == 1){
      printf("[player %d] : You win\n",player+1);
      end_game=1 ;
    }
    
    else if (end == 42){
      printf("Sorry but it's a draw this time !\n");
      end_game = 1;
    }


    player= !player;
    tour = 0;
    end += 1;
    
  }
}


