/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** entity
*/

#include "rpg.h"

entity_t *init_entity(char *path, sfVector2f pos, sfIntRect int_rect, int rect)
{
    entity_t *entity = malloc(sizeof(entity_t));

    entity->sprite = sfSprite_create();
    entity->texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(entity->sprite, entity->texture, sfTrue);
    sfSprite_setScale(entity->sprite, (sfVector2f){5, 5});
    sfSprite_setPosition(entity->sprite, pos);
    if (int_rect.width != -1) {
        entity->rect = int_rect;
        sfSprite_setTextureRect(entity->sprite, int_rect);
    }
    entity->spritesheet_rect = rect;

    return (entity);
}
