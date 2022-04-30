/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** animation
*/

#include <stdio.h>
#include "rpg.h"

void rect_animation_vertical(game_t *game, entity_t *entity)
{
    if (entity->spritesheet_rect_y != 0)
        entity->rect.top += entity->spritesheet_rect_y;
    if (entity->rect.top >= entity->spritesheet_height)
        entity->rect.top = 0;
    sfSprite_setTextureRect(entity->sprite, entity->rect);
}

void rect_animation_horizontal(game_t *game, entity_t *entity)
{
    if (entity->spritesheet_rect_x != 0)
        entity->rect.left += entity->spritesheet_rect_x;
    if (entity->rect.left >= entity->spritesheet_width)
        entity->rect.left = 0;
    sfSprite_setTextureRect(entity->sprite, entity->rect);
}
