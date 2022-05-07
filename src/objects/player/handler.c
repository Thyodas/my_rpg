/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** player_handler
*/

#include "rpg.h"
#include <stdio.h>

void player_idle_animation(game_t *game);
void move_player(game_t *game, player_t *player, float shift_x, float shift_y);
void interact_player(game_t *game);
void rect_set_y(game_t *game, int status);

void handle_movement(game_t *game, player_t *player, float new_speed)
{
    CAST_PLAYER(game->play->player->data)->entity.animation_state
        = IDLE_STATE;
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        rect_set_y(game, 1);
        move_player(game, game->play->player->data, -new_speed, 0);
    }
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        rect_set_y(game, 3);
        move_player(game, game->play->player->data, 0, -new_speed);
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        rect_set_y(game, 0);
        move_player(game, game->play->player->data, new_speed, 0);
    }
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        rect_set_y(game, 2);
        move_player(game, game->play->player->data, 0, new_speed);
    }
}

void handle_interaction(game_t *game, player_t *player)
{
    if (sfKeyboard_isKeyPressed(sfKeyE))
        interact_player(game);
}

void handle_combat(game_t *game, player_t *player)
{
    static long invincibility = 0;
    long current_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
    double diff = (current_us - invincibility) / 1000000.0;
    if (player->is_hit) {
        if (diff >= 0.5) {
            player->is_hit = 0;
            sfSprite_setColor(player->entity.sprite, sfWhite);
            invincibility = 0;
        } else {
            sfColor color_hit = {250, 100, 100, 255};
            sfSprite_setColor(player->entity.sprite, color_hit);
        }
    } else
        invincibility = current_us;
}

void handler_player(game_t *game)
{
    static long last_clock_us = 0;
    long current_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
    double diff = (current_us - last_clock_us) / 1000000.0;
    player_t *player = ((player_t *)(game->play->player->data));
    double new_speed = ((player_t *)(game->play->player->data))->speed
        * diff;
    handle_movement(game, player, new_speed);
    handle_interaction(game, player);
    handle_combat(game, player);
    if (CAST_PLAYER(game->play->player->data)->entity.animation_state
        == IDLE_STATE)
        player_idle_animation(game);
    last_clock_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
}
