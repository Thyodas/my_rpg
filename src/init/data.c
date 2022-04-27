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
    data->emitter = malloc(sizeof(particles_emitter_t) * NB_PART);
    for (int i = 0; i < NB_PART; ++i) {
        data->emitter[i].is_gen = 0;
        data->emitter[i].nb_particles = 0;
    }
}
