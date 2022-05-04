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
    game->previous_scene = game->current_scene;
    game->current_scene = GAME_SCENE;
    if (game->play->view == NULL)
        game->play->view = sfView_createFromRect((sfFloatRect){REGION_SIZE_X
            * game->play->current_region_pos.x, REGION_SIZE_Y
            * game->play->current_region_pos.y, REGION_SIZE_X, REGION_SIZE_Y});
    sfRenderWindow_setView(game->window, game->play->view);
}

void set_menu_scene(game_t *game)
{
    game->previous_scene = game->current_scene;
    game->current_scene = START_SCENE;
    sfRenderWindow_setView(game->window,
        sfRenderWindow_getDefaultView(game->window));
}

void set_settings_scene(game_t *game)
{
    game->previous_scene = game->current_scene;
    game->current_scene = SETTINGS_SCENE;
    sfRenderWindow_setView(game->window,
        sfRenderWindow_getDefaultView(game->window));
}

void set_pause_scene(game_t *game)
{
    game->previous_scene = game->current_scene;
    if (game->previous_scene == GAME_SCENE) {
        sfTexture *texture = sfTexture_create(1920, 1080);
        sfTexture_updateFromRenderWindow(texture, game->window, 0, 0);
        game->scene[PAUSE_SCENE]->texture_background_saved = texture;
    }
    game->current_scene = PAUSE_SCENE;
    sfRenderWindow_setView(game->window,
        sfRenderWindow_getDefaultView(game->window));
}