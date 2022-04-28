/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** region
*/

#ifndef REGION_H_
    #define REGION_H_

    #include "mylist.h"
    #include <stdbool.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>

    typedef struct regions_s {
        int id;
        linked_list_t *entities;
        struct regions_s *left;
        struct regions_s *right;
        struct regions_s *top;
        struct regions_s *bottom;
        bool is_loaded;
    } region_t;

    const static char *REGION_NAME[] = {
        "start"
    };

    enum {
        START_REGION,
        MINE_REGION,
        REGION_NB
    };

    #define REGION_SIZE_X 480
    #define REGION_SIZE_Y 272

    #define INIT_REGION(id) (game->play->region_list[id] = create_region(id))

#endif /* !REGION_H_ */
