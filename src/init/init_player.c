/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_player
*/

#include "rpg.h"
#include "my.h"

int set_text_from_textures(entity_t *entity, int n)
{
    if (entity->textures == NULL && entity->textures_amount == 0) {
        my_put_err("[ERROR] - There is no textures");
        return 84;
    }
    if (n < 0 && n < entity->textures_amount)
        return 84;
    sfSprite_setTexture(entity->sprite, entity->textures[n], sfFalse);
    return 0;
}

entity_t *init_player(option_t option)
{
    entity_t *entity = malloc(sizeof(entity_t));

    entity->sprite = sfSprite_create();
    entity->textures = malloc(sizeof(sfTexture *) * 5);
    entity->textures[0] =
    sfTexture_createFromFile("./assets/spritesheets/player_left.png", NULL);
    entity->textures[1] =
    sfTexture_createFromFile("./assets/spritesheets/player_up.png", NULL);
    entity->textures[2] =
    sfTexture_createFromFile("./assets/spritesheets/player_right.png", NULL);
    entity->textures[3] =
    sfTexture_createFromFile("./assets/spritesheets/player_down.png", NULL);
    entity->textures[4] = NULL;

    entity->textures_amount = 4;
    entity->spritesheet_width = 71;
    entity->speed = 500;
    sfSprite_setTexture(entity->sprite, entity->textures[0], sfTrue);
    sfSprite_setScale(entity->sprite, option.scale);
    sfSprite_setPosition(entity->sprite, option.pos);
    if (option.int_rect.width != -1) {
        entity->rect = option.int_rect;
        sfSprite_setTextureRect(entity->sprite, option.int_rect);
    }
    entity->spritesheet_rect = option.rect;
    return (entity);
}
