/*
** EPITECH PROJECT, 2024
** Minishell
** File description:
** minishell.h
*/

#pragma once
#include <sys/types.h>
#include <signal.h>
#include <sys/uio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>

#ifndef MINISHELL_H
    #define MINISHELL_H
    #define STR_MAX_SIZE 4096
    #define BUILTINS_SUCCESS 0
    #define BUILTINS_ERR -1
    #define BUILTINS_NO_F -127

typedef struct builtins_s {
    char *name;
    int (*func)(char ***, char **);
} builtins_t;

typedef struct shell_s {
    char **env;
    char **path_array;
    char *user_input;
    char **user_input_array;
    int last_return;
} shell_t;

typedef struct my_cd_s {
    char *pwd;
    char *old_pwd;
    char *home;
} my_cd_t;

char **get_str_env(char **env, char *str);
int tty_shell(shell_t *shell);
int no_tty_shell(shell_t *shell);
int run_child(char ***envp, char **path_array, char **argv);

// Builtins
int builtins_functions(char ***env, char **argv, char *cmd);
int my_setenv(char ***env, char *name, char *value); // Only in main
int my_setenv_builtin(char ***env, char **argv);
int my_unsetenv_builtin(char ***env, char **argv);
int my_env_builtin(char ***env, char **argv);
int my_exit_builtin(char ***env, char **argv);
int my_cd_builtin(char ***env, char **argv);

#endif //MINISHELL_H
