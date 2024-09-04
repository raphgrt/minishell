/*
** EPITECH PROJECT, 2024
** Minishell2
** File description:
** builtins.c
*/

#include "../../include/minishell.h"
#include "../../lib/my_string_lib/my_string_lib.h"

const builtins_t BUILTINS[] = {
    {"cd", &my_cd_builtin},
    {"env", &my_env_builtin},
    {"setenv", &my_setenv_builtin},
    {"unsetenv", &my_unsetenv_builtin},
    {"exit", &my_exit_builtin},
    {NULL, NULL}
};

int builtins_functions(char ***env, char **argv, char *cmd)
{
    for (int i = 0; BUILTINS[i].name; i++) {
        if (my_strcmp(cmd, BUILTINS[i].name) == 0) {
            return (BUILTINS[i].func(env, argv));
        }
    }
    return (1);
}
