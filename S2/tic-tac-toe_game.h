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
 #include <time.h>
 #include <unistd.h>

 struct Board
 {
  int size;
  char** cells;
 };

//Prototypes
void print_board(struct Board board, int round, char name[]);
struct Board init_board(int n);
struct Board play(struct Board board);
int has_win(struct Board board);
int rand_a_b(int a, int b);
struct Board easy_AI(struct Board board);
