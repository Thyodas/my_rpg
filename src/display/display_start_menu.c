/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** start_menu
*/

#include "rpg.h"
#include "stdio.h"
#include "object.h"

void draw_cursor(sfRenderWindow *window, cursor_t *cursor);
particles_emitter_t *init_emitter(void);

static void handle_object_list_start_menu(game_t *game)
{
    linked_list_t *tmp = game->start_menu->objects;
    object_t *obj;

    while (tmp != NULL) {
        obj = tmp->data;
        obj->handler(game, obj);
        tmp = tmp->next;
    }
}

static void draw_object_list_start_menu(game_t *game)
{
    linked_list_t *tmp = game->start_menu->objects;
    object_t *obj;

    while (tmp != NULL) {
        obj = tmp->data;
        obj->draw(game, obj);
        tmp = tmp->next;
    }
}

void start_menu(game_t *game)
{
    sfEvent event;

    sfRenderWindow_clear(game->window, sfBlack);
    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        check_mouse_movement(game, event);
    }
    handle_object_list_start_menu(game);
    game->start_menu->emitter->ptr_part(game->start_menu->emitter,
                                SNOW, (sfVector2f){0.0, 0.0}, game->window);
    draw_object_list_start_menu(game);
    draw_cursor(game->window, game->cursor);
    sfRenderWindow_display(game->window);
}
