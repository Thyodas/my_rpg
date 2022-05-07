/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** my_itoa
*/

#include <stdlib.h>

char *my_itoa(int nb)
{
    int len = 0;
    char *str = "\0";
    int tmp = nb;

    if (nb == 0)
        return ("0");
    for (; tmp != 0; len++)
        tmp /= 10;
    str = malloc(len + 1);
    str[len] = '\0';
    for (; len--; nb /= 10)
        str[len] = nb % 10  + '0';
    return (str);
}
