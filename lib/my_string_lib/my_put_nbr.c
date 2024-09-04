/*
** EPITECH PROJECT, 2023
** My my_put_nbr.c
** File description:
** my_print_comb, write_number
*/

#include "my_string_lib.h"

void write_number(int number)
{
    int chiffre = number % 10 + 48;

    if (number >= 10) {
        write_number(number / 10);
        write(1, &chiffre, 1);
        } else {
        write(1, &chiffre, 1);
    }
}

int my_put_nbr(int nb)
{
    if (nb == 2147483647) {
        write(1, "2147483647", 10);
        return 0;
    }
    if (nb == -2147483648) {
        write(1, "-2147483648", 11);
        return 0;
    }
    if (nb < 0) {
        nb *= -1;
        write(1, "-", 1);
        write_number(nb);
    } else {
        write_number(nb);
    }
    return 0;
}
