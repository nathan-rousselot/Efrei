/*
 * File:   terminal_linux.h
 * Author: Louis CHEREL
 *
 * Created on 30 avril 2013, 14:34
 */

#ifndef TERMINAL_H
#define	TERMINAL_H

typedef enum e_termColors {
        BLACK,
        RED,
        GREEN,
        DARKGREEN,
        BLUE,
        MAGENTA,
        CYAN,
        WHITE
} termColors;


void setCurs(int x, int y);
void cleanTerm();
void setTextColor(int color);
void setBackgroundColor(int color);

#endif	/* TERMINAL_H */
