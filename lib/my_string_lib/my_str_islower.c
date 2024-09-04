/*
** EPITECH PROJECT, 2023
** My my_str_islower.c
** File description:
** my_print_comb
*/

int my_str_islower(char const *str)
{
    int index = 0;

    if (str[0] == '\0') {
        return 1;
    }
    while (str[index] != '\0') {
        if (str[index] < 'a' || str[index] > 'z') {
            return 0;
        }
        index++;
    }
    return 1;
}
