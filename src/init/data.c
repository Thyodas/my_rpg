/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** data
*/

#include "rpg.h"

cursor_t *init_cursor(sfRenderWindow *window);
sfRenderWindow *init_window(void);

void init_data(game_t *data)
{
    data->current_scene = 0;
    data->window = init_window();
    data->cursor = init_cursor(data->window);
}
