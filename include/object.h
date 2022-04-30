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
    #include "inventory.h"

    #define SLIME_PATH "assets/spritesheets/slime.png"

    enum id_object_type {
        TELEPORTER_OBJ,
        BUTTON_OBJ,
        OBJECT_NB
    };

    typedef struct {
        sfFloatRect area;
        region_t *dest_region;
    } teleporter_t;

    typedef struct {
        sfSprite *sprite;
        sfTexture *texture;
        sfIntRect *rect;
    } graphics_t;

    typedef struct {
        int damage;
        int life_points;
    } stats_t;

    typedef struct {
        sfVector2i pos1;
        sfVector2i pos2;
        entity_t entity;
        stats_t *stats;
    } enemy_t;

    typedef struct {
        entity_t entity;
        int speed;
        int health;
        inventory_t inventory;
    } player_t;

    typedef struct object_s {
        enum id_object_type id;
        void *data;
        void (*handler)(); //TODO @Guillaume
        void (*draw)();
    } object_t;

    #define CAST_PLAYER(arg) ((player_t *)(arg))

#endif /* !OBJECTS_H_ */
