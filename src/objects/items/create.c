/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_player
*/

#include "rpg.h"
#include "object.h"

item_t *create_items_object(option_t option, int unlocked)
{
    item_t *item = malloc(sizeof(item_t));

    item->entity = init_entity(option);
    item->name = option.name ? option.name : NULL;
    item->nb_usage = 0;
    item->unlocked = unlocked;
    return item;
}
