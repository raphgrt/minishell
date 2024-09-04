/*
** EPITECH PROJECT, 2024
** Minishell v1
** File description:
** my_unsetenv
*/

#include "../../include/minishell.h"
#include "../../lib/my_string_lib/my_string_lib.h"

static int my_find_word(char **env, char *to_remove)
{
    for (int i = 0; env[i]; i++) {
        if (my_strncmp(env[i], to_remove, my_strlen(to_remove)) == 0) {
            return (i);
        }
    }
    return (-1);
}

static int error_handling(char ***env, char **argv)
{
    if (*env == NULL)
        return (my_puterr("unsetenv: No environment.\n"));
    if (my_array_length(argv) < 1)
        return (my_puterr("unsetenv: Too few arguments.\n"));
    if (my_array_length(argv) > 2)
        return (1);
    return (0);
}

void my_unsetenv(char ***env, char *to_remove)
{
    char **new_env = NULL;
    int i = 0;
    int j = 0;

    for (; (*env)[i] != NULL; i++);
    new_env = malloc(sizeof(char *) * i);
    for (i = 0; (*env)[i] != NULL; i++) {
        if (my_strncmp((*env)[i], to_remove, my_strlen(to_remove)) == 0) {
            continue;
        }
        new_env[j] = (*env)[i];
        j++;
    }
    new_env[j] = NULL;
    *env = new_env;
}

int my_unsetenv_builtin(char ***env, char **argv)
{
    int index;

    if (error_handling(env, argv) == 1)
        return (BUILTINS_ERR);
    index = my_find_word((*env), argv[1]);
    if (index == -1)
        return (BUILTINS_ERR);
    my_unsetenv(env, argv[1]);
    return (BUILTINS_SUCCESS);
}
