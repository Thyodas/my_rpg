/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** loop_region
*/

#include "region.h"
#include "game.h"
#include "object.h"

void draw_scene(game_t *game);
void handle_object(game_t *game);

void draw_region_objects(game_t *game, region_t *region)
{
    object_t *obj;

    for (linked_list_t *head = region->objects; head;
        head = head->next) {
        obj = head->data;
        obj->draw(game, obj);
    }
}

void draw_debug_mode(game_t *game, region_t *region)
{
    if (!game->debug_mode)
        return;
    static sfSprite *collision = NULL;
    if (collision == NULL) {
        collision = sfSprite_create();
        sfSprite_setTexture(collision, sfTexture_createFromImage(
            region->map->collision, NULL), false);
        sfSprite_setColor(collision, (sfColor){255, 255, 255, 100});
    }
    sfRenderWindow_drawSprite(game->window, collision, NULL);
}

void draw_region(game_t *game, region_t *region)
{
    sfRenderWindow_drawSprite(game->window, region->map->background, NULL);
    draw_region_objects(game, region);
    game->play->player->draw(game, game->play->player);
    sfRenderWindow_drawSprite(game->window, region->map->foreground, NULL);
    draw_debug_mode(game, region);
    draw_scene(game);
}

void handle_region(game_t *game)
{
    handle_object(game);
    object_t *obj;
    for (linked_list_t *head = game->play->current_region->objects; head;
        head = head->next) {
        obj = head->data;
        obj->handler(game, obj);
    }
    game->play->player->handler(game, game->play->player);
}
