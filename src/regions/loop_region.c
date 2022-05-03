/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** loop_region
*/

#include "region.h"
#include "game.h"
#include "object.h"

void draw_object(game_t *game);
void handle_object(game_t *game);

void draw_region(game_t *game, region_t *region)
{
    sfRenderWindow_drawSprite(game->window, region->map->background, NULL);
    draw_object(game);
    object_t *obj;
    for (linked_list_t *head = game->play->current_region->objects; head;
        head = head->next) {
        obj = head->data;
        obj->draw(game, obj);
    }
    sfRenderWindow_drawSprite(game->window, region->map->foreground, NULL);
    if (!game->debug_mode)
        return;
    static sfSprite *collision = NULL;
    if (collision == NULL)
        collision = sfSprite_create();
    sfTexture *texture = sfTexture_createFromImage(region->map->collision,
        NULL);
    sfSprite_setTexture(collision, texture, false);
    sfSprite_setColor(collision, (sfColor){255, 255, 255, 100});
    sfRenderWindow_drawSprite(game->window, collision, NULL);
    sfTexture_destroy(texture);
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
}
