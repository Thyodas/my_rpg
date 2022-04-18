/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** is_hit
*/

#include "rpg.h"

int is_hit(entity_t *entity, cursor_t *cursor, float width, float height)
{
    sfVector2f pos = sfSprite_getPosition(entity->sprite);

    width *= sfSprite_getScale(entity->sprite).x;
    height *= sfSprite_getScale(entity->sprite).y;

    if ((cursor->pos.x >= pos.x && cursor->pos.x <= pos.x + width) &&
        (cursor->pos.y >= pos.y && cursor->pos.y <= pos.y + height))
        return (1);
    return (0);
}
