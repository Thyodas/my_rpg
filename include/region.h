/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** region
*/

#ifndef REGION_H_
    #define REGION_H_
    #define NB_MAX_INFO 4

    #include "entity.h"
    #include "mylist.h"
    object_t;

    typedef enum {
        SWORD,
        CRAB,
        FISH
    } parsing_t;

    typedef struct {
        object_t *data;
        l_enemy_t *next;
    } l_enemy_t;

    typedef struct {
        int x1;
        int y1;
        int x2;
        int y2;
        parsing_t id;
    } object_t;

    typedef struct {
        int x;
        int y;
        entity_t *background;
        entity_t *foreground;
        entity_t *collision;
        l_enemy_t *enemy;
        object_t *object;
    } region_t;

#endif /* !REGION_H_ */
