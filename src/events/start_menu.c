/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** start_menu
*/

#include "rpg.h"

void set_game_scene(game_t *game);

void start_menu_animate_sprites(game_t *game)
{
    // Sprite animation every 0.25 seconds
    game->clock->time = sfClock_getElapsedTime(game->clock->clock);
    game->clock->seconds = game->clock->time.microseconds / 1000000.0;
    if (game->clock->seconds >= 0.5) {
        sfClock_restart(game->clock->clock);
    }
}

// void start_menu_events_handler(game_t *game, sfEvent event)
// {
//     // Replace cursor by custom cursor
//     check_mouse_movement(game, event);

//     if (event.type == sfEvtMouseButtonReleased) {
//         if (is_hit(game->start_menu->exit, game->cursor, 34.0, 16.0)) {
//             // TODO free data
//             return;
//         }
//         if (is_hit(game->start_menu->new_game, game->cursor, 60.0, 16.0)) {
//             set_game_scene(game);
//         }
//     }
// }
