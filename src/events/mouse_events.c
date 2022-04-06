/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** mouse_events
*/

#include "rpg.h"

void check_mouse_movement(game_t *game, sfEvent event)
{
    sfVector2i pos;

    if (event.type == sfEvtMouseMoved) {
        pos = sfMouse_getPositionRenderWindow(game->window);
        game->cursor->pos.x = pos.x;
        game->cursor->pos.y = pos.y;
        sfSprite_setPosition(game->cursor->sprite, game->cursor->pos);
    }
}
