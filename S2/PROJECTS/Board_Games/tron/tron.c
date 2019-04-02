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

 //Main

int main() {
  FILE * fp;
  fp = fopen("log.txt", "w");
  struct Board board;
  board = init_board(21, 21);
  int round = 1;
  struct Player player1;
  struct Player player2;
  player1 = init_player(1, 5);
  player2 = init_player(2, 15);
  board.cells[10][5] = '1';
  fprintf(fp, "%d,%d\n", player1.last_row, player1.last_col);
  fprintf(fp, "%d,%d\n", player2.last_row, player2.last_col);
  board.cells[10][15] = '2';
  print_board(board, round, "Player 1");
  while (player1.alive == 1 && player2.alive == 1) {
    board = play(board, &player1);
    fprintf(fp, "%d,%d\n", player1.last_row, player1.last_col);
    print_board(board, round, "Player 2");
    board = play(board, &player2);
    fprintf(fp, "%d,%d\n", player2.last_row, player2.last_col);
    round++;
    print_board(board, round, "Player 1");
  }
  fclose(fp);

  int i = 0;
  while (i < 6) {
    free(board.cells[i]);
    i++;
  }
  free(board.cells);
  replay();
  if (player1.alive == 0) {
    printf("Player 2 has won!");
  }
  else {
    printf("Player 1 has won!");
  }

  return 0;
}
