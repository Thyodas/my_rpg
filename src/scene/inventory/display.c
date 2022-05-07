/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** display.c
*/

#include "rpg.h"
#include "my.h"

void draw_scene(game_t *game);
void handle_object(game_t *game);
void draw_cursor(sfRenderWindow *window, cursor_t *cursor);
void events_handler_inventory_scene(game_t *game);
void update_texts(game_t *game);

static void draw_background(game_t *game)
{
    sfSprite *sprite_background = sfSprite_create();

    sfSprite_setTexture(sprite_background,
                        game->scene[INVENTORY_SCENE]->texture_background_saved,
                        sfFalse);
    sfRenderWindow_drawSprite(game->window, sprite_background, NULL);
}

static void draw_stats(game_t *game)
{
    inventory_t *inventory = &((player_t *)(game->play->player->data))->inventory;

    update_texts(game);
    sfRenderWindow_drawText(game->window, inventory->attack_text, NULL);
    sfRenderWindow_drawText(game->window, inventory->health_text, NULL);
}

static void draw_items(game_t *game)
{
    object_t *object = NULL;
    item_t *item = NULL;
    sfVector2f pos = {700, 680};

    for (int i = 0; i < INVENTORY_SIZE; i++) {
        item = CAST_PLAYER(game->play->player->data)->inventory.items[i]->data;
        if (item != NULL) {
            sfSprite_setScale(item->entity->sprite, (sfVector2f){3.0, 3.0});
            sfSprite_setPosition(item->entity->sprite, pos);
            draw_entity(game, item->entity);
        }
        pos.x += 38.0 * 3.0 + 22.5;
        if (i == INVENTORY_SIZE / 2 - 1) {
            pos.y += 45.0 * 3.0 + 10.0;
            pos.x = 700;
        }
    }
}

void draw_following_item(game_t *game)
{
    cursor_t *cursor = game->cursor;
    if (cursor->item_selected_index == -1)
        return;
    sfVector2f pos = cursor->pos;
    item_t *item = CAST_PLAYER(game->play->player->data)->inventory.items[cursor->item_selected_index]->data;
    sfSprite_setPosition(item->entity->sprite, pos);
    draw_entity(game, item->entity);
}

void inventory_menu(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    events_handler_inventory_scene(game);
    handle_object(game);
    if (game->current_scene != INVENTORY_SCENE)
        return;
    draw_background(game);
    draw_scene(game);
    draw_items(game);
    draw_stats(game);
    draw_cursor(game->window, game->cursor);
    draw_following_item(game);
    sfRenderWindow_display(game->window);
}
