/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** start_menu
*/

#include "rpg.h"

void check_mouse_movement(game_t *game, sfEvent event);

void start_menu_events_handler(game_t *game, sfEvent event)
{
    check_mouse_movement(game, event);
}
