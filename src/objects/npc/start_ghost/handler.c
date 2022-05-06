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

void npc_start_ghost_handler(game_t *game, object_t *self)
{
    npc_t *npc = self->data;
    dialogue_box_handler(game, npc->dialogue);
    return;
}
