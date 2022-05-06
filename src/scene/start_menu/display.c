/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** display.c
*/

#include "rpg.h"
#include "my.h"

void draw_scene(game_t *game);
void handle_object(game_t *game);
void events_handler_start_scene(game_t *game);
void draw_cursor(sfRenderWindow *window, cursor_t *cursor);

void start_menu(game_t *game)
{
    sfRenderWindow_clear(game->window, (sfColor){28, 28, 28, 255});
    events_handler_start_scene(game);
    handle_object(game);
    if (game->current_scene != START_SCENE)
        return;
    game->scene[START_SCENE]
    ->emitter->ptr_part(game->scene[START_SCENE]->emitter, SNOW,
                        (sfVector2f){0.0, 0.0}, game->window);
    draw_scene(game);
    draw_cursor(game->window, game->cursor);
    sfRenderWindow_display(game->window);
}