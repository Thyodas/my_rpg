/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** start_menu
*/

#include "rpg.h"
#include <stdio.h>

void play_animate_sprites(game_t *game)
{
    // Sprite animation every 0.25 seconds
    static long last_clock_us = 0;
    long current_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
    double diff = (current_us - last_clock_us) / 1000000.0;
    if (diff >= 0.5) {
        rect_animation(game, ((player_t *)(game, game->play->player->data))->entity);
        last_clock_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
    }
}

void play_keyboard_events_handler(game_t *game)
{
    static long last_clock_us = 0;
    long current_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
    double diff = (current_us - last_clock_us) / 1000000.0;
    double new_speed = ((player_t *)(game, game->play->player->data))->speed
        * diff;

    if (sfKeyboard_isKeyPressed(sfKeyQ))
        move_player(game, game->play->player->data, -new_speed, 0);
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        move_player(game, game->play->player->data, 0, -new_speed);
    if (sfKeyboard_isKeyPressed(sfKeyD))
        move_player(game, game->play->player->data, new_speed, 0);
    if (sfKeyboard_isKeyPressed(sfKeyS))
        move_player(game, game->play->player->data, 0, new_speed);
    last_clock_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
}

void play_events_handler(game_t *game, sfEvent event)
{
    // Replace cursor by custom cursor (do not remove)
    check_mouse_movement(game, event);
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(game->window);
}
