/*
** EPITECH PROJECT, 2024
** Minishell v1
** File description:
** is_in_string.c
*/

#include "my_string_lib.h"

int str_find_word(const char *src, const char *text)
{
    int src_len;
    int text_len;

    if (src == NULL || text == NULL)
        return (-1);
    src_len = my_strlen(src);
    text_len = my_strlen(text);
    if (src_len < text_len)
        return (-1);
    for (int i = 0; src[i]; i++) {
        if (src[i] == text[0] && my_strncmp(&src[i], text, text_len) == 0)
            return (1);
    }
}
