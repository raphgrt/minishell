/*
** EPITECH PROJECT, 2024
** Minishell v1
** File description:
** my_char_issep.c
*/

int my_char_issep(char c)
{
    switch (c) {
        case ' ':
            return (1);
        case '\t':
            return (1);
        case '\0':
            return (1);
    }
    return (0);
}
