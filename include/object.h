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

    enum {
        TELEPORTER,
        OBJECT_NB
    };

    typedef enum {
        SWORD,
        CRAB,
        FISH
    } id_entity_e;

    typedef struct {
        int x1;
        int y1;
        int x2;
        int y2;
        id_entity_e id;
    } object_t;

#endif /* !OBJECTS_H_ */
