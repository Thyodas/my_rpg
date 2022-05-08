/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** attack.c
*/

#include "rpg.h"

void rect_set_y(game_t *game, int status);
void interact_player(game_t *game);
int handle_enemies_collisions(object_t *obj, entity_t *entity, game_t *game);
void hit_enemy(enemy_t *enemy, int attack, game_t *game);
void set_pos_hit(game_t *game, sfVector2f pos);
item_t *get_selected_item(game_t *game);

static void handle_items_collisions(game_t *game, player_t *player)
{
    linked_list_t *tmp = game->play->current_region->objects;
    object_t *obj;
    item_t *item_entity = get_selected_item(game);

    if (item_entity == NULL)
        return;
    while (tmp != NULL) {
        obj = tmp->data;
        if (obj->id == ENEMY_OBJ &&
            handle_enemies_collisions(obj, item_entity->entity, game) &&
            !CAST_ENEMY(obj->data)->is_hit) {
                hit_enemy(CAST_ENEMY(obj->data), player->attack, game);
                set_pos_hit(game, CAST_ENEMY(obj->data)->self_pos);
                item_entity->hit_effect = 1;
            }
        tmp = tmp->next;
    }
}

static void attack_animation(game_t *game, player_t *player)
{
    if (sfKeyboard_isKeyPressed(sfKeyRight) && !player->hit_delay) {
        rect_set_y(game, RIGHT);
        interact_player(game);
        player->hit_delay = 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft) && !player->hit_delay) {
        rect_set_y(game, LEFT);
        interact_player(game);
        player->hit_delay = 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown) && !player->hit_delay) {
        rect_set_y(game, DOWN);
        interact_player(game);
        player->hit_delay = 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp) && !player->hit_delay) {
        rect_set_y(game, UP);
        interact_player(game);
        player->hit_delay = 1;
    }
}

void player_attack(game_t *game, player_t *player)
{
    if (player->hit_delay) {
        interact_player(game);
        handle_items_collisions(game, player);
        return;
    }
    attack_animation(game, player);
    if (player->hit_delay)
        handle_items_collisions(game, player);
}