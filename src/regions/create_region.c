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

char *extend_string(const char *first, const char *second)
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

region_t *load_region(region_t *region)
{
    // region parsing
    char *path = extend_string("assets/images/regions/",
        REGION_NAME[region->id]);
    path = extend_string(path, ".png");
    region->background = sfSprite_create();
    region->foreground = sfSprite_create();
    region->collision = get_collision_image(path);
    SET_SPRITE_IMG(region->background, path, &((sfIntRect){0, 0, 480, 272}));
    SET_SPRITE_IMG(region->foreground, path, &((sfIntRect){0, 272, 480, 272}));
    sfSprite_setScale(region->background, (sfVector2f){4, 4});
    sfSprite_setScale(region->foreground, (sfVector2f){4, 4});
    region->is_loaded = true;
    free(path);
}

void init_all_regions(game_t *game)
{
    for (int i = 0; i < REGION_NB; ++i)
        INIT_REGION(START_REGION);
    load_region(game->play->region_list[START_REGION]);
    game->play->current_region = game->play->region_list[START_REGION];
}
