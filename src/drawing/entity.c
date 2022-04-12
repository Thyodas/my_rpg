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

void draw_list_entity(game_t *game, linked_list_t **list)
{
    linked_list_t *tmp = *list;

    while (tmp != NULL) {
        draw_entity(game, tmp->data);
        tmp = tmp->next;
    }
}
