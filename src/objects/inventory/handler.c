/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** handler
*/

#include "rpg.h"
#include <stdio.h>

void set_inventory_data(game_t *game, void *data, int n)
{
    game->play->inventory[n]->data = data;
}

void *get_inventory_data(game_t *game, int n)
{
    return game->play->inventory[n]->data;
}
