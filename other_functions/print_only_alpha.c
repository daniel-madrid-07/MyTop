/*
** EPITECH PROJECT, 2026
** my_printf
** File description:
** print_only_alpha - prints only alphabetic characters from arguments
*/

#include "other_functions.h"

static int is_printable(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ' ';
}

static void print_arg(char *arg)
{
    for (int j = 0; arg[j] != '\0'; j++) {
        if (is_printable(arg[j]))
            my_printf("%c", arg[j]);
    }
}

int print_only_alpha(int argc, char **argv)
{
    if (argc < 1 || argv == NULL)
        return 84;
    for (int i = 1; i < argc; i++) {
        if (argv[i] == NULL)
            return 84;
        print_arg(argv[i]);
    }
    my_printf("\n");
    return 0;
}
