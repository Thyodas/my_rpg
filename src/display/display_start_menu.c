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
void handle_particles(game_t *game, int type, int x, int y);

void init_start_menu(game_t *game)
{
    game->clock = init_clock();
    game->start_menu = malloc(sizeof(start_menu_t));
    option_t option = {
        "assets/spritesheets/waves.png",
        (sfVector2f){5.0, 5.0},
        (sfVector2f){200.0, 900.0},
        (sfIntRect){0, 0, 18, 18},
        18,
        72,
    };
    init_waves_start_menu(game, option);
    option.path = "assets/images/new_game.png";
    option.int_rect.width = -1;
    option.pos = (sfVector2f){800.0, 350.0};
    game->start_menu->new_game = init_entity(option);
    option.path = "assets/images/continue.png";
    option.pos = (sfVector2f){800.0, 500.0};
    game->start_menu->play = init_entity(option);
    option.path = "assets/images/exit.png";
    option.pos = (sfVector2f){800.0, 650.0};
    game->start_menu->exit = init_entity(option);
    option.path = "assets/images/help.png";
    option.pos = (sfVector2f){1800.0, 35.0};
    game->start_menu->help = init_entity(option);
}

void start_menu(game_t *game)
{
    sfEvent event;

    start_menu_animate_sprites(game);
    while (sfRenderWindow_pollEvent(game->window, &event))
        start_menu_events_handler(game, event);
    sfRenderWindow_clear(game->window, sfBlack);
    handle_particles(game, SNOW, 0, 0);

    // draw waves
    //draw_list_entity(game, game->start_menu->waves);

    // if (game->start_menu->help_clicked == 1)
        // draw_entity(game, game->start_menu->help_menu);

    draw_entity(game, game->start_menu->new_game);
    draw_entity(game, game->start_menu->play);
    draw_entity(game, game->start_menu->exit);
    draw_entity(game, game->start_menu->help);

    draw_cursor(game->window, game->cursor);
    sfRenderWindow_display(game->window);
}
