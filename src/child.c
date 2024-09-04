/*
** EPITECH PROJECT, 2024
** Minishell v1
** File description:
** child.c
*/

#include "../include/minishell.h"
#include "../lib/my_string_lib/my_string_lib.h"

/*
 ** child process generation
 **
 ** @param   path    bin executable path
 ** @param   argv    args for command
 ** @param   envp    main envp
 ** @return  ch_pid  children's PID
*/
static pid_t gen_child(const char *path, char *const *argv, char *const *envp)
{
    pid_t ch_pid = fork();

    if (ch_pid == -1) {
        perror("fork failure");
        exit(EXIT_FAILURE);
    }
    if (ch_pid > 0)
        return (ch_pid);
    execve(path, argv, envp);
    perror("execve failure");
    exit(EXIT_FAILURE);
}

void exec_error(int wstatus)
{
    int signal = WTERMSIG(wstatus);

    if (WIFSIGNALED(wstatus) == 0)
        return;
    if ((signal == SIGSEGV || signal == SIGFPE) && WCOREDUMP(wstatus))
        my_putstr(" (core dumped)\n");
    else if (WCOREDUMP(wstatus))
        my_putstr("Abort (core dumped)\n");
    if (signal == SIGSEGV)
        my_puterr("Segmentation fault\n");
    if (signal == SIGFPE)
        my_puterr("Floating exception\n");
    if (errno == ENOEXEC)
        my_puterr("Wrong Architecture.\n");
    else
        my_puterr("Unhandled signal\n");
}

static char *get_pathname_cmd(char *cmd, char **path_array)
{
    char *pathname = NULL;
    char *tmp = NULL;

    if (access(cmd, F_OK) == 0)
        return (cmd);
    for (int i = 0; path_array[i]; i++) {
        tmp = my_strcat(path_array[i], "/");
        pathname = my_strcat(tmp, cmd);
        free(tmp);
        if (access(pathname, F_OK) == 0)
            return my_strdup(pathname);
        free(pathname);
    }
    return (NULL);
}

int run_child(char ***envp, char **path_array, char **argv)
{
    pid_t child;
    int wstatus;
    char *pathame = get_pathname_cmd(argv[0], path_array);

    if (pathame == NULL) {
        my_puterr(argv[0]);
        my_puterr(": Command not found.\n");
        return (1);
    }
    child = gen_child(pathame, argv, *envp);
    if (waitpid(child, &wstatus, WUNTRACED | WCONTINUED) == -1) {
        perror("Error");
        exit(1);
    }
    exec_error(wstatus);
    return (EXIT_SUCCESS);
}
