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

    for (int i = 0; i <= NB_MAX_INFO; i++)
        array[i] = 0;
    array[NB_MAX_INFO] = -1;
}

static void add_enemy(regions_t *region, char *line)
{
    linked_list_t *entity = malloc(sizeof(linked_list_t));
    object_t *new_enemy = malloc(sizeof(object_t));

    new_enemy->id = line[0] >= '0' && line[0] <= '9'? line[0] - '0': NULL;
    new_enemy->x1 = my_getnbr(line[1]);
    new_enemy->y1 = my_getnbr(line[2]);
    new_enemy->x2 = my_getnbr(line[3]);
    new_enemy->y2 = my_getnbr(line[4]);
    entity->next = region->entities;
    entity->data = new_enemy;
    region->entities = entity;
    return;
}

static void add_object(regions_t *region, char *line)
{
    linked_list_t *entity = malloc(sizeof(linked_list_t));
    object_t *object = malloc(sizeof(object_t));

    object->id = my_getnbr(line[0]);
    object->x1 = my_getnbr(line[1]);
    object->y1 = my_getnbr(line[2]);
    entity->next = region->entities;
    entity->data = object;
    region->entities = entity;
}

static void set_region_id(regions_t *region, char *line)
{
    return;
}

int read_data(char *region_path)
{
    void (*init_region[3])(regions_t *, char *) = {
        set_region_id, add_enemy, add_object
    };
    regions_t *region = malloc(sizeof(regions_t));
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
