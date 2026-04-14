/*
** EPITECH PROJECT, 2026
** other_functions
** File description:
** my_str_contains_all - checks if s2 contains all characters from s1
*/

#include "other_functions.h"

int my_str_contains_all(char const *s1, char const *s2)
{
    if (s1 == NULL || s2 == NULL)
        return 0;
    for (int i = 0; s1[i] != '\0'; i++) {
        if (my_str_count_char(s1, s1[i]) > my_str_count_char(s2, s1[i]))
            return 0;
    }
    return 1;
}
