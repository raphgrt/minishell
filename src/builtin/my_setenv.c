/*
** EPITECH PROJECT, 2024
** Minishell2
** File description:
** my_setenv.c
*/

#include "../../include/minishell.h"
#include "../../lib/my_string_lib/my_string_lib.h"

static char **add_str_to_array(char **array, char *str)
{
    int len;
    char **new_array;

    for (len = 0; array[len]; len++);
    new_array = malloc(sizeof(char *) * (len + 2));
    for (int i = 0; array[i]; i++)
        new_array[i] = my_strdup(array[i]);
    new_array[len] = my_strdup(str);
    new_array[len + 1] = NULL;
    return (new_array);
}

int my_setenv(char ***env, char *name, char *value)
{
    char *new_name;
    char *new_line;

    if (name == NULL || value == NULL)
        return (1);
    new_name = my_strcat(name, "=");
    new_line = my_strcat(new_name, value);
    *env = add_str_to_array(*env, new_line);
    return (BUILTINS_SUCCESS);
}

static int my_char_isalpha(char c)
{
    if (c >= 'a' && c <= 'z')
        return 1;
    if (c >= 'A' && c <= 'Z')
        return 1;
    return 0;
}

static int is_correct_name(char *name)
{
    if (!my_char_isalpha(name[0]) && name[0] != '_') {
        write(2, "setenv: Variable name must begin with a letter.\n", 48);
        return 0;
    }
    for (int i = 0; name[i] != '\0'; i++) {
        if (!my_char_an(name[i])) {
            my_puterr(
            "setenv: Variable name must contain alphanumeric characters.\n");
            return (BUILTINS_ERR);
        }
    }
    return (BUILTINS_SUCCESS);
}

static int my_str_contain_char(char *str, char c)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            return 1;
    }
    return 0;
}

int my_setenv_builtin(char ***env, char **argv)
{
    if (argv[1] == NULL)
        return (BUILTINS_ERR);
    if (argv[3] != NULL) {
        my_putstr("setenv: Too many arguments.\n");
        return (BUILTINS_ERR);
    }
    if (is_correct_name(argv[1]) == BUILTINS_ERR)
        return (BUILTINS_ERR);
    if (my_str_contain_char(argv[1], '=') == 1) {
        my_putstr("setenv: Variable name must not contain '='.\n");
        return (BUILTINS_ERR);
    }
    return (my_setenv(env, argv[1], argv[2]));
}
