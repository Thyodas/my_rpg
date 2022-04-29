/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** parser
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "region.h"
#include "game.h"
#include "object.h"
#include "my.h"

char **cut_str(char *input, char *delimiter);
void parse_teleporter(game_t *game, region_t *region, char **args);

void (* const PARSE_OBJECT[])(game_t *, region_t *, char **) = {
    &parse_teleporter,
};

static int *new_int_array(int size)
{
    int *array = malloc(sizeof(int) * (NB_MAX_INFO + 1));

    for (int i = 0; i <= NB_MAX_INFO; i++)
        array[i] = 0;
    array[NB_MAX_INFO] = -1;
}

int parse_region(game_t *game, region_t *region)
{
    char *line = NULL;
    char **args = NULL;
    size_t size = 0;
    int object_id = -1;
    FILE *file = fopen(REGION_PATH[region->id], "r");
    if (file == NULL)
        return -1;
    while (getline(&line, &size, file) != -1) {
        line[my_strlen(line) - 1] = line[my_strlen(line) - 1] == '\n' ?
            '\0' : line[my_strlen(line) - 1];
        args = cut_str(line, " ");
        if (args == NULL || args[0] == NULL || !my_str_isnum(args[0]))
            continue;
        object_id = my_getnbr(args[0]);
        if (object_id < 0 || object_id >= OBJECT_NB)
            continue;
        PARSE_OBJECT[object_id](game, region, &args[1]);
    }
}
