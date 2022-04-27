/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** particles_engine.c
*/

#include "rpg.h"

void gen_snow(game_t *game, int nb_flakes);
void activate_flakes(particles_emitter_t *emitter);
void update_flakes(particles_emitter_t *emitter);
void draw_particles(game_t *game, int type);

static void handle_snow(game_t *game)
{
    sfTime time_elapsed;

    gen_snow(game, 1000);
    time_elapsed = sfClock_getElapsedTime(game->emitter[SNOW].particles_clock);
    if (time_elapsed.microseconds > 1000000) {
        sfClock_restart(game->emitter[SNOW].particles_clock);
        activate_flakes(&game->emitter[SNOW]);
    }
    update_flakes(&game->emitter[SNOW]);
    draw_particles(game, SNOW);
}

void handle_blood(game_t *game, int x, int y)
{

}

void handle_particles(game_t *game, int type, int x, int y)
{
    switch (type) {
        case SNOW:
            handle_snow(game);
            break;
        case BLOOD:
            handle_blood(game, x, y);
            break;
        default:
            break;
    }
}