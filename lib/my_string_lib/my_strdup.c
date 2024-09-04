/*
** EPITECH PROJECT, 2023
** My my_strdup.c
** File description:
** my_print_comb
*/

#include "my_string_lib.h"

char *my_strdup(char const *src)
{
    char *res;
    int size;

    size = my_strlen(src);
    res = malloc(sizeof(char) * size + 1);
    my_strcpy(res, src);
    res[size] = '\0';
    return (res);
}
