/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** region
*/

#ifndef REGION_H_
    #define REGION_H_

    #define NB_MAX_INFO 4
    #define REGION_SIZE_X 480
    #define REGION_SIZE_Y 272

    #define INIT_REGION(id) (game->play->region_list[id] = create_region(id))

    #include <stdbool.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>
    #include "mylist.h"
    object_t;
    regions_t;

    typedef enum {
        SWORD,
        CRAB,
        FISH
    } id_entity_e;

    const static char *REGION_NAME[] = {
        "start"
    };

    enum {
        START_REGION,
        MINE_REGION,
        REGION_NB
    };

    typedef struct {
        int x1;
        int y1;
        int x2;
        int y2;
        id_entity_e id;
    } object_t;

    typedef struct {
        int id;
        linked_list_t *entities;
        regions_t *left;
        regions_t *right;
        regions_t *top;
        regions_t *bottom;
        bool is_loaded;
    } regions_t;


#endif /* !REGION_H_ */
