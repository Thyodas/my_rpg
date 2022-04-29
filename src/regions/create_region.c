/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** create_region
*/

#include "game.h"
#include "region.h"
#include "my.h"

int parse_region(game_t *game, region_t *region);

region_t *create_region(game_t *game, int id)
{
    region_t *region = malloc(sizeof(region_t));
    region->id = id;
    region->is_loaded = false;
    region->top = NULL;
    region->right = NULL;
    region->left = NULL;
    region->bottom = NULL;
    region->map = game->play->map_list[REGION_MAP_JMP_TABLE[id]];
    return (region);
}

void load_region(game_t *game, region_t *region)
{
    if (region->is_loaded)
        return;
    parse_region(game, region);
    load_map(region->map);
    region->is_loaded = true;
}

void link_regions(game_t *game)
{
    game->play->region_list[START_REGION]->top = game->play->region_list[MINE_REGION];
    game->play->region_list[MINE_REGION]->bottom = game->play->region_list[START_REGION];
}

void init_all_regions(game_t *game)
{
    for (int id = 0; id < REGION_NB; ++id)
        game->play->region_list[id] = create_region(game, id);
    load_region(game, game->play->region_list[START_REGION]);
    game->play->current_region = game->play->region_list[START_REGION];
    game->play->current_region_pos = (sfVector2i){0, 1};
    link_regions(game);
}
