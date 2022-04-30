/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_player
*/

#include "rpg.h"
#include "object.h"
#include "my.h"

player_t *create_player(option_t option)
{
    player_t *player = malloc(sizeof(player_t));
    entity_t entity;

    entity.sprite = sfSprite_create();
    entity.texture =
        sfTexture_createFromFile(option.path, NULL);
    entity.spritesheet_width = option.spritesheet_width;
    entity.spritesheet_height = option.spritesheet_height;
    player->speed = 150;
    player->health = 20;
    sfSprite_setTexture(entity.sprite, entity.texture, sfTrue);
    sfSprite_setScale(entity.sprite, option.scale);
    sfSprite_setPosition(entity.sprite, option.pos);
    if (option.int_rect.width != -1) {
        entity.rect = option.int_rect;
        sfSprite_setTextureRect(entity.sprite, option.int_rect);
    }
    entity.spritesheet_rect_x = 16;
    entity.spritesheet_rect_y = 16;
    player->entity = entity;
    return (player);
}
