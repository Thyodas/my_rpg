/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** handler
*/

#include "rpg.h"

sfVector2f get_position_interaction(player_t *player, int status)
{
    sfVector2f pos = sfSprite_getPosition(player->entity.sprite);

    if (status == RIGHT) {
        pos.x += 19.0;
        pos.y -= 2.5;
    }
    if (status == LEFT) {
        pos.x -= 19.5;
        pos.y += 8.0;
    }
    if (status == DOWN) {
        pos.x += 10.0;
        pos.y += 17.0;
    }
    if (status == UP) {
        pos.x += 2.0;
        pos.y -= 14.0;
    }
    return pos;
}
