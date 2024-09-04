/*
** EPITECH PROJECT, 2024
** Minishell2
** File description:
** get_env.c
*/

#include "../include/minishell.h"
#include "../lib/my_string_lib/my_string_lib.h"

static char *find_str_array(char **env, char *str)
{
    for (int i = 0; env[i]; i++) {
        if (my_strncmp(env[i], str, my_strlen(str)) == 0)
            return (env[i]);
    }
    return (NULL);
}

char **get_str_env(char **env, char *str)
{
    char *res = find_str_array(env, str);
    char **res_array;

    if (res == NULL)
        return (NULL);
    res += 5;
    res_array = my_str_to_word_array_sep(res, ':');
    return (res_array);
}
