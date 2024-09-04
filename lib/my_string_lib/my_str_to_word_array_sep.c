/*
** EPITECH PROJECT, 2024
** Minishell v1
** File description:
** my_str_to_word_array_sep.c
*/

#include "my_string_lib.h"

char **my_str_to_word_array_sep(const char *str, const char sep)
{
    int j = 0;
    int len = 0;
    int nb_words = str_count_words_char(str, sep);
    char **tmp = malloc(sizeof(char *) * nb_words + 1);

    for (int i = 0; str[i]; i++) {
        if (str[i] != sep)
            len++;
        if (str[i] != sep && (str[i + 1] == sep || !str[i + 1])) {
            tmp[j] = malloc(len + 2);
            tmp[j] = my_strncpy(tmp[j], &str[(i + 1) - len], len);
            tmp[j][len] = '\0';
            len = 0;
            j++;
        }
    }
    tmp[nb_words] = NULL;
    return (tmp);
}
