/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** handler
*/

#include "rpg.h"
#include <stdio.h>

bool check_player_region_collision(game_t *game, float shift_x, float shift_y);
void player_movement_animation(game_t *game);

void rect_animation_movement(entity_t *entity)
{
    if (entity->rect.left < 32)
        entity->rect.left = 32;
    if (entity->spritesheet_rect_x != 0)
        entity->rect.left += entity->spritesheet_rect_x;
    if (entity->rect.left >= entity->spritesheet_width)
        entity->rect.left = 32;
    sfSprite_setTextureRect(entity->sprite, entity->rect);
}

void rect_animation_interaction(game_t *game, entity_t *entity)
{
    if (entity->rect.left >= entity->spritesheet_width - entity->spritesheet_rect_x) {
        entity->rect.left = 0;
        CAST_PLAYER(game->play->player->data)->entity.animation_state
                = IDLE_STATE;
    }
    entity->rect.left = entity->spritesheet_width - entity->spritesheet_rect_x;
    sfSprite_setTextureRect(entity->sprite, entity->rect);
}

void rect_animation_idle(entity_t *entity)
{
    if (entity->spritesheet_rect_x != 0)
        entity->rect.left += entity->spritesheet_rect_x;
    if (entity->rect.left >= 32)
        entity->rect.left = 0;
    sfSprite_setTextureRect(entity->sprite, entity->rect);
}

void move_player(game_t *game, player_t *player, float shift_x, float shift_y)
{
    if (check_player_region_collision(game, shift_x, shift_y))
        return;
    sfSprite_move(player->entity.sprite, (sfVector2f){shift_x, shift_y});
    player_movement_animation(game);
}

void interact_player(game_t *game)
{
    static long last_clock_us = 0;
    long current_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
    double diff = (current_us - last_clock_us) / 1000000.0;

    CAST_PLAYER(game->play->player->data)->entity.animation_state
            = INTERACTION_STATE;
    if (diff >= 0.2) {
        rect_animation_interaction(game,
                    &((player_t *)(game->play->player->data))->entity);
        last_clock_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
    }
}

void rect_set_y(entity_t *entity, int status)
{
    if (entity->spritesheet_rect_y != 0)
        entity->rect.top = entity->spritesheet_rect_y * status;
    if (entity->rect.top >= entity->spritesheet_height)
        entity->rect.top = 0;
    sfSprite_setTextureRect(entity->sprite, entity->rect);
}
