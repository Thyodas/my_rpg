/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** loop_region
*/

#include "region.h"
#include "game.h"
#include "object.h"

void draw_entity(game_t *game, entity_t *entity);

void draw_region(game_t *game, region_t *region)
{
    sfRenderWindow_drawSprite(game->window, region->map->background, NULL);
    draw_entity(game, game->play->player);
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
    sfRenderWindow_drawSprite(game->window, collision, NULL);
    sfTexture_destroy(texture);
}

void handle_region(game_t *game)
{
    object_t *obj;
    for (linked_list_t *head = game->play->current_region->objects; head;
        head = head->next) {
        obj = head->data;
        obj->handler(game, obj);
    }
}
