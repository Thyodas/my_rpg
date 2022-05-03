/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** display_settings_menu.c
*/

#include "rpg.h"
#include "settings.h"

void draw_cursor(sfRenderWindow *window, cursor_t *cursor);
void init_settings_menu(game_t *game);

static void handle_object_list_settings_menu(game_t *game)
{
    linked_list_t *tmp = game->settings_menu->obj;
    object_t *obj;

    while (tmp != NULL) {
        obj = tmp->data;
        obj->handler(game, obj);
        tmp = tmp->next;
    }
}

static void draw_object_list_settings_menu(game_t *game)
{
    linked_list_t *tmp = game->settings_menu->obj;
    object_t *obj;

    while (tmp != NULL) {
        obj = tmp->data;
        obj->draw(game, obj);
        tmp = tmp->next;
    }
}

void settings_menu(game_t *game)
{
    sfEvent event;

    sfRenderWindow_clear(game->window, sfBlack);
    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        check_mouse_movement(game, event);
    }
    handle_object_list_settings_menu(game);
    game->settings_menu->emitter->ptr_part(game->settings_menu->emitter,
                                SNOW, (sfVector2f){0.0, 0.0}, game->window);
    draw_object_list_settings_menu(game);
    draw_cursor(game->window, game->cursor);
    sfRenderWindow_display(game->window);
}