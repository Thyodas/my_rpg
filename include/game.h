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
    #include "object.h"
    #include "settings.h"
    #include "scene.h"
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>
    #include <stdbool.h>

    typedef struct {
        sfFont *retro_font;
    } all_data_t;

    typedef struct play_s {
        object_t *player;
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
        scene_t *scene[NB_SCENE];
        int previous_scene;
        settings_t *settings;
        play_t *play;
        sfEvent event;
        bool debug_mode;
        all_data_t data;
    } game_t;

    #define SET_SPRITE_IMG(sprite, img, area) (sfSprite_setTexture(sprite, \
        sfTexture_createFromFile(img, area), sfFalse))

#endif /* !GAME_H_ */
