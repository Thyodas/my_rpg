/*
** EPITECH PROJECT, 2022
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** inventory
*/

#ifndef INVENTORY_H_
    #define INVENTORY_H_

    #include "mylist.h"
    #include "object.h"

    typedef struct {
        linked_list_t *object_list;
        object_t *held_object;
    } inventory_t;

#endif /* !INVENTORY_H_ */
