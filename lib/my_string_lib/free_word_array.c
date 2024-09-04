/*
** EPITECH PROJECT, 2024
** Minishell v1
** File description:
** free_word_array.c
*/

#include "my_string_lib.h"

int free_word_array(char **wrd_array)
{
    for (int x = 0; wrd_array[x]; x++) {
        free(wrd_array[x]);
    }
    free(wrd_array);
    if (wrd_array != NULL)
        return (0);
    return (-1);
}
