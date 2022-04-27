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
entity_t *init_player(option_t option);
void play_events_handler(game_t *game, sfEvent event);

void init_game(game_t *game)
{
    // game->clock = init_clock(); TODO start 60 secs clocks
    game->play = malloc(sizeof(play_t));
    option_t option = {
        NULL,
        (sfVector2f){5.0, 5.0},
        (sfVector2f){960.0, 540.0},
        (sfIntRect){0, 0, 24, 24},
        24,
    };
    game->play->player = init_player(option);
    init_all_regions(game);
}

void game(game_t *game)
{
    sfEvent event;

    // play_animate_sprites(game);
    while (sfRenderWindow_pollEvent(game->window, &event))
        play_events_handler(game, event);
    sfRenderWindow_clear(game->window, sfBlack);

    draw_region(game, game->play->current_region);

    draw_entity(game, game->play->player);

    // draw_cursor(game->window, game->cursor);
    sfRenderWindow_display(game->window);
}
