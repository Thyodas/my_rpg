/*
** EPITECH PROJECT, 2022
** MY_STRCAT
** File description:
** Concatenates two strings.
*/

#include <stdlib.h>

char *my_strcat(char *src1, char *src2)
{
    if (src1 == NULL)
        return src2;
    if (src2 == NULL)
        return src1;
    int src1_len = my_strlen(src1);
    int src2_len = my_strlen(src2);
    char *dest = malloc(sizeof(char) * (src1_len + src2_len + 1));

    for (int i = 0; i < src1_len + src2_len; ++i) {
        if (i < src1_len)
            dest[i] = src1[i];
        else
            dest[i] = src2[i - src1_len];
    }
    dest[src1_len + src2_len] = '\0';
    return (dest);
}
