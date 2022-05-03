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
    #include "particles.h"

    #define CAST_BUTTON(arg) ((button_t *)(arg))
    #define NB_ARGS_BUTTON 6

    enum buttons_start {
        BTN_NEW,
        BTN_EXIT,
        BTN_HELP,
        BTN_CONTINUE,
        NB_BUTTONS_START
    };

    enum buttons_settings {
        BTN_VOLUME_MUSIC,
        BTN_VOLUME_GENERAL,
        BTN_RESET,
        BTN_RETURN,
        NB_BUTTONS_SETTINGS
    };

    #define NB_BUTTONS (NB_BUTTONS_START + NB_BUTTONS_SETTINGS)

    enum button_state {
        IDLE,
        HOVERED,
        CLICKED
    };

    typedef struct cursor_s {
        sfTexture *texture;
        sfSprite *sprite;
        sfIntRect rect;
        sfVector2f pos;
        int mouse_pressed;
    } cursor_t;

    typedef struct button {
        int id_btn;
        sfSprite *sprite;
        int state;
        void (*on_click)();
    } button_t;

#endif /* !UI_H_ */
