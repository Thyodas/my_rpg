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

    #define NB_ARGS_SMOKE 3
    #define CAST_SMOKE(arg) ((smoke_t *)(arg))
    #define NB_ARGS_WAVES 3

    enum id_object_type {
        TELEPORTER_OBJ,
        DIALOGUE_OBJ,
        SMOKE_OBJ,
        WAVES_OBJ,
        OBJECT_NB
    };

    typedef struct {
        sfFloatRect area;
        region_t *dest_region;
    } teleporter_t;

    typedef struct smoke {
        int offset_x;
        int offset_pos_x;
        int offset_pos_y;
        sfSprite *sprite;
        sfVector2f pos;
    } smoke_t;

    typedef struct waves {
        long last_clock;
        sfSprite *sprite;
        int offset_x;
        sfVector2f pos;
    } waves_t;

    typedef struct {
        entity_t entity;
        int speed;
        int health;
    } player_t;

    typedef struct object_s {
        enum id_object_type id;
        void *data;
        void (*handler)();
        void (*draw)();
    } object_t;

    #define CAST_PLAYER(arg) ((player_t *)(arg))

#endif /* !OBJECTS_H_ */
