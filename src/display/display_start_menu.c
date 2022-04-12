/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** start_menu
*/

#include "rpg.h"
#include "stdio.h"

void draw_cursor(sfRenderWindow *window, cursor_t *cursor);
void start_menu_events_handler(game_t *game, sfEvent event);
void start_menu_animate_sprites(game_t *game);
void init_waves_start_menu(game_t *game, option_t option);

void init_start_menu(game_t *game)
{
    game->clock = init_clock();
    game->start_menu = malloc(sizeof(start_menu_t));
    option_t option = {
        "assets/images/play.png",
        (sfVector2f){5.0, 5.0},
        (sfVector2f){200.0, 900.0},
        (sfIntRect){0, 0, 18, 18},
        18,
    };
    init_waves_start_menu(game, option);
    game->start_menu->play = init_entity(option);
}

void start_menu(game_t *game)
{
    sfEvent event;

    start_menu_animate_sprites(game);
    while (sfRenderWindow_pollEvent(game->window, &event))
        start_menu_events_handler(game, event);
    sfRenderWindow_clear(game->window, sfBlack);

    // draw waves
    draw_list_entity(game, game->start_menu->waves);

    draw_cursor(game->window, game->cursor);
    sfRenderWindow_display(game->window);
}
