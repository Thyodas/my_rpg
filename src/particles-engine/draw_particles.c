/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** draw_particles.c
*/

#include "rpg.h"

static void set_primitive_type(sfVertexArray *vertex_array, int type)
{
    switch (type) {
        case SNOW:
            sfVertexArray_setPrimitiveType(vertex_array, sfPoints);
            break;
        case BLOOD:
            sfVertexArray_setPrimitiveType(vertex_array, sfTrianglesFan);
            break;
        default:
            break;
    }
}

void draw_particles(game_t *game, int type)
{
    sfVertexArray *vertex_array = sfVertexArray_create();

    set_primitive_type(vertex_array, type);
    for (int i = 0; i < game->emitter[type].nb_particles; ++i)
        sfVertexArray_append(vertex_array,
                            game->emitter[type].particles[i].vertex);
    sfRenderWindow_drawVertexArray(game->window, vertex_array, NULL);
    sfVertexArray_destroy(vertex_array);
}
