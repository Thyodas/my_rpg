/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** display.c
*/

#include "rpg.h"

void draw_object(game_t *game);
void handle_object(game_t *game);
void events_handler_settings_scene(game_t *game);
void draw_cursor(sfRenderWindow *window, cursor_t *cursor);

void settings_menu(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    events_handler_settings_scene(game);
    handle_object(game);
    game->scene[SETTINGS_SCENE]->emitter->
                                ptr_part(game->scene[SETTINGS_SCENE]->emitter,
                                SNOW, (sfVector2f){0.0, 0.0}, game->window);
    draw_object(game);
    draw_cursor(game->window, game->cursor);
    sfRenderWindow_display(game->window);
}