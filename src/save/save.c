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
        if (my_arr_size(item_data) < 4) {
            free(item_data);
            continue;
        }
        item_t *item = create_items_object(get_option_by_name(item_data[1]), 0);
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
    FILE *f_file = fopen("data/save.rpg", "w");
    char *str = malloc(sizeof(char) * 100);
    str[0] = '\0';
    if (!f_file) {
        free(str);
        return;
    }
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        item_t *item = ((item_t *)(inventory.items[i]->data));
        if (item == NULL)
            continue;
        str = my_strcat(my_strcat(str, my_int_to_strnum(i)), "#");
        str = my_strcat(my_strcat(str, item->name), "#");
        str = my_strcat(my_strcat(str, my_int_to_strnum(item->nb_usage)), "#");
        str = my_strcat(my_strcat(str,
            my_int_to_strnum(item->unlocked)), "\n");
        fwrite(str, sizeof(char), my_strlen(str), f_file);
    }
    fclose(f_file);
}
