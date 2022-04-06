/*
** EPITECH PROJECT, 2021
** my_grep
** File description:
** my_grep
*/

#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include "my.h"

int get_size(char *path)
{
    struct stat stats;
    int code = stat(path, &stats);

    if (code == 0 && !S_ISDIR(stats.st_mode))
        return (stats.st_size);
    else
        return (-1);
}

int my_arr_size(char **str)
{
    int i = 0;

    for (; str[i] != 0; i++);
    return (i);
}

char *my_cat_two(char *input, int argc)
{
    int fd;
    long ret;
    off_t size = 1; // get_size(input);
    char *buf = malloc(sizeof(char) * (size + 1));
    if (size == -1)
        return ("84");
    if (argc <= 1) {
        fd = 0;
    } else {
        fd = open(input, O_RDONLY);
        if (fd == -1)
            return ("84");
    }
    do {
        ret = read(fd, buf, size);
    } while (ret != 0 && ret != -1);
    if (close(fd) == -1)
        return ("84");
    buf[size] = '\0';
    return (buf);
}

char *my_reader(char *av)
{
    char *result = my_cat_two(av, 2);

    if (my_strcmp(result, "84") == 0)
        return ("84");
    return (result);
}
