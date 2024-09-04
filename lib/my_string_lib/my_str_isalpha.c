/*
** EPITECH PROJECT, 2023
** My my_str_isalpha.c
** File description:
** my_print_comb
*/

int my_str_isalpha(char const *str)
{
    int index = 0;

    if (str[0] == '\0') {
        return 1;
    }
    while (str[index] != '\0') {
        if (str[index] < 65 || str[index] > 122) {
            return 0;
        }
        if (str[index] > 91 && str[index] < 97) {
            return 0;
        }
        index++;
    }
    return (1);
}
