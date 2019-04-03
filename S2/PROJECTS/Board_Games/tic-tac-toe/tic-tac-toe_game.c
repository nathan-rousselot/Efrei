/***************************************************************************
 *
 * Project:  Board Games Project
 *
 ***************************************************************************
 *   Copyright (C) 2019 by Nathan Rousselot                                *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,  USA.         *
 ***************************************************************************
 */

 //Directives
 #include "tic-tac-toe_game.h"
 #include "terminal_linux.h"

 //Functions
 void print_board(struct Board board, int round, char name[]) {
  //This function take a board as a parameter, and prints it in a stilized way...
  printf("\033[2J");
  int i = 0;
  int j = 0;
  int k = 0;
  while (i < board.size) {
    printf("|");
    while (j < board.size) {
      printf("%c |", board.cells[i][j]);
      j++;
    }
    j = 0;
    if (i == board.size / 2) {
      printf("  Round: %d", round);
    }
    if (i == board.size / 2 + 1) {
      printf("  %s turn.", name);
    }
    printf("\n");
    while (k < board.size) {
      printf("---");
      k++;
    }
    k = 0;
    printf("-\n");
    i++;
  }
}

struct Board init_board(int n) {
  //This function takes the size of a board we want, and returns it full of blank spaces
  char** cells = malloc(sizeof(char*) * n);
  int i = 0;
  while (i < n) {
    cells[i] = malloc(sizeof(char) * n);
    i++;
  }
  i = 0;
  int j = 0;
  while (i < n) {
    while (j < n) {
      cells[i][j] = ' ';
      j++;
    }
    j = 0;
    i++;
  }
  struct Board board;
  board.size = n;
  board.cells = cells;
  i = 0;
  return board;
}

struct Board play(struct Board board) {
  //This function simulate one turn of play.
  int isok = 1;
  while (isok == 1) {
    int line;
    int col;
    printf("On which line do you want to play?\n");
    scanf("%d", &line);
    printf("On which column do you want to play?\n");
    scanf("%d", &col);
    if (line > 2 || col > 2) {
      printf("Wrong move! Out of bounds...\n");
    }
    else if (board.cells[line][col] != ' ') {
      printf("Wrong move! There's already somebody here...\n");
    }
    else {
      board.cells[line][col] = 'X';
      isok = 0;
    }
  }
  return board;
}

int has_win(struct Board board) {
  //This function check whether somebody has won already or not. Returns 0 if somebody has won. 1 otherwise.
  int i = 0;
  int j = 0;
  if (board.cells[0][0] == board.cells[0][1] && board.cells[0][1] == board.cells[0][2] && board.cells[0][0] != ' ') {
    if (board.cells[0][0] == 'X') {
      printf("You won!\n");
      return 0;
    }
    printf("You lost!\n");
    return 0;
  }
  else if (board.cells[1][0] == board.cells[1][1] && board.cells[1][1] == board.cells[1][2] && board.cells[1][0] != ' ') {
    if (board.cells[1][0] == 'X') {
      printf("You won!\n");
      return 0;
    }
    printf("You lost!\n");
    return 0;
  }
  else if (board.cells[2][0] == board.cells[2][1] && board.cells[2][1] == board.cells[2][2] && board.cells[2][0] != ' ') {
    if (board.cells[2][0] == 'X') {
      printf("You won!\n");
      return 0;
    }
    printf("You lost!\n");
    return 0;
  }
  else if (board.cells[0][0] == board.cells[1][0] && board.cells[1][0] == board.cells[2][0] && board.cells[0][0] != ' ') {
    if (board.cells[0][0] == 'X') {
      printf("You won!\n");
      return 0;
    }
    printf("You lost!\n");
    return 0;
  }
  else if (board.cells[0][1] == board.cells[1][1] && board.cells[1][1] == board.cells[2][1] && board.cells[0][1] != ' ') {
    if (board.cells[0][1] == 'X') {
      printf("You won!\n");
      return 0;
    }
    printf("You lost!\n");
    return 0;
  }
  else if (board.cells[0][2] == board.cells[1][2] && board.cells[1][2] == board.cells[2][2] && board.cells[0][2] != ' ') {
    if (board.cells[0][2] == 'X') {
      printf("You won!\n");
      return 0;
    }
    printf("You lost!\n");
    return 0;
  }
  else if (board.cells[0][0] == board.cells[1][1] && board.cells[1][1] == board.cells[2][2] && board.cells[0][0] != ' ') {
    if (board.cells[0][0] == 'X') {
      printf("You won!\n");
      return 0;
    }
    printf("You lost!\n");
    return 0;
  }
  else if (board.cells[0][2] == board.cells[1][1] && board.cells[1][1] == board.cells[2][0] && board.cells[0][2] != ' ') {
    if (board.cells[1][1] == 'X') {
      printf("You won!\n");
      return 0;
    }
    printf("You lost!\n");
    return 0;
  }
  return 1;
}




//AI Functions
int rand_a_b(int a, int b) {
  return rand()%(b-a) + a;
}

struct Board easy_AI(struct Board board) {
  srand(time(NULL));
  int a = rand_a_b(0, 3);
  int b = rand_a_b(0, 3);
  while (board.cells[a][b] != ' ') {
    a = rand_a_b(0, 3);
    b = rand_a_b(0, 3);
  }
  board.cells[a][b] = 'O';
  return board;
}
