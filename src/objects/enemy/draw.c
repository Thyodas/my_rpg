/*
** EPITECH PROJECT, 2022
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** draw
*/

#include "game.h"
#include "object.h"

void draw_enemy(game_t *game, struct object_s *self)
{
    if (!game->debug_mode)
        return;
    static sfRectangleShape *shape = NULL;
    teleporter_t *data = self->data;
    if (shape == NULL) {
        shape = sfRectangleShape_create();
        sfRectangleShape_setFillColor(shape, (sfColor){10, 50, 150, 100});
        sfRectangleShape_setOutlineColor(shape, (sfColor){10, 50, 150, 200});
    }
    sfRectangleShape_setSize(shape, (sfVector2f){data->area.width,
        data->area.height});
    sfRectangleShape_setPosition(shape, (sfVector2f){data->area.left,
        data->area.top});
    sfRenderWindow_drawRectangleShape(game->window, shape, NULL);
}
