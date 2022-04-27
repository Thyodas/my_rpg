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
        sfSprite *background;
        sfSprite *foreground;
        sfSprite *collision;
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
        REGION_NB
    };

    #define INIT_REGION(id) (game->play->region_list[id] = create_region(id))

#endif /* !REGION_H_ */
