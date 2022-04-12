/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** strings_two
*/

#include "my.h"
#include <stdlib.h>

char *re_malloc(char *str);

int is_string_null(char *str, char delimiter)
{
    char temp[2];
    temp[0] = delimiter;
    temp[1] = '\0';
    if (str == NULL || my_strcmp(str, temp) == 0 || my_strlen(str) == 0) {
        return (0);
    }
    return (1);
}

int get_first_empty_index(char **words)
{
    for (int i = 0; words[i] != NULL; i++) {
        if (words[i] == NULL || my_strcmp(words[i], "") == 0 ||
            my_strlen(words[i]) == 0) {
            return (i);
        }
    }
    return (-1);
}

char **clean_arr_str(char **words)
{
    for (int i = 0; words[i] != NULL; i++) {
        int index = get_first_empty_index(words);
        if (index < i && index != -1) {
            words[index] = words[i];
            words[i] = "";
        }
    }
    return (words);
}

int check_cut_str(char *input, int i, char delimiter)
{
    if (input[i + 1] == '\0' || input[i] == delimiter || input[i] == '\t')
        return (1);
    return (0);
}

char **cut_str(char *input, char delimiter)
{
    char **words = malloc(sizeof(char *) * (my_strlen(input) + 1));
    char *str = malloc(sizeof(char) * (my_strlen(input) + 1));
    int index = 0;
    int count = 0;
    for (int i = 0; input[i]; i++) {
        if (check_cut_str(input, i, delimiter)) {
            input[i] != delimiter && input[i] != '\t' ?
                str[index++] = input[i] : i;
            str[index] = '\0';
            is_string_null(str, delimiter) == 1 ? words[count++] =
                re_malloc(str) : NULL;
            str = malloc(sizeof(char) * (my_strlen(input) + 1));
            index = 0;
            continue;
        }
        str[index++] = input[i];
    }
    words[count] = NULL;
    free(str);
    return (words);
}
