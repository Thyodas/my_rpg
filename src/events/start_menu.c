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
    if (entity->spritesheet_rect != 0)
        entity->rect.left += entity->spritesheet_rect;
    if (entity->rect.left >= 72)
        entity->rect.left = 0;
    sfSprite_setTextureRect(entity->sprite, entity->rect);
}

void rect_list_animation(game_t *game, linked_list_t **list)
{
    linked_list_t *element = *list;

    while (element) {
        rect_animation(game, element->data);
        if (element->next == NULL)
            break;
        element = element->next;
    }
}

void start_menu_animate_sprites(game_t *game)
{
    // Sprite animation every 0.25 seconds
    game->clock->time = sfClock_getElapsedTime(game->clock->clock);
    game->clock->seconds = game->clock->time.microseconds / 1000000.0;
    if (game->clock->seconds >= 0.5) {
        rect_list_animation(game, game->start_menu->waves);
        sfClock_restart(game->clock->clock);
    } else
        return;
}

void start_menu_events_handler(game_t *game, sfEvent event)
{
    // Replace cursor by custom cursor
    check_mouse_movement(game, event);
}
