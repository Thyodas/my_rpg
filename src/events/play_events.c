/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** start_menu
*/

#include "rpg.h"
#include <stdio.h>

bool check_player_region_collision(game_t *game, float shift_x, float shift_y);

void play_animate_sprites(game_t *game)
{
    // Sprite animation every 0.25 seconds
    static long last_clock_us = 0;
    long current_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
    double diff = (current_us - last_clock_us) / 1000000.0;
    if (diff >= 0.5) {
        rect_animation(game, game->play->player);
        last_clock_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
    }
}

static void move_player(game_t *game, int text_pos, float shift_x,
float shift_y)
{
    if (check_player_region_collision(game, shift_x, shift_y))
        return;
    set_text_from_textures(game->play->player, text_pos);
    sfSprite_move(game->play->player->sprite, (sfVector2f){shift_x, shift_y});
    play_animate_sprites(game);
}

void play_keyboard_events_handler(game_t *game)
{
    static long last_clock_us = 0;
    long current_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
    double diff = (current_us - last_clock_us) / 1000000.0;
    double new_speed = game->play->player->speed * diff;
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        move_player(game, 0, -new_speed, 0);
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        move_player(game, 1, 0, -new_speed);
    if (sfKeyboard_isKeyPressed(sfKeyD))
        move_player(game, 2, new_speed, 0);
    if (sfKeyboard_isKeyPressed(sfKeyS))
        move_player(game, 3, 0, new_speed);
    last_clock_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
}

void play_events_handler(game_t *game, sfEvent event)
{
    // Replace cursor by custom cursor (do not remove)
    check_mouse_movement(game, event);
}
