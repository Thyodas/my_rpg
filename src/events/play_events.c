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

static void play_keyboard_events_handler(game_t *game, sfEvent event)
{
    sfVector2f pos = sfSprite_getPosition(game->play->player->sprite);

    if (event.key.code == sfKeyLeft) {
        set_text_from_textures(game->play->player, 0);
        sfSprite_setPosition(game->play->player->sprite, move_coords(pos, -10.0, 0.0));
    } else if (event.key.code == sfKeyUp) {
        set_text_from_textures(game->play->player, 1);
        sfSprite_setPosition(game->play->player->sprite, move_coords(pos, 0.0, -10.0));
    } else if (event.key.code == sfKeyRight) {
        set_text_from_textures(game->play->player, 2);
        sfSprite_setPosition(game->play->player->sprite, move_coords(pos, 10.0, 0.0));
    } else if (event.key.code == sfKeyDown) {
        set_text_from_textures(game->play->player, 3);
        sfSprite_setPosition(game->play->player->sprite, move_coords(pos, 0.0, 10.0));
    } else
        return;
    play_animate_sprites(game);
}

void play_events_handler(game_t *game, sfEvent event)
{
    // Replace cursor by custom cursor (do not remove)
    check_mouse_movement(game, event);

    if (event.type == sfEvtKeyPressed)
        play_keyboard_events_handler(game, event);
}
