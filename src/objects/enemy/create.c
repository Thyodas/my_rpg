/*
** EPITECH PROJECT, 2022
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** create
*/

#include "rpg.h"
#include "object.h"
#include "region.h"

static entity_t init_enemy_entity(option_t *option)
{
    entity_t entity;

    entity.texture = sfTexture_createFromFile(option->path, NULL);
    entity.sprite = sfSprite_create();
    entity.spritesheet_width = option->spritesheet_width;
    entity.spritesheet_height = option->spritesheet_height;
    sfSprite_setTexture(entity.sprite, entity.texture, sfTrue);
    sfSprite_setScale(entity.sprite, option->scale);
    sfSprite_setPosition(entity.sprite, option->pos);
    if (option->int_rect.width != -1) {
        entity.rect = option->int_rect;
        sfSprite_setTextureRect(entity.sprite, option->int_rect);
    }
    entity.spritesheet_rect_x = 16;
    entity.spritesheet_rect_y = 16;
    return entity;
}

enemy_t create_enemy(sfVector2i *pos, option_t *option, stats_t *stats)
{
    enemy_t enemy;
    enemy.pos1 = pos[0];
    enemy.pos2 = pos[1];
    enemy.entity = init_enemy_entity(option);
    enemy.stats = stats;
    return enemy;
}
