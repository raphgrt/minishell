/*
** EPITECH PROJECT, 2024
** Minishell v1
** File description:
** my_exit
*/

#include "../../include/minishell.h"
#include "../../lib/my_string_lib/my_string_lib.h"

static int is_exit_input(char *str)
{
    int is_correct = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            is_correct = 0;
            break;
        }
    }
    if (!is_correct && str[0] >= '0' && str[0] <= '9') {
        my_puterr("exit: Badly formed number.\n");
        return 0;
    }
    if (!is_correct) {
        my_puterr("exit: Expression Syntax.\n");
        return 0;
    }
    return 1;
}

int my_exit_builtin(char ***env, char **argv)
{
    if (argv[1] == NULL)
        exit(0);
    if (is_exit_input(argv[1]) == 0)
        exit(1);
    exit(my_getnbr(argv[1]));
    return (BUILTINS_SUCCESS);
}
