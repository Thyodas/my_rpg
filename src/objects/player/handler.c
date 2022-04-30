/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** handler
*/

#include "rpg.h"

bool check_player_region_collision(game_t *game, float shift_x, float shift_y);

void move_player(game_t *game, player_t *player, float shift_x, float shift_y)
{
    if (check_player_region_collision(game, shift_x, shift_y))
        return;
    sfSprite_move(player->entity.sprite, (sfVector2f){shift_x, shift_y});
    play_animate_sprites(game);
}
