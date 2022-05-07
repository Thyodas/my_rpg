/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_player
*/

#include "rpg.h"
#include "object.h"

void sword_hit_effect(game_t *game, item_t *sword);

static void (*ptr_hit_effect[]) = {
    &sword_hit_effect
};

item_t *create_items_object(option_t option, int unlocked, int id)
{
    item_t *item = malloc(sizeof(item_t));

    item->entity = init_entity(option);
    item->name = option.name ? option.name : NULL;
    item->nb_usage = 0;
    item->unlocked = unlocked;
    item->hit_effect = 0;
    item->sprite_effect = sfSprite_create();
    item->id = id;
    item->handle_hit = ptr_hit_effect[id];
    return item;
}
