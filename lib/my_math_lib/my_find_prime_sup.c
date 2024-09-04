/*
** EPITECH PROJECT, 2023
** My my_find_prime_sup.c
** File description:
** my_print_comb
*/

int prime(int nb)
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

int my_find_prime_sup(int nb)
{
    int index = nb;
    int is_valid = prime(index);

    while (!is_valid) {
        index++;
        is_valid = prime(index);
    }
    return index;
}
