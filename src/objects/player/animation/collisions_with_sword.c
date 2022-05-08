/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** collisions_with_sword.c
*/

#include "rpg.h"

int handle_enemies_collisions(object_t *obj, entity_t *entity, game_t *game);

void collisions_with_sword(game_t *game, object_t *obj, item_t *sword)
{
    player_t *player = CAST_PLAYER(game->play->player->data);
    if (obj->id == ENEMY_OBJ && handle_enemies_collisions(obj, sword->entity,
            game) && !CAST_ENEMY(obj->data)->is_hit) {
            hit_enemy(CAST_ENEMY(obj->data), player->attack, game);
            set_pos_hit(player, CAST_ENEMY(obj->data)->self_pos);
            sword->hit_effect = 1;
    }
    if (obj->id == GRASS_OBJ && handle_enemies_collisions(obj,
        sword->entity, game) && !((grass_t *)obj->data)->is_hit &&
        !((grass_t *)obj->data)->destroyed)
            ((grass_t *)obj->data)->is_hit = 1;
}

