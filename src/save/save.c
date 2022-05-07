/*
** EPITECH PROJECT, 2022
** B-PSU-200-STG-2-1-tetris-remi.mergen
** File description:
** saving_inventory
*/

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "game.h"
#include "object.h"

char *my_strcat(char *src1, char *src2);
char **cut_str(char *str, char *delim);
int my_strlen(char const * str);
unsigned my_atoi( char *str );
char *my_itoa(int nb);

ssize_t get_score(void)
{
    int fd = open("save.rpg", O_RDONLY);
    inventory_t inventory;
    char *tmp = "\0";
    char **item_data = NULL;
    size_t size = 0;
    ssize_t nbr = 0;

    inventory.nb_items = 0;
    inventory.selected_item = 0;
    if (fd == -1)
        return (0);
    close(fd);
    while (getline(&tmp, &size, fopen("save.rpg", "r"))) {
        //TODO parser;
        item_data = cut_str(tmp, '#');
        item_t item;
        item.name = item_data[0];
        item.nb_usage = item_data[1];
        item.unlocked = item_data[2];
        inventory.items[1] = item;
    }
    if (!tmp)
        return (0);
    nbr = my_atoi(tmp);
    free(tmp);
    return nbr;
}

void save_score(game_t *game)
{
    inventory_t inventory = CAST_PLAYER(game->play->player->data)->inventory;
    FILE *f_file = fopen("save.rpg", "w");
    char *str = "\0";

    if (!f_file)
        return;
    for (int i = 0; i < 1; i++) {
        item_t *item = ((item_t *)(inventory.items[i]->data));
        str = my_strcat(str, item->name);
        str = my_strcat(str, "#");
        str = my_strcat(str, my_itoa(item->nb_usage));
        str = my_strcat(str, "#");
        str = my_strcat(str, my_itoa(item->unlocked));
        str = my_strcat(str, "\n");
        fwrite(str, sizeof(char), my_strlen(str), f_file);
    }
    fclose(f_file);
    free(str);
}
