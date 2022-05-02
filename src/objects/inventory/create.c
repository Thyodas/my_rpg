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
    int i = 0;
    object_t **object = malloc(sizeof(object_t *) * (10 + 1));;

    for (; i < 10; i++)
        object[i] = malloc(sizeof(object_t));
    object[i] = NULL;
    return (object);
}
