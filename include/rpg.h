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

    typedef struct button_s {
        sfSprite *sprite;
        sfTexture *texture;
        sfIntRect rect;
    } button_t;

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
        cursor_t *cursor;
        start_menu_t *start_menu;
        // menu_t *menu;
        // game_menu_t *game_menu;
        // tutorial_t *tuto_menu;
    } game_t;


#endif /* !RPG_H_ */
