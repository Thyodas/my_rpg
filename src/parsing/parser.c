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
#include "my.h"

static int *new_int_array(int size)
{
    int *array = malloc(sizeof(int) * (NB_MAX_INFO + 1));

    for (int i = 0; i < 5; i++)
        array[i] = 0;
    array[4] = -1;
}

static void add_enemy(region_t *region, char *line)
{
    l_enemy_t *new_enemy = malloc(sizeof(l_enemy_t));
    new_enemy->data = new_int_array(5);
    return;
}

static void add_object(region_t *region, char *line)
{
    object_t *object = malloc(sizeof(object_t));

    object->id = line[0];
    object->x1 = line[1];
    object->y1 = line[2];
}

static void set_region_pos(region_t *region, char *line)
{
    region->x = my_getnbr(&line[0]);
    region->y = my_getnbr(&line[2]);
}

int read_data(char *region_path)
{
    void (*init_region[3])(region_t *, char *) = {
        set_region_pos, add_enemy, add_object
    };
    region_t *region = malloc(sizeof(region_t));
    char *line = NULL;
    size_t size = 0;
    size_t tmp = -1;

    while (getline(&line, &size, (FILE *)region_path) != -1) {
        tmp = my_getnbr(line);
        if (tmp == -1)
            return -1;
        init_region[tmp](region, cut_str(&line[2], ' '));
    }
}
