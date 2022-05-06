/*
** EPITECH PROJECT, 2022
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** draw
*/

#include "game.h"
#include "object.h"

static void debug_draw(game_t *game, object_t *self)
{
    return;
}

void draw_enemy(game_t *game, object_t *self)
{
    enemy_t *enemy = self->data;
    sfRenderWindow_drawSprite(game->window, enemy->entity.sprite, NULL);
    if (game->debug_mode) {
        debug_draw(game, self);
        return;
    }
}
