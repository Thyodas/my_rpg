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

void change_region(game_t *game, region_t *current_region, int dir_x,
int dir_y);

static bool is_pixel_red(sfImage *image, int x, int y)
{
    sfColor color = sfImage_getPixel(image, x, y);

    return (color.r == 255 && color.g == 0 && color.b == 0);
}

bool is_pixel_colliding(game_t *game, sfFloatRect *player_bounds, int y)
{
    for (int x = player_bounds->left; x < player_bounds->width
        + player_bounds->left; ++x) {
        if (is_pixel_red(game->play->collision, x, y)) {
            return true;
        }
    }
    return false;
}

void move_to_region(game_t *game, sfFloatRect *player_bounds)
{
    if (player_bounds->top + player_bounds->height / 2
        < game->play->current_region_pos.y * REGION_SIZE_Y
        && game->play->current_region->top != NULL)
            change_region(game, game->play->current_region->top, 0, -1);
    if (player_bounds->top + player_bounds->height / 2
        > (game->play->current_region_pos.y + 1) * REGION_SIZE_Y
        && game->play->current_region->bottom != NULL)
            change_region(game, game->play->current_region->bottom, 0, 1);
    if (player_bounds->left + player_bounds->width / 2
        < game->play->current_region_pos.x * REGION_SIZE_X
        && game->play->current_region->left != NULL)
            change_region(game, game->play->current_region->left, -1, 0);
    if (player_bounds->left + player_bounds->width / 2
        > (game->play->current_region_pos.x + 1) * REGION_SIZE_X
        && game->play->current_region->right != NULL)
            change_region(game, game->play->current_region->right, 1, 0);
}

bool check_region_bound(game_t *game, sfFloatRect *player_bounds)
{
    return ((player_bounds->top
        < game->play->current_region_pos.y * REGION_SIZE_Y
        && game->play->current_region->top == NULL)
        || (player_bounds->top + player_bounds->height / 2
        > (game->play->current_region_pos.y + 1) * REGION_SIZE_Y
        && game->play->current_region->bottom == NULL)
        || (player_bounds->left
        < game->play->current_region_pos.x * REGION_SIZE_X
        && game->play->current_region->left == NULL)
        || (player_bounds->left + player_bounds->width / 2
        > (game->play->current_region_pos.x + 1) * REGION_SIZE_X
        && game->play->current_region->right == NULL));
}

bool check_player_region_collision(game_t *game, float shift_x, float shift_y)
{
    sfFloatRect player_bounds = sfSprite_getGlobalBounds(
        game->play->player->sprite);
    player_bounds.left += shift_x;
    player_bounds.top += shift_y;

    if (check_region_bound(game, &player_bounds))
        return true;
    for (int y = player_bounds.top; y < player_bounds.height
        + player_bounds.top; ++y)
        if (is_pixel_colliding(game, &player_bounds, y))
            return true;
    move_to_region(game, &player_bounds);
    return false;
}