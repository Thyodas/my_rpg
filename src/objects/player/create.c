/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_player
*/

#include "rpg.h"
#include "object.h"
#include "my.h"

object_t *create_player_object(option_t option)
{
    player_t *player = malloc(sizeof(player_t));
    object_t *object = malloc(sizeof(object_t));
    entity_t entity;
    entity.sprite = sfSprite_create();
    entity.texture = sfTexture_createFromFile(option.path, NULL);
    entity.spritesheet_width = option.spritesheet_width;
    entity.spritesheet_height = option.spritesheet_height;
    player->speed = 150;
    player->health = 20;
    sfSprite_setTexture(entity.sprite, entity.texture, sfTrue);
    sfSprite_setScale(entity.sprite, option.scale);
    sfSprite_setPosition(entity.sprite, option.pos);
    entity.rect = option.int_rect;
    sfSprite_setTextureRect(entity.sprite, entity.rect);
    entity.spritesheet_rect_x = 16;
    entity.spritesheet_rect_y = 16;
    player->entity = entity;
    object->data = player;
    player->entity.animation_state = IDLE_STATE;
    return (object);
}
