/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** data
*/

#include "rpg.h"

cursor_t *init_cursor(sfRenderWindow *window);
sfRenderWindow *init_window(void);

void init_data(game_t *game)
{
    game->current_scene = 0;
    game->window = init_window();
    game->cursor = init_cursor(game->window);
    game->debug_mode = false;
}
