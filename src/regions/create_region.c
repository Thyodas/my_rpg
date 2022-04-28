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

char *extend_string(char *first, char *second)
{
    int len_first = my_strlen(first);
    int len_second = my_strlen(second);
    char *new = malloc(sizeof(char) * len_first + len_second + 1);
    int pos = 0;

    for (; *first; ++first) {
        new[pos++] = *first;
    }
    for (; *second; ++second) {
        new[pos++] = *second;
    }
    new[pos] = '\0';
    return new;
}

region_t *load_region(region_t *region)
{
    // region parsing
    region->background = sfSprite_create();
    region->foreground = sfSprite_create();
    region->collision = sfImage_createFromFile("assets/images/regions/start_collision.png");
    SET_SPRITE_IMG(region->background, "assets/images/regions/start_background.png");
    SET_SPRITE_IMG(region->foreground, "assets/images/regions/start_foreground.png");
    sfSprite_setScale(region->background, (sfVector2f){4, 4});
    sfSprite_setScale(region->foreground, (sfVector2f){4, 4});
}

void init_all_regions(game_t *game)
{
    INIT_REGION(START_REGION);
    load_region(game->play->region_list[START_REGION]);
    game->play->current_region = game->play->region_list[START_REGION];
}
