#include <stdio.h>
#include <stdlib.h>
#include "terminal_linux.h"

int __TERM_TEXT_COLOR = WHITE;
int __TERM_BACKGROUND_COLOR = BLACK;


void setCurs (int x, int y) {
    printf("\033[%d;%dH\n", x, y);
}

void cleanTerm () {
    printf("\033[2J");
}

void setTextColor (int color) {
    __TERM_TEXT_COLOR = color;
    printf("\033[%d;%dm", color + 30, __TERM_BACKGROUND_COLOR + 40);
}

void setBackgroundColor (int color) {
    __TERM_BACKGROUND_COLOR = color;
    printf("\033[%d;%dm", __TERM_TEXT_COLOR + 30, color + 40);
}
