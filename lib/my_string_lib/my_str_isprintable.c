/*
** EPITECH PROJECT, 2023
** My my_str_isprintable.c
** File description:
** my_print_comb
*/

int my_str_isprintable(char const *str)
{
    int index = 0;

    if (str[0] == '\0') {
        return 1;
    }
    while (str[index]) {
        if (str[index] < 32 || str[index] == 127) {
            return (0);
        }
        index++;
    }
    return (1);
}
