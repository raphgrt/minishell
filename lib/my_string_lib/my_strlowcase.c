/*
** EPITECH PROJECT, 2023
** My my_strlowcase.c
** File description:
** my_print_comb
*/

char *my_strlowcase(char *str)
{
    int index = 0;

    while (str[index]) {
        if (str[index] >= 'A' && str[index] <= 'Z') {
            str[index] += 32;
        }
        index++;
    }
    return str;
}
