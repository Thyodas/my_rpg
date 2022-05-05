/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** player_handler
*/

#include "rpg.h"
#include <stdio.h>

bool check_entity_region_collision(game_t *game, float shift_x, float shift_y, entity_t entity);
void player_movement_animation(game_t *game);
void player_idle_animation(game_t *game);

void move_player(game_t *game, player_t *player, float shift_x, float shift_y)
{
    if (check_entity_region_collision(game, shift_x, shift_y,
                            ((player_t *)(game->play->player->data))->entity))
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

void handler_player(game_t *game)
{
    static long last_clock_us = 0;
    long current_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
    double diff = (current_us - last_clock_us) / 1000000.0;
    player_t *player = ((player_t *)(game->play->player->data));
    double new_speed = ((player_t *)(game->play->player->data))->speed
        * diff;

    CAST_PLAYER(game->play->player->data)->entity.animation_state
        = IDLE_STATE;
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        move_player(game, game->play->player->data, -new_speed, 0);
        rect_set_y(game, &player->entity, 1);
    }
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        rect_set_y(game, &player->entity, 3);
        move_player(game, game->play->player->data, 0, -new_speed);
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        rect_set_y(game, &player->entity, 0);
        move_player(game, game->play->player->data, new_speed, 0);
    }
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        rect_set_y(game, &player->entity, 2);
        move_player(game, game->play->player->data, 0, new_speed);
    }
    if (CAST_PLAYER(game->play->player->data)->entity.animation_state
        == IDLE_STATE)
        player_idle_animation(game);
    last_clock_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
}
