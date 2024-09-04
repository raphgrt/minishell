/*
** EPITECH PROJECT, 2023
** My my_is_prime.c
** File description:
** my_print_comb
*/

int my_is_prime(int nb)
{
    if (nb < 2) {
        return 0;
    }
    for (int i = 2; i * i <= nb; i++) {
        if (nb % i == 0) {
            return 0;
        }
    }
    return 1;
}
