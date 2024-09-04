/*
** EPITECH PROJECT, 2023
** My my_strcpy.c
** File description:
** my_print_comb
*/

char *my_strcpy(char *dest, char const *src)
{
    int index = 0;
    char c = src[index];

    while (c != '\0') {
        dest[index] = c;
        index ++;
        c = src[index];
    }
    dest[index] = '\0';
    return dest;
}
