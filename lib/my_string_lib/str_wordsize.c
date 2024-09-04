/*
** EPITECH PROJECT, 2024
** Minishell v1
** File description:
** str_wordsize.c
*/

#include "my_string_lib.h"

int *str_wordsize_fn(char const *str, int *len, int (*is_separator)(char))
{
    int index = 0;
    int tmp_count = 0;
    int x;

    if (str == NULL || len == NULL)
        return (NULL);
    for (x = 0; str[x] && str[x + 1]; x++) {
        if (is_separator(str[x]) && !is_separator(str[x + 1])) {
            len[index] = tmp_count + 1;
            tmp_count = 0;
            index++;
        } else {
            tmp_count++;
        }
    }
    if (x > 0 && index != 0)
        len[index] = tmp_count + 2;
    return (len);
}

int *str_wordsize_char(char const *str, int *len, const char sep)
{
    int index = 0;
    int tmp_count = 0;
    int x;

    if (str == NULL || len == NULL)
        return (NULL);
    for (x = 0; str[x] && str[x + 1]; x++) {
        if (str[x] == sep && str[x + 1] != sep) {
            len[index] = tmp_count + 1;
            tmp_count = 0;
            index++;
        } else {
            tmp_count++;
        }
    }
    if (x > 0 && index != 0)
        len[index] = tmp_count + 2;
    return (len);
}
