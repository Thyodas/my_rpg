/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** strings
*/

#include "my.h"
#include <stdlib.h>

static int count_substring_two(int sub_len, int i, char *str, char *substring)
{
    int j = 0;

    for (; j < sub_len; j++)
        if (str[i + j] != substring[j])
            break;
    return (j);
}

int count_substring(char *str, char *substring)
{
    int sub_len = my_strlen(substring);
    int str_len = my_strlen(str);
    int count = 0;
    int j = 0;

    for (int i = 0; i <= str_len - sub_len; i++) {
        j = count_substring_two(sub_len, i, str, substring);
        if (j == sub_len)
            count++;
    }
    return (count);
}

int scrape_nbr(char *str)
{
    int index = 0;
    char *result = malloc(sizeof(char) * my_strlen(str));

    if (result == NULL) {
        my_put_err("Out of memory\n");
        return (84);
    }

    for (int i = 0; str[i]; i++)
        if (str[i] >= '0' && str[i] <= '9')
            result[index++] = str[i];
    result[index] = '\0';

    int final = my_getnbr(result);
    free(result);
    return (final);
}

int get_max_len(char **map)
{
    int max = 0;

    for (int i = 0; map[i]; i++)
        if (my_strlen(map[i]) > max)
            max = my_strlen(map[i]);

    return (max);
}
