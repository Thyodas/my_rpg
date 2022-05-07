/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** getter_selected_item.c
*/

#include "rpg.h"

item_t *get_selected_item(player_t *player)
{
    inventory_t *inventory = &player->inventory;
    item_t *item = (item_t *)inventory->items[inventory->selected_item]->data;
    return item;
}