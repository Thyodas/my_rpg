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
void init_all_maps(game_t *game);

void init_game(game_t *game)
{
    // game->clock = init_clock(); TODO start 60 secs clocks
    game->play = malloc(sizeof(play_t));
    game->play->view = NULL;
    init_all_maps(game);
    init_all_regions(game);

    option_t option = {
        NULL,
        (sfVector2f){1.0, 1.0},
        (sfVector2f){REGION_SIZE_X * game->play->current_region_pos.x + 200,
            REGION_SIZE_Y * game->play->current_region_pos.y + 170},
        (sfIntRect){0, 0, 24, 24},
        24,
    };
    game->play->player = init_player(option);
}

void game(game_t *game)
{
    // play_animate_sprites(game);
    while (sfRenderWindow_pollEvent(game->window, &game->event))
        play_events_handler(game, game->event);
    play_keyboard_events_handler(game);
    sfRenderWindow_clear(game->window, sfBlack);

    draw_region(game, game->play->current_region);

    // draw_cursor(game->window, game->cursor);
    sfRenderWindow_display(game->window);
}
