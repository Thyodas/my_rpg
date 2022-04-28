/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** create_region
*/

#include "game.h"
#include "region.h"
#include "my.h"

region_t *create_region(int id)
{
    region_t *region = malloc(sizeof(region_t));
    region->id = id;
    region->is_loaded = false;
    region->top = NULL;
    region->right = NULL;
    region->left = NULL;
    region->bottom = NULL;
    return (region);
}

sfImage *get_collision_image(char *path)
{
    sfImage *full_image = sfImage_createFromFile(path);
    sfUint8 *pointer = (sfUint8 *)sfImage_getPixelsPtr(full_image);
    sfImage *result = sfImage_create(480, 272);
    sfImage_copyImage(result, full_image, 0, 0, (sfIntRect){0, 544, 480, 272},
        sfFalse);
    free(full_image);
    return (result);
}

void load_region(region_t *region)
{
    // region parsing
    region->is_loaded = true;
}

void init_map(game_t *game)
{
    game->play->background = sfSprite_create();
    game->play->foreground = sfSprite_create();
    game->play->collision = sfImage_createFromFile(
        "assets/images/regions/collision.png");
    SET_SPRITE_IMG(game->play->background,
        "assets/images/regions/background.png", NULL);
    SET_SPRITE_IMG(game->play->foreground,
        "assets/images/regions/foreground.png", NULL);
}

void link_regions(game_t *game)
{
    game->play->region_list[START_REGION]->top = game->play->region_list[MINE_REGION];
    game->play->region_list[MINE_REGION]->bottom = game->play->region_list[START_REGION];
}

void init_all_regions(game_t *game)
{
    for (int id = 0; id < REGION_NB; ++id)
        game->play->region_list[id] = create_region(id);
    init_map(game);
    load_region(game->play->region_list[START_REGION]);
    game->play->current_region = game->play->region_list[START_REGION];
    game->play->current_region_pos = (sfVector2i){0, 1};
    link_regions(game);
}
