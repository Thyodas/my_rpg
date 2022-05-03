/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** draw_object.c
*/

#include "rpg.h"
#include "object.h"

void draw_object(game_t *game)
{
    linked_list_t *tmp = game->scene[game->current_scene]->obj;
    object_t *obj;

    while (tmp != NULL) {
        obj = tmp->data;
        obj->draw(game, obj);
        tmp = tmp->next;
    }
}
