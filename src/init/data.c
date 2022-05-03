/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** data
*/

#include "rpg.h"

cursor_t *init_cursor(sfRenderWindow *window);
sfRenderWindow *init_window(void);

static void init_all_data_structure(game_t *game)
{
    game->data.retro_font = sfFont_createFromFile("assets/fonts/retro.ttf");
    //sfTexture_setSmooth(sfFont_getTexture(game->data.retro_font, 10), sfFalse);
}

void init_data(game_t *game)
{
    game->current_scene = 0;
    game->window = init_window();
    game->cursor = init_cursor(game->window);
    game->debug_mode = false;
    init_all_data_structure(game);
}
