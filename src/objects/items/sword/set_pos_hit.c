/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** set_pos_hit.c
*/

#include "rpg.h"

item_t *get_selected_item(player_t *player);

void set_pos_hit(player_t *player, sfVector2f pos)
{
    item_t *item = get_selected_item(player);
    pos.x -= 5;
    pos.y -= 5;
    sfSprite_setPosition(item->sprite_effect, pos);
}
