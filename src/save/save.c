/*
** EPITECH PROJECT, 2022
** B-PSU-200-STG-2-1-tetris-remi.mergen
** File description:
** saving_inventory
*/

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include "game.h"

unsigned my_atoi( char *str );

ssize_t get_score(void)
{
    int fd = open("save.rpg", O_RDONLY);
    char *tmp = NULL;
    size_t size = 0;
    ssize_t nbr = 0;

    if (fd == -1)
        return (0);
    close(fd);
    while (getline(&tmp, &size, fopen("save.rpg", "r")))
    ;
    if (!tmp)
        return (0);
    nbr = my_atoi(tmp);
    free(tmp);
    return nbr;
}

void save_score(game_t *game)
{
    FILE *f_file = fopen("save.rpg", "w");
    char *str = NULL;

    if (!f_file)
        return;
    for (int i = 0; game->inventory[i]; i++) {
        fwrite(str, sizeof(char), my_strlen(str), f_file);
        fwrite("\n", sizeof(char), 1, f_file);
    }
    if (!str) {
        fclose(f_file);
        return;
    }
    fclose(f_file);
    free(str);
}
