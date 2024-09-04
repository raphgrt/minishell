/*
** EPITECH PROJECT, 2023
** My concat_params.c
** File description:
** my_print_comb
*/

#include "my_string_lib.h"

char *my_backspace(char *dest)
{
    int index = 0;

    while (dest[index]) {
        index++;
    }
    dest[index] = '\n';
    return dest;
}

char *concat_params(int argc, char **argv)
{
    int size = 0;
    char *res;

    for (int index = 0; index < argc; index++) {
        size += my_strlen(argv[index]);
    }
    res = malloc(sizeof(char) * size);
    for (int index = 0; index < argc; index++) {
        my_strcat(res, argv[index]);
        my_backspace(res);
    }
    return (res);
}
