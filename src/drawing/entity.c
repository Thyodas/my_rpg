/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** entity
*/

#include "rpg.h"

void draw_entity(game_t *game, entity_t *entity)
{
    sfRenderWindow_drawSprite(game->window, entity->sprite, NULL);
}
