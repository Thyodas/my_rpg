/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** enemy_handler
*/

#include "game.h"
#include "object.h"
#include <stdio.h>

void rect_animation_movement_enemy(game_t *game, entity_t *entity,
direction_e dir)
{
    if (entity->spritesheet_rect_x == 0) {
        sfSprite_setTextureRect(entity->sprite, entity->rect);
        return;
    }
    if (entity->rect.top != entity->spritesheet_rect_y * dir)
        entity->rect.top = entity->spritesheet_rect_y * dir;
    entity->rect.left += entity->spritesheet_rect_x;
    if (entity->rect.left >= entity->spritesheet_width)
        entity->rect.left = 0;
    sfSprite_setTextureRect(entity->sprite, entity->rect);
}

void rect_animation_idle_enemy(game_t *game, entity_t *entity)
{
    if ((int)game->clock->seconds % 1 == 0) {
        sfVector2f scale = sfSprite_getScale(entity->sprite);
        scale.x += ((int)game->clock->seconds % 2) / 100;
        scale.y += ((int)game->clock->seconds % 2) / 100;
        sfSprite_setScale(entity->sprite, scale);
    }
}
