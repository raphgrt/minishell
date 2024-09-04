/*
** EPITECH PROJECT, 2023
** My my_isneg.c
** File description:
** my_print_comb
*/

#include <unistd.h>

int my_isneg(int n)
{
    if (n >= 0) {
        write(1, "P", 1);
        return 0;
    }
    write(1, "N", 1);
    return 0;
}
