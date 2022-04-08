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

    typedef struct my_time_s {
        sfTime time;
        float seconds;
        sfClock *clock;
        float prev_time;
    } my_time_t;

    typedef struct button_s {
        sfSprite *sprite;
        sfTexture *texture;
        sfIntRect rect;
    } button_t;

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
        button_t *new_game;
        button_t *play;
        button_t *quit;
        button_t *help;
    } start_menu_t;

    typedef struct game_s {
        int current_scene;
        sfRenderWindow *window;
        my_time_t *clock;
        entity_t *test;
        cursor_t *cursor;
        start_menu_t *start_menu;
    } game_t;

    my_time_t *init_clock(void);

#endif /* !RPG_H_ */
