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
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

//Structures
struct Board {
  char** cells;
  int xsize;
  int ysize;
  int last_row;
  int last_col;
};

//Prototypes
void print_board(struct Board board, int round, char name[]);
struct Board init_board(int x, int y);
struct Board play(int player_id, struct Board board);
int is_full(struct Board board, int column);
int has_won(struct Board board);
int has_won_diff(struct Board board);
