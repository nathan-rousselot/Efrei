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
#include "power-4-game.h"
#include "terminal_linux.h"

//Functions
void print_board(struct Board board, int round, char name[]) {
 //This function take a board as a parameter, and prints it in a stylized way...
 printf("\033[2J");
 setBackgroundColor(BLACK);
 int i = 0;
 int j = 0;
 printf("\n 0  1  2  3  4  5  6\n");
 while (i < board.ysize) {
   printf(" ");
   while (j < board.xsize) {
     if (board.cells[i][j] == '1') {
       setTextColor(BLUE);
       printf("*  ");
       setTextColor(WHITE);
     }
     else if (board.cells[i][j] == '2') {
       setTextColor(RED);
       printf("*  ");
       setTextColor(WHITE);
     }
     else {
       printf(".  ");
     }
     j++;
   }
   j = 0;
   if (i == board.ysize / 2 - 1) {
     setTextColor(GREEN);
     printf("  Round: %d", round);
     setTextColor(WHITE);
   }
   if (i == board.ysize / 2) {
     setTextColor(DARKGREEN);
     printf("  %s turn.", name);
     setTextColor(WHITE);
   }
   printf("\n");
   i++;
 }
}

struct Board init_board(int x, int y) {
  //This function takes the size of a board we want, and returns it full of blank spaces
  char** cells = malloc(sizeof(char*) * y);
  int i = 0;
  while (i < y) {
    cells[i] = malloc(sizeof(char) * x);
    i++;
  }
  i = 0;
  int j = 0;
  while (i < y) {
    while (j < x) {
      cells[i][j] = '.';
      j++;
    }
    j = 0;
    i++;
  }
  struct Board board;
  board.xsize = x;
  board.ysize = y;
  board.cells = cells;
  i = 0;
  board.last_col = -1;
  board.last_row = -1;
  return board;
}

int is_full(struct Board board, int column) {
  //This function tests whether a column is full or not.
  if (board.cells[0][column] == '1' || board.cells[0][column] == '2') {
    return 1;
  }
  return 0;
}

struct Board play(int player_id, struct Board board) {
  //This function just simulates one turn of playing
  printf("\nOn which column do you want to play?");
  int column = -1;
  int isok = 1;
  while (isok == 1) {
    while (column < 0 || column > 6) {
      scanf("%d", &column);
    }
    if (is_full(board, column) == 1) {
      printf("Cannot play here\n");
      sleep(0.2);
    }
    else {
      int j = 5;
      while (j > 0 && (board.cells[j][column] == '1' || board.cells[j][column] == '2')) {
        j--;
      }
      if (player_id == 1) {
        board.cells[j][column] = '1';
        isok = 0;
      }
      else {
        board.cells[j][column] = '2';
        isok = 0;
      }
      board.last_row = j;
      board.last_col = column;
    }
    column = -1;
  }
  return board;
}

int has_won_diff(struct Board board) {
  int occ = 0;
  int i = 0;
  while (i < 6 && occ != 4) {
    if (board.cells[board.last_row][i] == board.cells[board.last_row][board.last_col]) {
      occ++;
    }
    else {
      occ = 0;
    }
    i++;
  }
  if (occ == 4) {
    return board.cells[board.last_row][board.last_col];
  }
  i = 0;
  occ = 0;
  while (i < 5 && occ != 4) {
    if (board.cells[i][board.last_col] == board.cells[board.last_row][board.last_col]) {
      occ++;
    }
    else {
      occ = 0;
    }
    i++;
  }
  if (occ == 4) {
    return board.cells[board.last_row][board.last_col];
  }
  i = 0;
  occ = 0;
  return -1;
}

int has_won(struct Board board) {
  // This function is a better way to test if someone has won...
  //lower row check
  if (board.last_row < 3) {
    if (board.cells[board.last_row][board.last_col] == board.cells[board.last_row + 1][board.last_col] &&
        board.cells[board.last_row + 1][board.last_col] == board.cells[board.last_row + 2][board.last_col] &&
        board.cells[board.last_row + 2][board.last_col] == board.cells[board.last_row + 3][board.last_col]) {
          return board.cells[board.last_row][board.last_col];
    }
  }
  //upper row check
  if (board.last_row > 2) {
    if (board.cells[board.last_row][board.last_col] == board.cells[board.last_row - 1][board.last_col] &&
        board.cells[board.last_row - 1][board.last_col] == board.cells[board.last_row - 2][board.last_col] &&
        board.cells[board.last_row - 2][board.last_col] == board.cells[board.last_row - 3][board.last_col]) {
          return board.cells[board.last_row][board.last_col];
    }
  }
  //right column check
  if (board.last_col > 2) {
    if (board.cells[board.last_row][board.last_col] == board.cells[board.last_row][board.last_col - 1] &&
        board.cells[board.last_row][board.last_col - 1] == board.cells[board.last_row][board.last_col - 2] &&
        board.cells[board.last_row][board.last_col - 2] == board.cells[board.last_row][board.last_col - 3]) {
            return board.cells[board.last_row][board.last_col];
    }
  }
  //left column check
  if (board.last_col < 4) {
    if (board.cells[board.last_row][board.last_col] == board.cells[board.last_row][board.last_col + 1] &&
        board.cells[board.last_row][board.last_col + 1] == board.cells[board.last_row][board.last_col + 2] &&
        board.cells[board.last_row][board.last_col + 2] == board.cells[board.last_row][board.last_col + 3]) {
            return board.cells[board.last_row][board.last_col];
    }
  }
  //Down left diagonal
  if (board.last_row < 3 && board.last_col > 2) {
    if (board.cells[board.last_row][board.last_col] == board.cells[board.last_row + 1][board.last_col - 1] &&
        board.cells[board.last_row + 1][board.last_col - 1] == board.cells[board.last_row + 2][board.last_col - 2] &&
        board.cells[board.last_row + 2][board.last_col - 2] == board.cells[board.last_row + 3][board.last_col - 3]) {
            return board.cells[board.last_row][board.last_col];
    }
  }
  //Up right diagonal
  if (board.last_row > 3 && board.last_col < 3) {
    if (board.cells[board.last_row][board.last_col] == board.cells[board.last_row - 1][board.last_col + 1] &&
        board.cells[board.last_row - 1][board.last_col + 1] == board.cells[board.last_row - 2][board.last_col + 2] &&
        board.cells[board.last_row - 2][board.last_col + 2] == board.cells[board.last_row - 3][board.last_col + 3]) {
            return board.cells[board.last_row][board.last_col];
    }
  }
  //Down right diagonal
  if (board.last_row < 3 && board.last_col < 3) {
    if (board.cells[board.last_row][board.last_col] == board.cells[board.last_row + 1][board.last_col + 1] &&
        board.cells[board.last_row + 1][board.last_col + 1] == board.cells[board.last_row + 2][board.last_col + 2] &&
        board.cells[board.last_row + 2][board.last_col + 2] == board.cells[board.last_row + 3][board.last_col + 3]) {
            return board.cells[board.last_row][board.last_col];
    }
  }
  //Up left diagonal
  if (board.last_row > 3 && board.last_col > 2) {
    if (board.cells[board.last_row][board.last_col] == board.cells[board.last_row - 1][board.last_col - 1] &&
        board.cells[board.last_row - 1][board.last_col - 1] == board.cells[board.last_row - 2][board.last_col - 2] &&
        board.cells[board.last_row - 2][board.last_col - 2] == board.cells[board.last_row - 3][board.last_col - 3]) {
            return board.cells[board.last_row][board.last_col];
    }
  }
  return -1;
}
