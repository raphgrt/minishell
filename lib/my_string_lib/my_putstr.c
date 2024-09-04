/*
** EPITECH PROJECT, 2023
** My my_putstr.c
** File description:
** my_print_comb
*/

#include "my_string_lib.h"

int my_putstr(char const *str)
{
    if (str == NULL)
        return (1);
    for (int x = 0; str[x]; x++)
        write(1, &str[x], 1);
    return (0);
}
