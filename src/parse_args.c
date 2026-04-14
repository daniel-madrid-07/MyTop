/*
** EPITECH PROJECT, 2026
** my_top
** File description:
** Parse individual arguments
*/

#include "../include/my.h"

int parse_u(char **argv, flags_t *flags, int i)
{
    flags->U = 1;
    if (argv[i + 1] == NULL) {
        write(2, "option requires an argument -- 'U'\n", 36);
        return 84;
    }
    flags->pw = getpwnam(argv[i + 1]);
    if (flags->pw == NULL) {
        write(2, "my_top: Invalid user\n", 22);
        return 84;
    }
    return 0;
}

int parse_d(char **argv, flags_t *flags, int i)
{
    flags->d = 1;
    if (argv[i + 1] == NULL) {
        write(2, "option requires an argument -- 'd'\n", 36);
        return 84;
    }
    if (!my_str_isfloat(argv[i + 1])) {
        write(2, "my_top: bad delay interval\n", 28);
        return 84;
    }
    flags->seconds = atof(argv[i + 1]);
    return 0;
}

int parse_n(char **argv, flags_t *flags, int i)
{
    flags->n = 1;
    if (argv[i + 1] == NULL) {
        write(2, "option requires an argument -- 'n'\n", 36);
        return 84;
    }
    if (!my_str_isnum(argv[i + 1])) {
        write(2, "my_top: bad iterations argument\n", 33);
        return 84;
    }
    flags->frames = atoi(argv[i + 1]);
    return 0;
}
