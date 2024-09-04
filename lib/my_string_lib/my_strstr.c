/*
** EPITECH PROJECT, 2023
** My my_strncmp.c
** File description:
** my_print_comb
*/

int check_to_find_str(char *str, char const *to_find)
{
    for (int index = 0; to_find[index] != '\0'; index++) {
        if (str[index] != to_find[index])
            return (0);
        if (str[index] == '\0')
            return (0);
    }
    return 1;
}

char *my_strstr(char *str, char const *to_find)
{
    int index = 0;
    int found = 0;
    char c = to_find[0];

    if (to_find[index] == '\0')
        return str;
    while (str[index] != '\0' && found == 0) {
        if (str[index] == c){
            found = check_to_find_str(str + index, to_find);
        }
        index++;
    }
    if (found == 1)
        return (str + index - 1);
    return (0);
}
