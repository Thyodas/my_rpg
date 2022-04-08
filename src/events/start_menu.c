/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** start_menu
*/

#include "rpg.h"

void check_mouse_movement(game_t *game, sfEvent event);

void rect_animation(game_t *game, entity_t *entity)
{
    if (entity->spritesheet_rect != NULL)
        entity->rect.left += entity->spritesheet_rect;
    if (entity->rect.left >= 72)
        entity->rect.left = 0;
    sfSprite_setTextureRect(entity->sprite, entity->rect);
}

void start_menu_animate_sprites(game_t *game)
{
    // Sprite animation every 0.25 seconds
    game->clock->time = sfClock_getElapsedTime(game->clock->clock);
    game->clock->seconds = game->clock->time.microseconds / 1000000.0;
    if (game->clock->seconds >= 0.5) {
        rect_animation(game, game->test);
        sfClock_restart(game->clock->clock);
    } else
        return;
}

void start_menu_events_handler(game_t *game, sfEvent event)
{
    // Replace cursor by custom cursor
    check_mouse_movement(game, event);
}
