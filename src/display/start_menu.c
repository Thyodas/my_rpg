/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** start_menu
*/

#include "rpg.h"

void draw_cursor(sfRenderWindow *window, cursor_t *cursor);
void start_menu_events_handler(game_t *game, sfEvent event);
void draw_button(game_t *game, button_t *button);
button_t *init_button(char *path, sfVector2f pos,
                        sfIntRect rect);

void init_start_menu(game_t *game)
{
    game->start_menu = malloc(sizeof(start_menu_t));
    game->start_menu->play = init_button("assets/images/play.png",
                        (sfVector2f){100, 100}, (sfIntRect){0, 0, -1, 0});
}

void start_menu(game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event))
        start_menu_events_handler(game, event);
    sfRenderWindow_clear(game->window, sfBlack);

    // TODO draw background

    draw_button(game, game->start_menu->play);

    draw_cursor(game->window, game->cursor);
    sfRenderWindow_display(game->window);
}
