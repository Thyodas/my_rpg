/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** objects
*/

#ifndef OBJECTS_H_
    #define OBJECTS_H_

    #include "region.h"
    #include "entity.h"

    enum id_object_type {
        TELEPORTER_OBJ,
        OBJECT_NB
    };

    typedef struct {
        sfFloatRect area;
        region_t *dest_region;
    } teleporter_t;

    typedef struct {
        entity_t entity;
        int speed;
        int health;
    } player_t;

    typedef struct object_s {
        enum id_object_type id;
        void *data;
        void (*handler)(); // TODO @Guillaume
        void (*draw)();
    } object_t;

#endif /* !OBJECTS_H_ */
