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
option_t get_option_by_name(char *name);

void get_save(game_t *game)
{
    FILE* input_file = fopen("data/save.rpg", "r");
    if (!input_file)
        return;
    char *content = NULL;
    size_t size = 0;
    while (getline(&content, &size, input_file) != -1) {
        char **item_data = cut_str(content, "#");
        if (item_data == NULL || my_arr_size(item_data) < 5) {
            free(item_data);
            continue;
        }
        item_t *item = create_items_object(get_option_by_name(item_data[1]), 0,
            my_getnbr(item_data[0]));
        item->name = item_data[1];
        item->nb_usage = my_getnbr(item_data[2]);
        item->unlocked = my_getnbr(item_data[3]);
        set_inventory_data(game, item, my_getnbr(item_data[0]));
    }
    if (!content)
        return;
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
        item_t *item = ((item_t *)(inventory.items[i]->data));
        if (item == NULL)
            continue;
        my_fprintf(fd, "%d#%d#%s#%d#%d\n", i, item->id, item->name,
            item->nb_usage, item->unlocked);
    }
    close(fd);
}
