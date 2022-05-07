/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** handler
*/

#include "rpg.h"

sfVector2f getPositionInteraction(player_t *player, int status)
{
    sfVector2f pos = sfSprite_getPosition(player->entity.sprite);

    if (status == 0) {
        pos.x += 17.0;
        pos.y -= 1.5;
    }
    if (status == 1) {
        pos.x -= 17.5;
        pos.y += 7.0;
    }
    if (status == 2) {
        pos.x += 10.0;
        pos.y += 15.0;
    }
    if (status == 3) {
        pos.x += 2.0;
        pos.y -= 12.0;
    }
    return pos;
}
