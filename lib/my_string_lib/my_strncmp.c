/*
** EPITECH PROJECT, 2023
** My my_strncmp.c
** File description:
** my_print_comb
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int index = 0;

    while ((s1[index] != '\0' && s2[index] != '\0') || index < n) {
        if (s1[index] != s2[index]) {
            return (s1[index] - s2[index]);
        }
        index++;
    }
    return (0);
}
