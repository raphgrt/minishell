/*
** EPITECH PROJECT, 2024
** Minishell2
** File description:
** main.c
*/

#include "../include/minishell.h"
#include "../lib/my_string_lib/my_string_lib.h"

static char **str_array_dup(char **array)
{
    char **new_array;
    int len;

    for (len = 0; array[len]; len++);
    new_array = malloc(sizeof(char *) * (len + 1));
    for (int i = 0; array[i]; i++)
        new_array[i] = my_strdup(array[i]);
    new_array[len] = NULL;
    return (new_array);
}

static int check_args(int ac, char **av)
{
    if (ac > 1) {
        my_putstr("Usage: ");
        my_putstr(av[0]);
        my_putstr("\n");
        return (1);
    }
    return (0);
}

static shell_t *init_shell(char **env)
{
    shell_t *shell = malloc(sizeof(shell_t));

    shell->env = str_array_dup(env);
    shell->user_input = NULL;
    shell->user_input_array = NULL;
    shell->path_array = get_str_env(env, "PATH=");
    shell->last_return = 0;
    return (shell);
}

static void free_shell(shell_t *shell)
{
    if (shell->user_input)
        free(shell->user_input);
    if (shell->user_input_array)
        free_word_array(shell->user_input_array);
    if (shell->path_array)
        free_word_array(shell->path_array);
    if (shell->env)
        free_word_array(shell->env);
    free(shell);
}

char *get_current_pwd(void)
{
    char *pwd = malloc(sizeof(char) * STR_MAX_SIZE);

    getcwd(pwd, STR_MAX_SIZE);
    if (pwd == NULL) {
        my_puterr("Error: getcwd failed\n");
        return (NULL);
    }
    return (pwd);
}

int main(int ac, char **av, char **env)
{
    shell_t *shell;
    int return_value = 0;

    if (check_args(ac, av))
        return (84);
    shell = init_shell(env);
    my_setenv(&shell->env, "PWD", get_current_pwd());
    if (!isatty(STDIN_FILENO)) {
        return_value = no_tty_shell(shell);
        return (return_value);
    }
    return_value = tty_shell(shell);
    free_shell(shell);
    return (return_value);
}
