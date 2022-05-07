/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** draw.c
*/

#include "rpg.h"

sfVector2f get_position_interaction(player_t *player, int status);

void draw_interaction(game_t *game, int status)
{
    player_t *player = CAST_PLAYER(game->play->player->data);
    inventory_t *inventory = &player->inventory;
    item_t *item = inventory->items[inventory->nb_items]->data;

    sfSprite_setPosition(item->entity->sprite,
                         get_position_interaction(player,
                                                    player->orientation));
    sfSprite_setScale(item->entity->sprite, (sfVector2f){0.8, 0.8});
    draw_entity(game, item->entity);
}

void draw_player(game_t *game)
{
    entity_t *player = &((player_t *)(game->play->player->data))->entity;
    if (player->animation_state == INTERACTION_STATE)
        draw_interaction(game, player->animation_state);
    sfRenderWindow_drawSprite(game->window, player->sprite, NULL);
    if (!game->debug_mode)
        return;
    static sfRectangleShape *shape = NULL;
    if (shape == NULL) {
        shape = sfRectangleShape_create();
        sfRectangleShape_setFillColor(shape, (sfColor){61, 70, 242, 100});
        sfRectangleShape_setOutlineColor(shape, (sfColor){61, 70, 242, 200});
    }
    sfFloatRect rect = sfSprite_getGlobalBounds(player->sprite);
    sfRectangleShape_setSize(shape, (sfVector2f){rect.width,
        rect.height});
    sfRectangleShape_setPosition(shape, (sfVector2f){rect.left,
        rect.top});
    sfRenderWindow_drawRectangleShape(game->window, shape, NULL);
}
