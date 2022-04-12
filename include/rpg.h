/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** rpg
*/

#ifndef RPG_H_
    #define RPG_H_

    #include <stdlib.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>
    #include <time.h>
    #include "mylist.h"

    typedef struct my_time_s {
        sfTime time;
        float seconds;
        sfClock *clock;
        float prev_time;
    } my_time_t;

    typedef struct option_s {
        char *path;
        sfVector2f scale;
        sfVector2f pos;
        sfIntRect int_rect;
        int rect;
    } option_t;

    typedef struct entity_s {
        sfSprite *sprite;
        sfTexture *texture;
        sfIntRect rect;
        int spritesheet_rect; // Décalage d'image sur spritesheet par pixel (spritesheet horizontal)
    } entity_t;

    typedef struct cursor_s {
        sfTexture *texture;
        sfSprite *sprite;
        sfIntRect rect;
        sfVector2f pos;
    } cursor_t;

    typedef struct start_menu_s {
        entity_t *new_game;
        entity_t *play;
        entity_t *quit;
        entity_t *help;
        linked_list_t **waves;
    } start_menu_t;

    typedef struct game_s {
        int current_scene;
        sfRenderWindow *window;
        my_time_t *clock;
        cursor_t *cursor;
        start_menu_t *start_menu;
    } game_t;

    my_time_t *init_clock(void);

    /* Drawing */
    void draw_list_entity(game_t *game, linked_list_t **list);
    void draw_entity(game_t *game, entity_t *entity);

    /* Init */
    entity_t *init_entity(option_t option);

#endif /* !RPG_H_ */
