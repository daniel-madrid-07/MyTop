/*
** EPITECH PROJECT, 2026
** my_top
** File description:
** Help display
*/

#include "../include/my.h"

void help(void)
{
    my_printf("Usage:\n");
    my_printf("  my_top [options]\n");
    my_printf("\n");
    my_printf("Options:\n");
    my_printf("-d, --delay =SECS [.TENTHS\n");
    my_printf("-n, --iterations =NUMBER\n");
    my_printf("-U, --filter-any-user =USER\n");
    my_printf("-h, --help\n");
}
