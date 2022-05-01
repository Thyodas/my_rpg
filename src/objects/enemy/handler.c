/*
** EPITECH PROJECT, 2022
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** handler
*/

#include "game.h"
#include "object.h"
#include <stdio.h>

void enemy_handler(game_t *game, struct object_s *self)
{
    enemy_t *enemy = self->data;
    sfFloatRect rect = sfSprite_getGlobalBounds(
        ((player_t *)(game->play->player->data))->entity.sprite);
    if (sfFloatRect_intersects(&rect, &enemy->area, NULL)) {
        //player.life--;
    }
    return;
}
