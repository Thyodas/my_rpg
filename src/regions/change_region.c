/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** change_region
*/

#include "game.h"
#include "region.h"

void load_region(game_t *game, region_t *region);

void change_region(game_t *game, region_t *new_region, int dir_x, int dir_y)
{
    game->play->current_region = new_region;
    game->play->current_region_pos.x += dir_x;
    game->play->current_region_pos.y += dir_y;
    load_region(game, new_region);
    sfView_move(game->play->view, (sfVector2f){dir_x * REGION_SIZE_X,
        dir_y * REGION_SIZE_Y});
    sfRenderWindow_setView(game->window, game->play->view);
}
