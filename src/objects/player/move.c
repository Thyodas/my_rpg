/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** move.c
*/

#include "rpg.h"

void player_movement_animation(game_t *game);
bool check_entity_region_collision(game_t *game, sfVector2f shift,
                                    entity_t entity, int is_player);
particles_emitter_t *init_emitter(void);
sfVector2f get_pos_player(game_t *game);

static int handle_enemies_collisions(object_t *obj, player_t *player,
                                    game_t *game)
{
    sfFloatRect rect_player = sfSprite_getGlobalBounds(player->entity.sprite);
    if (obj->id == ENEMY_OBJ) {
        enemy_t *enemy = obj->data;
        sfFloatRect rect_enemy =
            sfSprite_getGlobalBounds(enemy->entity.sprite);
        if (sfFloatRect_intersects(&rect_player, &rect_enemy, NULL)) {
            player->health = (player->is_hit) ? player->health :
                                                player->health - 1;
            player->is_hit = 1;
            particles_emitter_t *emitter = init_emitter();
            emitter->pos = get_pos_player(game);
            my_put_in_list(&player->emitters, emitter);
            return 1;
        }
    }
    return 0;
}

static int handle_collisions(game_t *game, player_t *player, sfVector2f shift)
{
    if (check_entity_region_collision(game, shift,
                            ((player_t *)(game->play->player->data))->entity,
                            1))
        return 1;
    if (player->is_hit)
        return 0;
    linked_list_t *tmp = game->play->current_region->objects;
    while (tmp != NULL) {
        object_t *obj = tmp->data;
        if (handle_enemies_collisions(obj, player, game))
            return 1;
        tmp = tmp->next;
    }
    return 0;
}

void move_player(game_t *game, player_t *player, float shift_x, float shift_y)
{
    if (handle_collisions(game, player, (sfVector2f){shift_x, shift_y}))
        return;
    sfSprite_move(player->entity.sprite, (sfVector2f){shift_x, shift_y});
    player_movement_animation(game);
}