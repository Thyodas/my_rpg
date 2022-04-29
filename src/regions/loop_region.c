/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** loop_region
*/

#include "region.h"
#include "game.h"

void draw_entity(game_t *game, entity_t *entity);

void draw_region(game_t *game, region_t *region)
{
    sfRenderWindow_drawSprite(game->window, region->map->background, NULL);
    draw_entity(game, game->play->player);
    sfRenderWindow_drawSprite(game->window, region->map->foreground, NULL);
}