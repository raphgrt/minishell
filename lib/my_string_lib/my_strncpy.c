/*
** EPITECH PROJECT, 2023
** My my_strncpy.c
** File description:
** my_print_comb
*/

#include "my_string_lib.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int index = 0;
    int size = my_strlen(src);

    for (index = 0; index < n; index++) {
        dest[index] = src[index];
    }
    if (n > size) {
        dest[index] = '\0';
    }
    return (dest);
}
