/*
** EPITECH PROJECT, 2023
** My my_strcapitalize.c
** File description:
** my_print_comb
*/

#include "my_string_lib.h"

int is_letter(char c)
{
    if (c >= 'a' && c <= 'z') {
        return (1);
    }
    return (0);
}

int is_sep(char c)
{
    if (c == ' ') {
        return 1;
    }
    if (c >= 33 && c <= 47) {
        return 1;
    }
    if (c >= 58 && c <= 64) {
        return 1;
    }
    if (c >= 91 && c <= 96) {
        return 1;
    }
    return 0;
}

char *my_strcapitalize(char *str)
{
    int index = 0;

    str = my_strlowcase(str);
    if (is_letter(str[index])) {
        str[index] -= 32;
    }
    while (str[index] != '\0') {
        if (is_sep(str[index]) && is_letter(str[index + 1])) {
            str[index + 1] -= 32;
        }
        index++;
    }
    return str;
}
