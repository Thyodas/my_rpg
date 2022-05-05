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
}

static void init_settings(game_t *game)
{
    game->settings.general_volume = 100;
    game->settings.volume_music = 100;
    game->settings.music_text = NULL;
    game->settings.general_text = NULL;
}

void init_data(game_t *game)
{
    game->current_scene = 0;
    game->previous_scene = 0;
    game->window = init_window();
    game->cursor = init_cursor(game->window);
    game->debug_mode = false;
    game->play = NULL;
    init_all_data_structure(game);
    init_settings(game);
}
