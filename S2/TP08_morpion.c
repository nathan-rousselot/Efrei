#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Structures
struct Board
{
  int size;
  char** cells;
};

struct Player
{
  int id;
  char* nick;
  int wins;
  int loses;
};

//Prototypes
void print_board(struct Board board);
struct Board init_board(int n);
struct Board play(struct Player player, struct Board board);
struct Player init_players(int id);
int has_win(struct Board board, struct Player player1, struct Player player2);

//Main
int main() {
  //Init of the game
  printf("Welcome to Tic Tac Toe, the game.\n");
  struct Player player1;
  struct Player player2;
  player1 = init_players(1);
  player2 = init_players(2);
  struct Board board;
  board = init_board(3);
  print_board(board);

  //Start of the game
  int p = 0;
  while (player1.wins < 3 && player2.wins < 3) {
    if (p == 0) {
      board = play(player1, board);
      p = 1;
    }
    else {
      board = play(player2, board);
      p = 0;
    }
    print_board(board);
    int has_won = has_win(board, player1, player2);
    if (has_won == 0) {
      player1.wins++;
      player2.loses++;
      board = init_board(3);
    }
    else if (has_won == 1) {
      player2.wins++;
      player1.loses++;
      board = init_board(3);
    }
  }

  //Free operations
  int i = 0;
  while (i < board.size) {
    free(board.cells[i]);
    i++;
  }
  free(board.cells);

  //Do not touch this
  return 0;
}

//Functions
void print_board(struct Board board) {
  //This function take a board as a parameter, and prints it in a stilized way...
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

struct Player init_players(int id) {
  //This function creates a single player
  struct Player player;
  printf("Hello Player %d, what is your Nickname?\n");
  scanf("%s", &player.nick);
  player.id = id;
  player.wins = 0;
  player.loses = 0;
  return player;
}

struct Board play(struct Player player, struct Board board) {
  //This function simulate one turn of play.
  int isok = 1;
  while (isok == 1) {
    int line;
    int col;
    printf("It's up to %s to play!\nOn which line do you want to play?\n", &player.nick);
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
      if (player.id == 1) {
        board.cells[line][col] = 'O';
      }
      else {
        board.cells[line][col] = 'X';
      }
      isok = 0;
    }
  }
  return board;
}

int has_win(struct Board board, struct Player player1, struct Player player2) {
  //This function check wether somebody has won already or not.
  int i = 0;
  int j = 0;
  if (board.cells[0][0] == board.cells[0][1] && board.cells[0][1] == board.cells[0][2] && board.cells[0][0] != ' ') {
    printf("%s has won!\n", &player1.nick);
    if (board.cells[0][0] == 'O') {
      return 0;
    }
    printf("%s has won!\n", &player2.nick);
    return 1;
  }
  else if (board.cells[1][0] == board.cells[1][1] && board.cells[1][1] == board.cells[1][2] && board.cells[1][0] != ' ') {
    if (board.cells[1][0] == 'O') {
      printf("%s has won!\n", &player1.nick);
      return 0;
    }
    printf("%s has won!\n", &player2.nick);
    return 1;
  }
  else if (board.cells[2][0] == board.cells[2][1] && board.cells[2][1] == board.cells[2][2] && board.cells[2][0] != ' ') {
    if (board.cells[2][0] == 'O') {
      printf("%s has won!\n", &player1.nick);
      return 0;
    }
    printf("%s has won!\n", &player2.nick);
    return 1;
  }
  else if (board.cells[0][0] == board.cells[1][0] && board.cells[1][0] == board.cells[2][0] && board.cells[0][0] != ' ') {
    if (board.cells[0][0] == 'O') {
      printf("%s has won!\n", &player1.nick);
      return 0;
    }
    printf("%s has won!\n", &player2.nick);
    return 1;
  }
  else if (board.cells[0][1] == board.cells[1][1] && board.cells[1][1] == board.cells[2][1] && board.cells[0][1] != ' ') {
    if (board.cells[0][1] == 'O') {
      printf("%s has won!\n", &player1.nick);
      return 0;
    }
    printf("%s has won!\n", &player2.nick);
    return 1;
  }
  else if (board.cells[0][2] == board.cells[1][2] && board.cells[1][2] == board.cells[2][2] && board.cells[0][2] != ' ') {
    if (board.cells[0][2] == 'O') {
      printf("%s has won!\n", &player1.nick);
      return 0;
    }
    printf("%s has won!\n", &player2.nick);
    return 1;
  }
  else if (board.cells[0][0] == board.cells[1][1] && board.cells[1][1] == board.cells[2][2] && board.cells[0][0] != ' ') {
    if (board.cells[0][0] == 'O') {
      printf("%s has won!\n", &player1.nick);
      return 0;
    }
    printf("%s has won!\n", &player2.nick);
    return 1;
  }
  else if (board.cells[0][2] == board.cells[1][1] && board.cells[1][1] == board.cells[2][0] && board.cells[0][2] != ' ') {
    if (board.cells[1][1] == 'O') {
      printf("%s has won!\n", &player1.nick);
      return 0;
    }
    printf("%s has won!\n", &player2.nick);
    return 1;
  }
  return -1;
}
