/*
** EPITECH PROJECT, 2023
** My my_strlen.c
** File description:
** my_print_comb
*/

int my_strlen(char const *str)
{
    int len = 0;

    while (str[len] != '\0') {
        len ++;
    }
    return len;
}
