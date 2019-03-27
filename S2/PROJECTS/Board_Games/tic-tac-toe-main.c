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
#include "terminal_linux.h"
#include "tic-tac-toe_game.h"

//structs


//Prototypes
void initmenudisplay();
int choice_initmenudisplay(int * choice);
void playmenu();
int choice_playmenu(int * choice);

//Main
int main() {
  //Variables
  int choice = 0;
  struct Board board;
  board = init_board(3); //3*3 board
  int round = 0;

  initmenudisplay();
  choice_initmenudisplay(&choice);
  switch (choice) {
    case 1:
      choice = 0;
      playmenu();
      choice_playmenu(&choice);
      switch (choice) {
        case 1:
          while (has_win(board) == 1) {
            round++;
            print_board(board, round, "Your");
            board = play(board);
            sleep(0.1);
            board = easy_AI(board);
          }
          int i = 0;
          while (i < 3) {
            free(board.cells[i]);
            i++;
          }
          free(board.cells);
          break;
        case 2:
          break;
        case 3:
          break;
      }
      break;
    case 2:
      choice = 0;
      break;
    case 3:
      choice = 0;
      system("xdg-open https://en.wikipedia.org/wiki/Tic-tac-toe");
      break;
    case 4:
      choice = 0;
      system("xdg-open https://github.com/RousselotN/Efrei"); //ON LINUX ONLY
      break;
  }
  return 0;
}

//Functions

void initmenudisplay() {
  /*
  This function takes nothing as a parameter, and returns nothing aswell.
  It just creates a simple menu, which will be a starting point for the
  player. On this Menu, the player will have multiple choice, like
  selecting difficulty, or be redirected to a doc file etc.
  */
  printf("\033[2J");
  printf("          ************************** \n\
          * Welcome to Tic Tac Toe *\n\
          *            by          *\n\
          *      Nathan Rousselot  *\n\
          *                        *\n\
          * What do you want to do?*\n\
          * I- Play                *\n\
          * II- See automatic games*\n\
          * III- Learn How to play *\n\
          * IV- GitHub             *\n\
          **************************\n");
}

int choice_initmenudisplay(int * choice) {
  while (*choice < 1 || *choice > 4 || *choice == 2 || *choice == 3) {
    scanf("%d", choice);
  }
  return *choice;
}

void playmenu() {
  printf("\033[2J");
  printf("          ************************** \n\
          *         Play Menu      *\n\
          *                        *\n\
          *What kind of game do you*\n\
          *want to play?           *\n\
          * I- Easy                *\n\
          * II- Meidum (SOON)      *\n\
          * III- Impossible (SOON) *\n\
          **************************\n");

}

int choice_playmenu(int * choice) {
  while (*choice < 1 || *choice > 3 || *choice == 2) {
    scanf("%d", choice);
  }
  return *choice;
}
