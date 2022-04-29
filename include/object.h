/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** objects
*/

#ifndef OBJECTS_H_
    #define OBJECTS_H_

    #include "game.h"
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

    typedef struct object_s {
        enum id_object_type id;
        void *data;
        void (*handler)(game_t *game, struct object_s *self);
        void (*draw)(game_t *game, struct object_s *self);
    } object_t;

#endif /* !OBJECTS_H_ */
