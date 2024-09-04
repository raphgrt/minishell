/*
** EPITECH PROJECT, 2023
** My str_dup.h
** File description:
** my_print_comb
*/

#include "my_string_lib.h"

char **my_str_to_word_array(char const *str)
{
    int j = 0;
    int len = 0;
    int nb_words = str_count_words_fn(str, &my_char_issep);
    char **tmp = malloc(sizeof(char *) * nb_words + 1);

    for (int i = 0; str[i]; i++) {
        if (!my_char_issep(str[i]))
            len++;
        if (my_char_issep(str[i]) == 0 && my_char_issep(str[i + 1]) == 1) {
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
