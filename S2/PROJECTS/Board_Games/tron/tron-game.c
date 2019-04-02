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
#include "tron-game.h"
#include "terminal_linux.h"

//Functions
 void print_board(struct Board board, int round, char name[]) {
  //This function take a board as a parameter, and prints it in a stylized way...
  printf("\033[2J");
  printf("\n");
  setBackgroundColor(BLACK);
  int i = 0;
  int j = 0;
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
   return board;
 }

struct Board play(struct Board board, struct Player * player) {
  //Let one player play his turn.
  char move = 'A';
  while(move != 'Z' && move != 'Q' && move != 'S' && move != 'D') {
    scanf("%c", &move);
  }
  switch(move) {
    case 'Z':
      if ((*player).last_row - 1 < 0) {
        (*player).alive = 0;
      }
      else if (board.cells[(*player).last_row - 1][(*player).last_col] != '.') {
        (*player).alive = 0;
      }
      else {
        board.cells[(*player).last_row - 1][(*player).last_col] = (char) ((*player).id + 48);
        (*player).last_row--;
      }
      break;
    case 'S':
      if ((*player).last_row + 1 > 20) {
        (*player).alive = 0;
      }
      else if (board.cells[(*player).last_row + 1][(*player).last_col] != '.') {
        (*player).alive = 0;
      }
      else {
        board.cells[(*player).last_row + 1][(*player).last_col] = (char) ((*player).id + 48);
        (*player).last_row++;
      }
      break;
    case 'D':
      if ((*player).last_col + 1 > 20) {
        (*player).alive = 0;
      }
      else if (board.cells[(*player).last_row][(*player).last_col + 1] != '.') {
        (*player).alive = 0;
      }
      else {
        board.cells[(*player).last_row ][(*player).last_col + 1] = (char) ((*player).id + 48);
        (*player).last_col++;
      }
      break;
    case 'Q':
      if ((*player).last_col - 1 < 0) {
        (*player).alive = 0;
      }
      else if (board.cells[(*player).last_row][(*player).last_col - 1] != '.') {
        (*player).alive = 0;
      }
      else {
        board.cells[(*player).last_row][(*player).last_col - 1] = (char) ((*player).id + 48);
        (*player).last_col--;
      }
      break;
  }
  return board;
}

struct Player init_player(int id, int col) {
  //Initialize a player, with a given column, usually 5 or 15 according to the subject.
  struct Player player;
  player.id = id;
  player.alive = 1;
  player.last_col = col;
  player.last_row = 10;
  return player;
}


void replay() {
  //Generates a replay of the past game.

  //init of the Board
  struct Board board;
  board = init_board(21, 21);
  int x, y;
  //init of the file
  FILE * fp;
  fp = fopen("log.txt", "r");
  char line[10];
  char ** lines = malloc(21*21*sizeof(char*));
  int i = 0;
  while (i < 21*21) {
    lines[i] = malloc(10*sizeof(char));
    i++;
  }
  i = 0;
  while (fgets(lines[i], 10, fp) != NULL) {
    if (i % 2 == 0) {
      sscanf(lines[i], "%d,%d", &x, &y);
      board.cells[x][y] = '1';
      print_board(board, (i / 2) + 1, "Player 1");
      usleep(50000);
    }
    else {
      sscanf(lines[i], "%d,%d", &x, &y);
      board.cells[x][y] = '2';
      print_board(board, (i / 2) + 1, "Player 2");
      usleep(50000);
    }
    i++;
  }
  i = 0;
  while (i < 20) {
    free(lines[i]);
    i++;
  }
  free(lines);
}
