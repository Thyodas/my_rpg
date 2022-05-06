/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** npc_handler
*/

#include "rpg.h"
#include <stdio.h>
#include "npc.h"
#include "dialogue.h"

void dialogue_box_handler(game_t *game, dialogue_box_t *dialogue);
float calc_distance(sfVector2f point1, sfVector2f point2);
void dialogue_box_set_text(dialogue_box_t *dialogue, char *text);

float calc_distance_sprite(sfSprite *sprite1, sfSprite *sprite2)
{
    return (calc_distance(sfSprite_getPosition(sprite1),
        sfSprite_getPosition(sprite2)));
}

void change_dialogue_index_animation(game_t *game, npc_t *npc)
{
    static long last_clock = 0;
    if (npc->dialogue_list[npc->dialogue_line][npc->dialogue_index + 1] == NULL
        || !npc->dialogue->finished || last_clock == 0) {
        last_clock = sfClock_getElapsedTime(game->clock->clock).microseconds;
        return;
    }
    long current_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
    double diff = (current_us - last_clock) / 1000000.0;
    if (diff >= 0.5) {
        dialogue_box_set_text(npc->dialogue,
                npc->dialogue_list[npc->dialogue_line][++npc->dialogue_index]);
        last_clock = sfClock_getElapsedTime(game->clock->clock).microseconds;
    }
}

void npc_start_ghost_handler(game_t *game, object_t *self)
{
    player_t *player = game->play->player->data;
    npc_t *npc = self->data;
    if (calc_distance_sprite(player->entity.sprite, npc->entity.sprite) > 100) {
        npc->dialogue_index = 0;
        npc->is_talking = false;
        return;
    }
    if (!npc->is_talking) {
        npc->is_talking = true;
        dialogue_box_set_text(npc->dialogue,
            npc->dialogue_list[npc->dialogue_line][npc->dialogue_index]);
    }
    change_dialogue_index_animation(game, npc);
    dialogue_box_handler(game, npc->dialogue);
    return;
}
