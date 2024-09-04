/*
** EPITECH PROJECT, 2023
** My my_strcat.c
** File description:
** my_strcat
*/

char *my_strncat(char *dest, char const *src, int n)
{
    int index = 0;

    while (dest[index]) {
        index++;
    }
    for (int index_2 = 0; index_2 < n; index_2++) {
        dest[index] = src[index_2];
        index++;
    }
    dest[index + 1] = '\0';
    return dest;
}
