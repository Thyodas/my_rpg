/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_player
*/

#include "rpg.h"
#include "object.h"
#include "my.h"

object_t **create_inventory_object(void)
{
    int nbr = 11;
    object_t **object = malloc(sizeof(object_t *) * nbr);

    for (int i = 0; i < nbr; i++) {
        object[i] = malloc(sizeof(object_t));
        object[i]->data = NULL;
    }
    return object;
}
