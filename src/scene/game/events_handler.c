/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** events_handler.c
*/

#include "rpg.h"

void set_pause_scene(game_t *game);

void game_events_handler(game_t *game)
{
    check_mouse_movement(game);
    if (game->event.type == sfEvtClosed)
        sfRenderWindow_close(game->window);
    if (game->event.type == sfEvtKeyReleased &&
        game->event.key.code == sfKeyEscape)
        set_pause_scene(game);
}