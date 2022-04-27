/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** loop_region
*/

#include "region.h"
#include "game.h"

void draw_region(game_t *game, region_t *region)
{
    sfRenderWindow_drawSprite(game->window, region->background, NULL);
}