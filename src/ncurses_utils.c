/*
** EPITECH PROJECT, 2026
** my_top
** File description:
** ncurses utilities
*/

#include "../include/my.h"

void init_ncurses(void)
{
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    curs_set(0);
}

void cleanup_ncurses(void)
{
    endwin();
}
