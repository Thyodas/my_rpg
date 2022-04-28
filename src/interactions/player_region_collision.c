/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** player_region_collision
*/

#include "game.h"
#include "region.h"
#include <stdio.h>
#include <stdbool.h>

static bool is_pixel_red(sfImage *image, int x, int y)
{
    sfColor color = sfImage_getPixel(image, x, y);

    return (color.r == 255 && color.g == 0 && color.b == 0);
}

bool is_pixel_colliding(game_t *game, sfFloatRect *player_bounds, int y)
{
    for (int x = player_bounds->left; x < player_bounds->width
        + player_bounds->left; ++x) {
        if (is_pixel_red(game->play->current_region->collision, x, y)) {
            return true;
        }
    }
    return false;
}


bool check_player_region_collision(game_t *game, float shift_x, float shift_y)
{
    sfFloatRect player_bounds = sfSprite_getGlobalBounds(
        game->play->player->sprite);
    player_bounds.left = (shift_x + player_bounds.left) / 4;
    player_bounds.top = (shift_y + player_bounds.top) / 4;
    player_bounds.height /= 4;
    player_bounds.width /= 4;
    if (player_bounds.top < 0 || player_bounds.top + player_bounds.height > 272
        || player_bounds.left < 0 || player_bounds.left
        + player_bounds.width > 480)
        return true;

    for (int y = player_bounds.top; y < player_bounds.height
        + player_bounds.top; ++y)
        if (is_pixel_colliding(game, &player_bounds, y))
            return true;
    return false;
}