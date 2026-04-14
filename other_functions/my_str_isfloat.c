/*
** EPITECH PROJECT, 2026
** other_functions
** File description:
** my_str_isfloat - check if string is a valid float (e.g., "3.14", "42", ".5")
*/

#include "other_functions.h"

static int check_char(char c, int *dot_count, int *digit_count)
{
    if (c == '.') {
        (*dot_count)++;
        if (*dot_count > 1)
            return 0;
    } else if (c >= '0' && c <= '9') {
        (*digit_count)++;
    } else {
        return 0;
    }
    return 1;
}

int my_str_isfloat(char const *str)
{
    int i = 0;
    int dot_count = 0;
    int digit_count = 0;

    if (str == NULL || str[0] == '\0')
        return 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i] != '\0') {
        if (!check_char(str[i], &dot_count, &digit_count))
            return 0;
        i++;
    }
    return (digit_count > 0) ? 1 : 0;
}
