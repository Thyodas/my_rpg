/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** extend_str
*/

#include <stdlib.h>

char *extend_string(char *first, char *second)
{
    int len_first = my_strlen(first);
    int len_second = my_strlen(second);
    char *new = malloc(sizeof(char) * len_first + len_second + 1);
    int pos = 0;

    for (; *first; ++first) {
        new[pos++] = *first;
    }
    for (; *second; ++second) {
        new[pos++] = *second;
    }
    new[pos] = '\0';
    return new;
}
