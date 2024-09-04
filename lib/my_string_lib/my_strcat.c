/*
** EPITECH PROJECT, 2023
** My my_strcat.c
** File description:
** my_strcat
*/

#include "my_string_lib.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;
    char *new_str;

    new_str = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));
    if (new_str == NULL)
        return (NULL);
    while (dest[i] != '\0') {
        new_str[i] = dest[i];
        i++;
    }
    while (src[j] != '\0') {
        new_str[i] = src[j];
        i++;
        j++;
    }
    new_str[i] = '\0';
    return (new_str);
}
