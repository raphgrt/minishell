/*
** EPITECH PROJECT, 2023
** My concat_params.c
** File description:
** lib_header
*/

#include <stdlib.h>
#include <unistd.h>

#pragma once
#ifndef MY_H
    #define MY_H

char *my_backspace(char *dest);
char *my_backspace(char *dest);
int my_char_an(char c);
int my_char_issep(char c);
int my_getnbr(char const *str);
int my_array_length(char **array);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
char *my_revstr(char *str);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
char **my_str_to_word_array(char const *str);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int n);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
int my_char_isnum(char c);
int my_do_op(int argc, char **argv);
int str_count_words_fn(char const *str, int (*is_separator)(char));
int str_count_words_char(char const *str, const char sep);
int *str_wordsize_char(char const *str, int *len, const char sep);
int *str_wordsize_fn(char const *str, int *len, int (*is_separator)(char));
int str_find_word(const char *src, const char *text);
char **my_str_to_word_array_sep(const char *str, const char sep);
int free_word_array(char **wrd_array);
int my_puterr(const char *str);
#endif
