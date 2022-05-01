/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** set_scene
*/

#include "game.h"
#include "region.h"

void set_game_scene(game_t *game)
{
    game->current_scene = 1;
    if (game->play->view == NULL)
        game->play->view = sfView_createFromRect((sfFloatRect){REGION_SIZE_X
            * game->play->current_region_pos.x, REGION_SIZE_Y
            * game->play->current_region_pos.y, REGION_SIZE_X, REGION_SIZE_Y});
    sfRenderWindow_setView(game->window, game->play->view);
}

void set_menu_scene(game_t *game)
{
    game->current_scene = 0;
    sfRenderWindow_setView(game->window,
        sfRenderWindow_getDefaultView(game->window));
}

void set_settings_scene(game_t *game)
{
    game->current_scene = 2;
    sfRenderWindow_setView(game->window,
        sfRenderWindow_getDefaultView(game->window));
}