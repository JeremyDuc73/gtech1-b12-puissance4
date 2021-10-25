#include <stdio.h>
#include <stdlib.h>

/*VARIABLES INITIALISATION */
char token[] = "OX";
char gamearray[6][7];
int NBR=6, NBC=7;
int end_game, turn, col_played, player, end, win = 0;
char c;

/*DASH FUNCTION (for the display)*/
void dash(void){
  int i=0;
  while(i<13){
    i++;
    printf("-");
  }
}

/*DISPLAY FUNCTION*/
void display(void) {
  printf("\033[0;32m");
  dash();
  for (int r = 0; r < NBR; r++)
    {
      printf("\n");
      for(int c = 0; c < NBC; c++)
	{
	  if (gamearray [r][c] == token[0]){
	    printf("\033[0;31m");
	  }
	  else if (gamearray [r][c] == token[1]){
            printf("\x1B[33m");
	  }
	  printf("%c ",gamearray[r][c]);
	  printf("\033[0;32m");
	}
    }
  printf("\n");
  dash();
  printf("\n");
  for(int r =1; r<NBC+1;r++){
    printf("%d ",r);
  }
  printf("\n");
}

/*GAME INITIALISATION FUNCTION*/
void init(void){
  printf("\033[0;37m");
  printf("HELLO!\nWELCOME TO PUISSANCE 4!!\nThe game size is 6x7\n\n");
  for(int r=0;r<NBR;r++) {
    for(int c=0;c<NBC;c++) {
      gamearray[r][c] = '.';
    }
  }
  display();
}

/*CLEAN FUNCTION (for the scanf in the main)*/
int clean(){
  while ((col_played = getchar()) !='\n' && col_played != EOF);
  return 1;
}

/*CHECK and PUT the token in the game tab FUNCTION*/
int pion_in_tab(int token_col, int player){
  if (gamearray[0][token_col-1] !='.'){
    display();
    do{
      printf("\033[0;37m");
      printf("[player %d] : This column is full please choose another one ! (1 to 7)\n", player+1);
    }while (((scanf("%d%c", &col_played, &c)!=2 || c!='\n') && clean()) || col_played<1 || col_played>7) ;
  }
  else {
    for(int r = NBR-1 ; r>=0 ; r--) {
      if (gamearray[r][token_col-1]=='.'){
	gamearray[r][token_col-1] = token[player];
	turn = 1;
	break;
      }
    }
  }
}

/*CHECK VERTICAL WIN FUNCTION*/
void win_vertical(void){
  for(int r=0;r<NBR-3;r++) {
    for(int c=0;c<NBC;c++) {
      if (gamearray[r][c]==token[player] && gamearray[r+1][c]==token[player] && gamearray[r+2][c]==token[player] && gamearray[r+3][c]==token[player]){
	win=1;
      }
    }
  }
}

/*CHECK HORIZONTAL WIN FUNCTION*/
void win_horizontal(void){
  for(int r=0;r<NBR;r++) {
    for(int c=0;c<NBC-3;c++) {
      if (gamearray[r][c]==token[player] && gamearray[r][c+1]==token[player] && gamearray[r][c+2]==token[player] && gamearray[r][c+3]==token[player]){
	win=1;
      }
    }
  }
}

/*CHECK LEFT DIAGONAL WIN FUNCTION*/
void win_diagonal_left(void){
  for(int r=0;r<NBR-3;r++) {
    for(int c=0;c<NBC-3;c++) {
      if (gamearray[r][c]==token[player] && gamearray[r+1][c+1]==token[player] && gamearray[r+2][c+2]==token[player] && gamearray[r+3][c+3]==token[player]){
	win = 1;
      }
    }
  }
}

/*CHECK RIGHT DIAGONAL WIN FUNCTION*/
void win_diagonal_right(void){
  for(int r=NBR;r>3;r--) {
    for(int c=0; c<NBC-3 ;c++) {
      if (gamearray[r][c]==token[player] && gamearray[r-1][c+1]==token[player] && gamearray[r-2][c+2]==token[player] && gamearray[r-3][c+3]==token[player]){
	win = 1;
	printf("%d %d %d %d", r , c ,r+3 ,c-3);
      }
    }
  }
}

/*CHECK WIN FUNCTION*/
void verify_win(void){
  win_vertical();
  win_horizontal();
  win_diagonal_left();
  win_diagonal_right();
}




int main (void){
  init();
  while (end_game ==0) {

    do{
      printf("\033[0;32m");
      printf("[player %d] : Please chose a column to play ! (1 to 7)\n", player+1);
    }while (((scanf("%d%c", &col_played, &c)!=2 || c!='\n') && clean()) || col_played<1 || col_played>7) ;
    while(turn == 0){
      pion_in_tab(col_played, player);
    }
    display();
    verify_win();

    if (win == 1){
      printf("\033[0;37m");
      printf("[player %d] : You win\n",player+1);
      end_game=1 ;
    }

    else if (end == 41){ //42 == total number of possibilities
      printf("\033[0;37m");
      printf("Sorry but it's a draw this time !\n");
      end_game = 1;
    }

    player= !player;
    turn = 0;
    end++;

  }
}


/*
PUISSANCE4 game by Aleksi BIELSKI and Jérémy DUC
*/
