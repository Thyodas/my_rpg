/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** player_handler
*/

#include "rpg.h"
#include <stdio.h>

bool check_player_region_collision(game_t *game, float shift_x, float shift_y);
void player_movement_animation(game_t *game);

void move_player(game_t *game, player_t *player, float shift_x, float shift_y)
{
    if (check_player_region_collision(game, shift_x, shift_y))
        return;
    sfSprite_move(player->entity.sprite, (sfVector2f){shift_x, shift_y});
    player_movement_animation(game);
}

void rect_set_y(game_t *game, entity_t *entity, int status)
{
    if (entity->spritesheet_rect_y != 0)
        entity->rect.top = entity->spritesheet_rect_y * status;
    if (entity->rect.top >= entity->spritesheet_height)
        entity->rect.top = 0;
    sfSprite_setTextureRect(entity->sprite, entity->rect);
}

void rect_animation_movement(game_t *game, entity_t *entity)
{
    if (entity->rect.left < 32)
        entity->rect.left = 32;
    if (entity->spritesheet_rect_x != 0)
        entity->rect.left += entity->spritesheet_rect_x;
    if (entity->rect.left >= entity->spritesheet_width)
        entity->rect.left = 32;
    sfSprite_setTextureRect(entity->sprite, entity->rect);
}

void rect_animation_idle(game_t *game, entity_t *entity)
{
    if (entity->spritesheet_rect_x != 0)
        entity->rect.left += entity->spritesheet_rect_x;
    if (entity->rect.left >= 32)
        entity->rect.left = 0;
    sfSprite_setTextureRect(entity->sprite, entity->rect);
}
