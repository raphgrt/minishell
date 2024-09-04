/*
** EPITECH PROJECT, 2023
** My my_compute_square_root.c
** File description:
** my_print_comb
*/

int my_power(int nb, int p)
{
    if (p == 0) {
        return 1;
    }
    if (p < 0) {
        return 0;
    }
    if (p > 0) {
        nb = nb * my_power(nb, p - 1);
    }
    return nb;
}

int core_power(int nb, int start_number, int res, int bit)
{
    while (bit > start_number) {
        bit /= 4;
    }
    while (bit > 0) {
        if (start_number >= res + bit) {
            start_number -= res + bit;
            res = (res / 2) + bit;
        } else {
            res /= 2;
        }
        bit /= 4;
    }
    return res;
}

int my_compute_square_root(int nb)
{
    int res = 0;
    int bit = 1 << 30;
    int start_number = nb;

    if (nb <= 0) {
        return 0;
    }
    res = core_power(nb, start_number, res, bit);
    if (my_power(res, 2) != nb) {
        return 0;
    }
    return res;
}
