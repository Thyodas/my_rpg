/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** exit.c
*/

#include "rpg.h"

void exit_game(game_t *game)
{
    sfRenderWindow_close(game->window);
}