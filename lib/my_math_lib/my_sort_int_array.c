/*
** EPITECH PROJECT, 2023
** My my_sort_int_array.c
** File description:
** my_print_comb
*/

void my_sort_int_array(int *array, int size)
{
    int joueur_droite = 0;
    int joueur_gauche = 0;
    int tmp;

    while (joueur_gauche < size) {
        if (joueur_droite > size - 1) {
            joueur_gauche++;
            joueur_droite = joueur_gauche;
        }
        if (joueur_gauche >= size) {
            break;
        }
        if (array[joueur_droite] < array[joueur_gauche]) {
            tmp = array[joueur_droite];
            array[joueur_droite] = array[joueur_gauche];
            array[joueur_gauche] = tmp;
        }
        joueur_droite++;
    }
}
