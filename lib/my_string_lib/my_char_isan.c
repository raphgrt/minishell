/*
** EPITECH PROJECT, 2023
** My my_str_isalpha.c
** File description:
** my_print_comb
*/

int my_char_an(char c)
{
    if (c >= 'A' && c <= 'Z') {
        return (1);
    }
    if (c >= 'a' && c <= 'z') {
        return (1);
    }
    if (c >= '0' && c <= '9') {
        return (1);
    }
    if (c == '_') {
        return (1);
    }
    return (0);
}
