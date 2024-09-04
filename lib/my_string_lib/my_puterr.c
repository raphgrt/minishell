/*
** EPITECH PROJECT, 2024
** Minishell v1
** File description:
** my_puterr.c
*/

#include "my_string_lib.h"

int my_puterr(const char *str)
{
    write(2, str, my_strlen(str));
    return (1);
}
