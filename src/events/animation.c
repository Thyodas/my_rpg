/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** animation
*/

#include "rpg.h"

void rect_animation(game_t *game, entity_t *entity)
{
    if (entity->spritesheet_rect != 0)
        entity->rect.left += entity->spritesheet_rect;
    if (entity->rect.left >= entity->spritesheet_width)
        entity->rect.left = 0;
    sfSprite_setTextureRect(entity->sprite, entity->rect);
}

void rect_list_animation(game_t *game, linked_list_t **list)
{
    linked_list_t *element = *list;

    while (element) {
        rect_animation(game, element->data);
        if (element->next == NULL)
            break;
        element = element->next;
    }
}
