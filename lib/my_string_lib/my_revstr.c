/*
** EPITECH PROJECT, 2023
** My my_revstr.c
** File description:
** my_print_comb
*/

#include "my_string_lib.h"

char *my_revstr(char *str)
{
    int index = my_strlen(str);
    int index2 = 0;
    int size = index;
    char c = str[index];

    index--;
    while (index > index2) {
        c = str[index2];
        str[index2] = str[index];
        str[index] = c;
        index--;
        index2++;
    }
    str[size] = '\0';
    return (str);
}
