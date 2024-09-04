/*
** EPITECH PROJECT, 2024
** Minishell v1
** File description:
** my_env
*/

#include "../../include/minishell.h"
#include "../../lib/my_string_lib/my_string_lib.h"

int my_env_builtin(char ***env, char **argv)
{
    if (*env == NULL)
        return (1);
    for (int i = 0; (*env)[i]; i++) {
        my_putstr((*env)[i]);
        my_putchar('\n');
    }
    return (BUILTINS_SUCCESS);
}
