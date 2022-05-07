/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** player_handler
*/

#include "rpg.h"
#include <stdio.h>

bool check_entity_region_collision(game_t *game, sfVector2f shift,
                                    entity_t entity, int is_player);
void player_movement_animation(game_t *game);
void player_idle_animation(game_t *game);
void rect_set_y(game_t *game, int status);
void player_movement_animation(game_t *game);

void move_player(game_t *game, player_t *player, float shift_x, float shift_y)
{
    if (check_entity_region_collision(game, (sfVector2f){shift_x, shift_y},
                            ((player_t *)(game->play->player->data))->entity,
                            1))
        return;
    sfSprite_move(player->entity.sprite, (sfVector2f){shift_x, shift_y});
    player_movement_animation(game);
}

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
        rect_set_y(game, 1);
        move_player(game, game->play->player->data, -new_speed, 0);
    }
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        rect_set_y(game, 3);
        move_player(game, game->play->player->data, 0, -new_speed);
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        rect_set_y(game, 0);
        move_player(game, game->play->player->data, new_speed, 0);
    }
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        rect_set_y(game, 2);
        move_player(game, game->play->player->data, 0, new_speed);
    }
    if (sfKeyboard_isKeyPressed(sfKeyE)) {
        interact_player(game);
    }
    if (CAST_PLAYER(game->play->player->data)->entity.animation_state
        == IDLE_STATE)
        player_idle_animation(game);
    last_clock_us = sfClock_getElapsedTime(game->clock->clock).microseconds;
}

void set_player_animation_settings(game_t *game, int status) {
    player_t *player = CAST_PLAYER(game->play->player->data);
    inventory_t *inventory = &player->inventory;
    item_t *item = inventory->items[inventory->selected_item]->data;
    sfSprite *sprite = item->entity->sprite;

    player->orientation = status;
    if (status == 0)
        sfSprite_setRotation(sprite, 90.0);
    if (status == 1)
        sfSprite_setRotation(sprite, 270.0);
    if (status == 2)
        sfSprite_setRotation(sprite, 180.0);
    if (status == 3)
        sfSprite_setRotation(sprite, 0.0);
}

void rect_set_y(game_t *game, int status)
{
    entity_t *entity = &CAST_PLAYER(game->play->player->data)->entity;

    set_player_animation_settings(game, status);
    if (entity->spritesheet_rect_y != 0)
        entity->rect.top = entity->spritesheet_rect_y * status;
    if (entity->rect.top >= entity->spritesheet_height)
        entity->rect.top = 0;
    sfSprite_setTextureRect(entity->sprite, entity->rect);
}
