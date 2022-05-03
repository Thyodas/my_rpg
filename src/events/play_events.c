/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** start_menu
*/

#include "rpg.h"
#include <stdio.h>

void rect_set_y(entity_t *entity, int status);
void rect_animation_movement(entity_t *entity);
void rect_animation_idle(entity_t *entity);
void interact_player(game_t *game);

void player_idle_animation(game_t *game)
{
    static long last_clock_us = 0;
    long current_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
    double diff = (current_us - last_clock_us) / 1000000.0;

    CAST_PLAYER(game->play->player->data)->entity.animation_state
        = IDLE_STATE;
    if (diff >= 0.5) {
        rect_animation_idle(&(CAST_PLAYER(game->play->player->data)->entity));
        last_clock_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
    }
}

void player_movement_animation(game_t *game)
{
    static long last_clock_us = 0;
    long current_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
    double diff = (current_us - last_clock_us) / 1000000.0;

    CAST_PLAYER(game->play->player->data)->entity.animation_state
        = MOVEMENT_STATE;
    if (diff >= 0.2) {
        rect_animation_movement(&((player_t *)(game->play->player->data))->entity);
        last_clock_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
    }
}

void play_keyboard_events_handler(game_t *game)
{
    static long last_clock_us = 0;
    long current_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
    double diff = (current_us - last_clock_us) / 1000000.0;
    player_t *player = ((player_t *)(game->play->player->data));
    double new_speed = ((player_t *)(game->play->player->data))->speed
        * diff;

    CAST_PLAYER(game->play->player->data)->entity.animation_state
        = IDLE_STATE;
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        move_player(game, game->play->player->data, -new_speed, 0);
        rect_set_y(&player->entity, 1);
    }
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        rect_set_y(&player->entity, 3);
        move_player(game, game->play->player->data, 0, -new_speed);
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        rect_set_y(&player->entity, 0);
        move_player(game, game->play->player->data, new_speed, 0);
    }
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        rect_set_y(&player->entity, 2);
        move_player(game, game->play->player->data, 0, new_speed);
    }
    if (sfKeyboard_isKeyPressed(sfKeyE))
        interact_player(game);
    if (CAST_PLAYER(game->play->player->data)->entity.animation_state
        == IDLE_STATE)
        player_idle_animation(game);
    last_clock_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
}

void play_events_handler(game_t *game, sfEvent event)
{
    // Replace cursor by custom cursor (do not remove)
    check_mouse_movement(game, event);
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(game->window);
}
