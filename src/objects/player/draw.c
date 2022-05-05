/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** draw.c
*/

#include "rpg.h"

void draw_player(game_t *game)
{
    entity_t *player = &((player_t *)(game->play->player->data))->entity;
    sfRenderWindow_drawSprite(game->window, player->sprite, NULL);
    if (!game->debug_mode)
        return;
    static sfRectangleShape *shape = NULL;
    if (shape == NULL) {
        shape = sfRectangleShape_create();
        sfRectangleShape_setFillColor(shape, (sfColor){61, 70, 242, 100});
        sfRectangleShape_setOutlineColor(shape, (sfColor){61, 70, 242, 200});
    }
    sfFloatRect rect = sfSprite_getGlobalBounds(player->sprite);
    sfRectangleShape_setSize(shape, (sfVector2f){rect.width,
        rect.height});
    sfRectangleShape_setPosition(shape, (sfVector2f){rect.left,
        rect.top});
    sfRenderWindow_drawRectangleShape(game->window, shape, NULL);
}
