/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** parser
*/

#include "game.h"
#include "region.h"
#include <stdio.h>

void parse_teleporter(game_t *game, region_t *region, char **args)
{
    printf("Hello teleporter!\n");
    for (int i = 0; args[i] != NULL; ++i) {
        dprintf(1, "%s ", args[i]);
    }
}