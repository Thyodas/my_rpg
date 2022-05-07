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
    #include "map.h"

    typedef struct regions_s {
        int id;
        linked_list_t *objects;
        struct regions_s *left;
        struct regions_s *right;
        struct regions_s *top;
        struct regions_s *bottom;
        map_t *map;
        bool is_loaded;
        const char *music_path;
    } region_t;

    const static char *REGION_PATH[] = {
        "data/regions/start.region",
        "data/regions/mine.region",
        "data/regions/start_house_interior.region",
        "data/regions/mine_interior_top.region",
        "data/regions/mine_interior_bottom.region"
    };

    enum {
        START_REGION,
        MINE_REGION,
        START_HOUSE_INTERIOR,
        MINE_INTERIOR_TOP,
        MINE_INTERIOR_BOTTOM,
        REGION_NB
    };

    const static int REGION_MAP_JMP_TABLE[REGION_NB] = {
        BASE_MAP, // Start_region (id 0) is linked to map id 0 (base map)
        BASE_MAP,
        START_HOUSE_MAP,
        MINE_INTERIOR_MAP,
        MINE_INTERIOR_MAP
    };

#endif /* !REGION_H_ */
