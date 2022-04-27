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
    game->clock->time = sfClock_getElapsedTime(game->clock->clock);
    game->clock->seconds = game->clock->time.microseconds / 1000000.0;
    if (game->clock->seconds >= 0.5) {
        rect_animation(game, game->play->player);
        sfClock_restart(game->clock->clock);
    }
}

static void move_player(game_t *game, int text_pos, float shift_x, float shift_y)
{
    set_text_from_textures(game->play->player, text_pos);
    sfSprite_move(game->play->player->sprite, (sfVector2f){shift_x, shift_y});
    play_animate_sprites(game);
}

static void play_keyboard_events_handler(game_t *game, sfEvent event)
{
    sfVector2f pos = sfSprite_getPosition(game->play->player->sprite);

    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        move_player(game, 0, -10, 0);
    }
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        move_player(game, 1, 0, -10);
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        move_player(game, 2, 10, 0);
    }
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        move_player(game, 3, 0, 10);
    }
}

void play_events_handler(game_t *game, sfEvent event)
{
    // Replace cursor by custom cursor (do not remove)
    check_mouse_movement(game, event);

    if (event.type == sfEvtKeyPressed)
        play_keyboard_events_handler(game, event);
}
