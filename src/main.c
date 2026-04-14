/*
** EPITECH PROJECT, 2026
** my_top
** File description:
** Main entry point
*/

#include "../include/my.h"

int main(int argc, char **argv)
{
    flags_t flags;

    init_flags(&flags);
    if (parse_options(argc, argv, &flags) != 0)
        return 84;
    init_ncurses();
    main_loop(&flags);
    cleanup_ncurses();
    return 0;
}
