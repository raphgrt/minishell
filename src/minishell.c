/*
** EPITECH PROJECT, 2024
** Minishell2
** File description:
** minishell.c
*/

#include "../include/minishell.h"
#include "../lib/my_string_lib/my_string_lib.h"

static int exec_command(shell_t *shell, int index)
{
    int ret = 0;
    char **argv = my_str_to_word_array(shell->user_input_array[index]);

    if (argv == NULL) {
        printf("Error: malloc failed\n");
        return (1);
    }
    ret = builtins_functions(&shell->env, argv, argv[0]);
    if (ret == 1)
        return (run_child(&shell->env, shell->path_array, argv));
    return (ret);
}

int commands_getter(shell_t *shell)
{
    int result = 0;

    shell->user_input_array = my_str_to_word_array_sep(shell->user_input, ';');
    if (shell->user_input_array == NULL)
        return (1);
    for (int i = 0; shell->user_input_array[i]; i++) {
        result = exec_command(shell, i);
        if (result != 0)
            break;
    }
    return (result);
}

int tty_shell(shell_t *shell)
{
    ssize_t size;
    size_t len;

    while (1) {
        my_putstr("$> ");
        size = getline(&shell->user_input, &len, stdin);
        if (size == -1)
            break;
        shell->user_input[size - 1] = '\0';
        if (my_strcmp(shell->user_input, "") == 0)
            continue;
        commands_getter(shell);
    }
    return (0);
}

int no_tty_shell(shell_t *shell)
{
    ssize_t size;
    size_t len;
    int ret = 0;

    while (1) {
        size = getline(&shell->user_input, &len, stdin);
        if (size == -1)
            break;
        shell->user_input[size - 1] = '\0';
        if (my_strcmp(shell->user_input, "") == 0)
            continue;
        ret = commands_getter(shell);
    }
    if (ret < 0)
        return (ret * -1);
    return (ret);
}
