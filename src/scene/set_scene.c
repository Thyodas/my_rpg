/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** set_scene
*/

#include "game.h"
#include "region.h"

void init_game(game_t *game);
void init_scene_objects(game_t *game);

void set_game_scene(game_t *game)
{
    game->previous_scene = game->current_scene;
    game->current_scene = GAME_SCENE;
    if (game->play->view == NULL)
        game->play->view = sfView_createFromRect((sfFloatRect){REGION_SIZE_X
            * game->play->current_region_pos.x, REGION_SIZE_Y
            * game->play->current_region_pos.y, REGION_SIZE_X, REGION_SIZE_Y});
    if (game->previous_scene == START_SCENE) {
        game->play->intro_animation.zooming = true;
        game->play->intro_animation.zoom_factor = 0.3;
        game->play->intro_animation.start_view = game->play->view;
        game->play->intro_animation.previous_copy = NULL;
    } else {
        game->play->intro_animation.zooming = false;
        sfRenderWindow_setView(game->window, game->play->view);
    }
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

void set_inventory_scene(game_t *game)
{
    game->previous_scene = game->current_scene;
    if (game->previous_scene == GAME_SCENE) {
        sfTexture *texture = sfTexture_create(1920, 1080);
        sfTexture_updateFromRenderWindow(texture, game->window, 0, 0);
        game->scene[INVENTORY_SCENE]->texture_background_saved = texture;
    }
    game->current_scene = INVENTORY_SCENE;
    sfRenderWindow_setView(game->window,
        sfRenderWindow_getDefaultView(game->window));
}

void set_help_scene(game_t *game)
{
    game->previous_scene = game->current_scene;
    game->current_scene = HELP_SCENE;
    sfRenderWindow_setView(game->window,
        sfRenderWindow_getDefaultView(game->window));
}
