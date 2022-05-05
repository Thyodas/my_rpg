/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** enemy_handler
*/

#include "game.h"
#include "object.h"
#include <stdio.h>

void rect_animation_movement_enemy(game_t *game, entity_t *entity, direction_e dir)
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
    sfVector2f scale = sfSprite_getScale(entity->sprite);

    if ((int)game->clock->seconds % 2 == 0) {
        scale.x += 0.0004;
        scale.y += 0.0002;
        sfSprite_setScale(entity->sprite, scale);
    } else {
        scale.x -= 0.0004;
        scale.y -= 0.0002;
        sfSprite_setScale(entity->sprite, scale);
    }
}

void enemy_handler(game_t *game, object_t *self)
{
    enemy_t *enemy = (enemy_t *)self->data;
    sfTime elapse = sfClock_getElapsedTime(game->clock->clock);
    game->clock->seconds = elapse.microseconds / 1000000.0;
    rect_animation_idle_enemy(game, &enemy->entity);
    //TODO move_enemy
    /* if (enemy_move != IDLE) {
        if (enemy_move == RIGHT) {
            rect_animation_movement_enemy(game, &enemy->entity, RIGHT);
        } else
            rect_animation_movement_enemy(game, &enemy->entity, LEFT);
    } else
        rect_animation_idle_enemy(game, &enemy->entity);
    */
}
