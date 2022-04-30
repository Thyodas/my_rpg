/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** animation
*/

#include "rpg.h"

void rect_animation(game_t *game, entity_t entity)
{
    if (entity.spritesheet_rect_x != 0)
        entity.rect.left += entity.spritesheet_rect_x;
    if (entity.rect.left >= entity.spritesheet_width)
        entity.rect.left = 0;
    sfSprite_setTextureRect(entity.sprite, entity.rect);
}
