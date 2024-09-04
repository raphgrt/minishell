/*
** EPITECH PROJECT, 2024
** Minishell v2
** File description:
** my_array_length.c
*/

#include "my_string_lib.h"

int my_array_length(char **array)
{
    int i = 0;

    for (; array[i]; i++);
    return (i);
}
