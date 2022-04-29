/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** game
*/

#ifndef GAME_H_
    #define GAME_H_

    #include "ui.h"
    #include "time.h"
    #include "option.h"
    #include "particles.h"
    #include "entity.h"
    #include "region.h"
    #include "map.h"
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>

    typedef struct play_s {
        entity_t *player;
        region_t *region_list[REGION_NB];
        region_t *start_region;
        region_t *current_region;
        map_t *map_list[MAP_NB];
        sfVector2i current_region_pos;
        sfView *view;
    } play_t;

    typedef struct game_s {
        int current_scene;
        sfRenderWindow *window;
        my_time_t *clock;
        cursor_t *cursor;
        start_menu_t *start_menu;
        play_t *play;
        sfEvent event;
    } game_t;

    #define SET_SPRITE_IMG(sprite, img, area) (sfSprite_setTexture(sprite, \
        sfTexture_createFromFile(img, area), sfFalse))

#endif /* !GAME_H_ */
