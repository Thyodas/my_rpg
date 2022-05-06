/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** enemy_handler
*/

#include "game.h"
#include "object.h"
#include <stdio.h>

void move_skeleton(game_t *game, enemy_t *enemy);
void move_slime(game_t *game, enemy_t *slime);
void move_blob(game_t *game, enemy_t *blob);
void move_ghost(game_t *game, enemy_t *ghost);

static void (*move[4])(game_t *, enemy_t *) = {
    &move_blob,
    &move_slime,
    &move_skeleton
};

static void animation_enemy_breathing(game_t *game, enemy_t *enemy)
{
    long current_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
    static int multiplier = 1;
    sfVector2f scale = sfSprite_getScale(enemy->entity.sprite);
    animation_data_t data = enemy->animation_data;

    if ((current_us - data.last_breathing_animation) / 1000000.0 >= 0.3) {
        scale.x += 0.03 * data.breath_state;
        scale.y += 0.01 * data.breath_state;
        sfSprite_setScale(enemy->entity.sprite, scale);
        data.last_breathing_animation =
            sfClock_getElapsedTime(game->clock->clock).microseconds;
    }
    if ((current_us - data.last_breath_out_animation) / 1000000.0 >= 1) {
        data.breath_state = data.breath_state == 1 ? -1 : 1;
        data.last_breath_out_animation =
            sfClock_getElapsedTime(game->clock->clock).microseconds;
    }
    enemy->animation_data = data;
}

void enemy_handler(game_t *game, object_t *self)
{
    enemy_t *enemy = (enemy_t *)self->data;
    animation_enemy_breathing(game, enemy);
    move[enemy->id](game, enemy);
}
