/*
** EPITECH PROJECT, 2026
** my_top
** File description:
** Parse command line options
*/

#include "../include/my.h"

void init_flags(flags_t *flags)
{
    flags->U = 0;
    flags->d = 0;
    flags->n = 0;
    flags->seconds = 3.0;
    flags->frames = -1;
    flags->pw = NULL;
}

int parse_options(int argc, char **argv, flags_t *flags)
{
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-' && argv[i][1] != '\0')
            parse_chooser(argv, flags, i);
    }
    return 0;
}

int parse_chooser(char **argv, flags_t *flags, int i)
{
    if (argv[i][1] == 'U')
        return parse_u(argv, flags, i);
    if (argv[i][1] == 'd')
        return parse_d(argv, flags, i);
    if (argv[i][1] == 'n')
        return parse_n(argv, flags, i);
    if (argv[i][1] == 'h')
        help();
    else {
        write(2, "invalid option", 15);
        return 84;
    }
    return 0;
}
