/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** move.c
*/

#include "rpg.h"

void player_movement_animation(game_t *game);
bool check_entity_region_collision(game_t *game, sfVector2f shift,
                                    entity_t entity, int is_player);

void move_player(game_t *game, player_t *player, float shift_x, float shift_y)
{
    if (check_entity_region_collision(game, (sfVector2f){shift_x, shift_y},
                            ((player_t *)(game->play->player->data))->entity,
                            1))
        return;
    sfSprite_move(player->entity.sprite, (sfVector2f){shift_x, shift_y});
    player_movement_animation(game);
}