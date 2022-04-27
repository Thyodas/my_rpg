/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** ui
*/

#ifndef UI_H_
    #define UI_H_

    #include <SFML/Graphics.h>

    #include "entity.h"

    typedef struct cursor_s {
        sfTexture *texture;
        sfSprite *sprite;
        sfIntRect rect;
        sfVector2f pos;
    } cursor_t;

    typedef struct start_menu_s {
        linked_list_t **waves;
        entity_t *new_game;
        entity_t *play;
        entity_t *exit;
        entity_t *help; // TODO when clicked -> help_clicked = 1;
        int help_clicked; // TODO 1 ? draw help_menu : remove from screen;
        entity_t *help_menu; // TODO design help menu;
    } start_menu_t;

#endif /* !UI_H_ */
