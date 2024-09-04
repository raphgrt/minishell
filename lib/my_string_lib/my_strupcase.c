/*
** EPITECH PROJECT, 2023
** My my_strupcase.c
** File description:
** my_print_comb
*/

char *my_strupcase(char *str)
{
    int index = 0;

    while (str[index] != '\0') {
        if (str[index] >= 'a' && str[index] <= 'z') {
            str[index] -= 32;
        }
        index++;
    }
    return str;
}
