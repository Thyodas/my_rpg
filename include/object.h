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
    #define NB_ARGS_BORDER_WAVES 5

    enum id_object_type {
        TELEPORTER_OBJ,
        DIALOGUE_OBJ,
        SMOKE_OBJ,
        WAVES_OBJ,
        ENEMY_OBJ,
        WAVES_BORDER_OBJ,
        OBJECT_NB,
    };

    #define SLIME_PATH "assets/spritesheets/slime.png"
    #define SKELETON_PATH "assets/spritesheets/skeleton.png"
    #define ENEMY_NB 4

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

    typedef struct waves_border {
        sfSprite *sprite;
        int offset_x;
        int offset_y;
        sfVector2f pos;
        int direction;
        long last_clock;
    } waves_border_t;

    typedef struct {
        entity_t entity;
        int speed;
        int health;
    } player_t;

    typedef struct stats_s {
        int damage;
        int life_points;
    } stats_t;

    typedef struct {
        sfVector2i self_pos;
        sfVector2i *pos;
        int where_to_go;
        entity_t entity;
        stats_t *stats;
    } enemy_t;

    typedef struct object_s {
        enum id_object_type id;
        void *data;
        void (*handler)();
        void (*draw)();
    } object_t;

    #define CAST_PLAYER(arg) ((player_t *)(arg))

#endif /* !OBJECTS_H_ */
