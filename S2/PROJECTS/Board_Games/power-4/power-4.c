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
#include "power-4-game.h"

//Main
int main() {
  struct Board board;
  board = init_board(7, 6);
  print_board(board, 1, "Player 1");
  int round = 1;
  int won = -1;
  while(won == -1) {
    board = play(1, board);
    won = has_won(board);
    sleep(0.1);
    print_board(board, round, "Player 1");
    if (won == -1) {
      board = play(2, board);
      won = has_won(board);
      sleep(0.1);
      print_board(board, round, "Player 2");
    }
    round++;
  }
  printf("\033[2J");
  printf("Player %c has won!\n", won);

  int i = 0;
  while (i < 6) {
    free(board.cells[i]);
    i++;
  }
  free(board.cells);
  return 0;
}
