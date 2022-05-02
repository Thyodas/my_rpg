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
void play_events_handler(game_t *game, sfEvent event);
void init_all_maps(game_t *game);
void handle_region(game_t *game);
object_t *create_player_object(option_t option);
object_t **create_inventory_object(void);

void player_idle_animation(game_t *game);

void init_game(game_t *game)
{
    // game->clock = init_clock(); TODO start 60 secs clocks
    game->play = malloc(sizeof(play_t));
    game->play->view = NULL;
    init_all_maps(game);
    init_all_regions(game);

    option_t option = {
        "./assets/spritesheets/character.png",
        (sfVector2f){1.0, 1.0},
        (sfVector2f){REGION_SIZE_X * game->play->current_region_pos.x + 200,
            REGION_SIZE_Y * game->play->current_region_pos.y + 170},
        (sfIntRect){0, 0, 16, 16},
        16,
        16,
        96,
        96,
    };
    game->play->player = create_player_object(option);
    game->play->inventory = create_inventory_object();
}

void game(game_t *game)
{
    // player_idle_animation(game);
    while (sfRenderWindow_pollEvent(game->window, &game->event))
        play_events_handler(game, game->event);
    play_keyboard_events_handler(game);
    sfRenderWindow_clear(game->window, sfBlack);
    handle_region(game);
    draw_region(game, game->play->current_region);

    // draw_cursor(game->window, game->cursor);
    sfRenderWindow_display(game->window);
}
