/*
** EPITECH PROJECT, 2022
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** create
*/

#include "rpg.h"
#include "object.h"
#include "region.h"

static void init_enemy_entity(enemy_t *enemy, option_t option)
{
    enemy->entity.texture = sfTexture_createFromFile(option.path, NULL);
    enemy->entity.sprite = sfSprite_create();
    enemy->entity.spritesheet_width = option.spritesheet_width;
    enemy->entity.spritesheet_height = option.spritesheet_height;
    sfSprite_setTexture(enemy->entity.sprite, enemy->entity.texture, sfTrue);
    sfSprite_setScale(enemy->entity.sprite, option.scale);
    sfSprite_setOrigin(enemy->entity.sprite, (sfVector2f){option.rect_x / 2,
        option.rect_y / 2});
    sfSprite_setPosition(enemy->entity.sprite, enemy->pos[0]);
    if (option.int_rect.width != -1) {
        enemy->entity.rect = option.int_rect;
        sfSprite_setTextureRect(enemy->entity.sprite, option.int_rect);
    }
    
    enemy->entity.spritesheet_rect_x = 16;
    enemy->entity.spritesheet_rect_y = 16;
}

enemy_t *create_enemy(sfVector2f *pos, option_t option, stats_t *stats)
{
    enemy_t *enemy = malloc(sizeof(enemy_t));
    enemy->self_pos = pos[0];
    enemy->pos = pos;
    enemy->where_to_go = 1;
    init_enemy_entity(enemy, option);
    enemy->stats = stats;
    enemy->last_breathing_animation = 0;
    enemy->last_move_animation = 0;
    enemy->last_breath_out_animation = 0;
    enemy->breath_state = 1;
    return enemy;
}
