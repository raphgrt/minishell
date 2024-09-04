/*
** EPITECH PROJECT, 2023
** My my_compute_power_rec.c
** File description:
** my_print_comb
*/

int my_compute_power_rec(int nb, int p)
{
    if (p == 0) {
        return 1;
    }
    if (p < 0) {
        return 0;
    }
    if (p > 0) {
        nb = nb * my_compute_power_rec(nb, p - 1);
    }
    return nb;
}
