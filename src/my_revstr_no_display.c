/*
** EPITECH PROJECT, 2018
** my_revstr.c
** File description:
** task03
*/

#include "function.h"

char *my_revstr_no_display(char *str)
{
    char temp;
    int n = 0;
    int i = 0;
    temp = str[0];

    while (str[n] != '\0')
        n++;
    n--;
    while (n >= i) {
        temp = str[i];
        str[i] = str[n];
        str[n] = temp;
        i++;
        n--;
    }
    return (str);
}