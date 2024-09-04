/*
** EPITECH PROJECT, 2024
** Minishell v1
** File description:
** my_cd.c
*/

#include "../../include/minishell.h"
#include "../../lib/my_string_lib/my_string_lib.h"

static int cd_error(char *pathname)
{
    if (chdir(pathname) != 0 &&
    (errno == ENOENT || errno == EACCES || errno == ENOTDIR)) {
        my_putstr(pathname);
        my_putstr(" : ");
        my_puterr(strerror(errno));
        my_putchar('\n');
        return (BUILTINS_ERR);
    }
    return (0);
}

static int count_array(char **array)
{
    int i = 0;

    for (; array[i]; i++);
    return (i);
}

int my_cd_back(my_cd_t *cd, char ***env)
{
    char *tmp = NULL;
    int ret = cd_error(cd->old_pwd);

    if (ret == 0) {
        tmp = cd->old_pwd;
        cd->old_pwd = cd->pwd;
        cd->pwd = tmp;
        my_setenv(env, "PWD", cd->pwd);
        my_setenv(env, "OLDPWD", cd->old_pwd);
        return (BUILTINS_SUCCESS);
    }
    return (BUILTINS_ERR);
}

int my_cd_home(my_cd_t *cd, char ***env)
{
    int ret = cd_error(cd->home);

    if (ret == 0) {
        cd->old_pwd = cd->pwd;
        cd->pwd = cd->home;
        my_setenv(env, "PWD", cd->pwd);
        my_setenv(env, "OLDPWD", cd->old_pwd);
        return (BUILTINS_SUCCESS);
    }
    return (BUILTINS_ERR);
}

int my_cd(my_cd_t *cd, char ***env, char *direction)
{
    int ret = cd_error(direction);

    if (ret == 0) {
        cd->old_pwd = cd->pwd;
        cd->pwd = direction;
        my_setenv(env, "PWD", cd->pwd);
        my_setenv(env, "OLDPWD", cd->old_pwd);
        return (BUILTINS_SUCCESS);
    }
    return (BUILTINS_ERR);
}

int my_cd_builtin(char ***env, char **argv)
{
    my_cd_t cd_info;

    cd_info.old_pwd = get_str_env(*env, "PWD=")[0];
    cd_info.home = get_str_env(*env, "HOME=")[0];
    cd_info.pwd = get_str_env(*env, "PWD=")[0];
    if (count_array(argv) > 2) {
        my_puterr("cd: Too many arguments.\n");
        return (1);
    }
    if (argv[1] == NULL || my_strncmp(argv[1], "~", 1) == 0)
        return (my_cd_home(&cd_info, env));
    if (my_strcmp(argv[1], "-") == 0)
        return (my_cd_back(&cd_info, env));
    return (my_cd(&cd_info, env, argv[1]));
}
