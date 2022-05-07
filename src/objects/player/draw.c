/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** draw.c
*/

#include "rpg.h"

sfVector2f getPositionInteraction(player_t *player, int status);

void draw_interaction(game_t *game)
{
    player_t *player = CAST_PLAYER(game->play->player->data);
    inventory_t *inventory = &player->inventory;
    item_t *item = inventory->items[inventory->nb_items]->data;

    if (item == NULL)
        return;
    sfSprite_setPosition(item->entity->sprite,
                getPositionInteraction(player, player->orientation));
    sfSprite_setScale(item->entity->sprite, (sfVector2f){0.8, 0.8});
    draw_entity(game, item->entity);
}

void draw_player(game_t *game)
{
    player_t *player = ((player_t *)(game->play->player->data));
    if (player->entity.animation_state == INTERACTION_STATE || player->interaction)
        draw_interaction(game);
    sfRenderWindow_drawSprite(game->window, player->entity.sprite, NULL);
    if (!game->debug_mode)
        return;
    static sfRectangleShape *shape = NULL;
    if (shape == NULL) {
        shape = sfRectangleShape_create();
        sfRectangleShape_setFillColor(shape, (sfColor){61, 70, 242, 100});
        sfRectangleShape_setOutlineColor(shape, (sfColor){61, 70, 242, 200});
    }
    sfFloatRect rect = sfSprite_getGlobalBounds(player->entity.sprite);
    sfRectangleShape_setSize(shape, (sfVector2f){rect.width,
        rect.height});
    sfRectangleShape_setPosition(shape, (sfVector2f){rect.left,
        rect.top});
    sfRenderWindow_drawRectangleShape(game->window, shape, NULL);
}
