/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** enemy_handler
*/

#include "game.h"
#include "object.h"
#include <stdio.h>

void rect_animation_enemy_breathing(game_t *game, entity_t *entity,
enemy_t *enemy)
{
    long current_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
    static int multiplier = 1;

    sfVector2f scale = sfSprite_getScale(entity->sprite);

    if ((current_us - enemy->last_breathing_animation) / 1000000.0 >= 0.3) {
        scale.x += 0.03 * enemy->breath_state;
        scale.y += 0.01 * enemy->breath_state;
        sfSprite_setScale(entity->sprite, scale);
        enemy->last_breathing_animation =
            sfClock_getElapsedTime(game->clock->clock).microseconds;
    }
    if ((current_us - enemy->last_breath_out_animation) / 1000000.0 >= 1) {
        enemy->breath_state = enemy->breath_state == 1 ? -1 : 1;
        enemy->last_breath_out_animation =
            sfClock_getElapsedTime(game->clock->clock).microseconds;
    }
}

void enemy_handler(game_t *game, object_t *self)
{
    enemy_t *enemy = (enemy_t *)self->data;
    sfTime elapse = sfClock_getElapsedTime(game->clock->clock);
    game->clock->seconds = elapse.microseconds / 1000000.0;
    rect_animation_enemy_breathing(game, &enemy->entity, self->data);
    
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
