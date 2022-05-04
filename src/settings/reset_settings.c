/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** reset_settings.c
*/

#include "rpg.h"

void reset_settings(game_t *game)
{
    game->settings.general_volume = 100;
    game->settings.volume_music = 100;
}
