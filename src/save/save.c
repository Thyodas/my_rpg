/*
** EPITECH PROJECT, 2022
** B-PSU-200-STG-2-1-tetris-remi.mergen
** File description:
** saving_inventory
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "rpg.h"
#include "game.h"
#include "object.h"
#include "my.h"

char **cut_str(char *str, char *delim);
option_t get_option_by_id(int id);
void add_item_on_id(game_t *game, object_t *item, int pos);
item_t *create_items(option_t option, int id, sfVector2f pos,
                    int on_the_ground);
void handle_item(game_t *game, object_t *self);
void draw_item(game_t *game, object_t *self);
object_t *create_object(enum id_object_type id, void *data, void (*handler)(),
void (*draw)());

static item_t *init_saved_item(char **item_data)
{
    int pos_inv = my_getnbr(item_data[0]);
    if (pos_inv < 0 || pos_inv >= INVENTORY_SIZE)
        return NULL;
    int id = my_getnbr(item_data[1]);
    if (id < 0 || id >= NB_ITEMS)
        return NULL;
    sfVector2f pos = {my_getnbr(item_data[5]), my_getnbr(item_data[6])};
    int on_the_ground = my_getnbr(item_data[4]);
    item_t *item = create_items(get_option_by_id(id), id, pos, on_the_ground);
    item->name = item_data[2];
    item->unlocked = my_getnbr(item_data[3]);
    return item;
}

void get_save(game_t *game)
{
    FILE* input_file = fopen("data/save.rpg", "r");
    if (!input_file)
        return;
    char *content = NULL;
    size_t size = 0;
    while (getline(&content, &size, input_file) != -1) {
        char **item_data = cut_str(content, "#");
        if (item_data == NULL || my_arr_size(item_data) < 6) {
            free(item_data);
            continue;
        }
        item_t *item_saved = init_saved_item(item_data);
        object_t *obj = create_object(ITEMS_OBJ, item_saved, &handle_item, 
        &draw_item);
        printf("On passe tout\n");
        add_item_on_id(game, obj, my_getnbr(item_data[0]));
    }
    if (content)
        free(content);
}

void save_score(game_t *game)
{
    inventory_t inventory = CAST_PLAYER(game->play->player->data)->inventory;

    int fd = open("data/save.rpg", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU
        | S_IRWXG | S_IRWXO);
    if (fd == -1)
        return;
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        object_t *obj = inventory.items[i];
        if (obj == NULL)
            continue;
        item_t *item = obj->data;
        my_fprintf(fd, "%d#%d#%s#%d#%d#%d#%d\n", i, item->id, item->name,
                item->unlocked, item->on_the_ground, (int)item->pos.x, (int)item->pos.y);
    }
    close(fd);
}
