/*
** EPITECH PROJECT, 2024
** Minishell v1
** File description:
** str_count_words.c
*/

int str_count_words_char(char const *str, const char sep)
{
    int res = 0;
    int x;

    for (x = 0; str[x] && str[x + 1]; x++)
        if (str[x] == sep && (str[x + 1]) != sep)
            res++;
    if (str[x] != sep)
        res++;
    return (res);
}

int str_count_words_fn(char const *str, int (*is_separator)(char))
{
    int res = 0;
    int x;

    for (x = 0; str[x] && str[x + 1]; x++)
        if (is_separator(str[x]) && !is_separator(str[x + 1]))
            res++;
    if (!is_separator(str[x]))
        res++;
    return (res);
}
