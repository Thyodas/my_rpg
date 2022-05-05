/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** display.c
*/

#include "rpg.h"
#include "stdio.h"

void handle_region(game_t *game);
void draw_region(game_t *game, region_t *region);
void game_events_handler(game_t *game);

void game(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event))
        game_events_handler(game);
    if (game->current_scene != GAME_SCENE)
        return;
    sfRenderWindow_clear(game->window, sfBlack);
    handle_region(game);
    draw_region(game, game->play->current_region);
    sfRenderWindow_display(game->window);
}