/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** button
*/

#include "rpg.h"

void draw_button(game_t *game, button_t *button)
{
    sfRenderWindow_drawSprite(game->window, button->sprite, NULL);
}
