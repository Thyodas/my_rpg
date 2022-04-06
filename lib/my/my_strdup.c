/*
** EPITECH PROJECT, 2021
** Strudup
** File description:
** my_strdup
*/

#include "my.h"
#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *result = NULL;
    int index = 0;
    int len = my_strlen(src);

    result = malloc(len + 1);
    while (src[index] != '\0') {
        result[index] = src[index];
        index++;
    }
    return (result);
}
