/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_player
*/

#include "rpg.h"
#include "my.h"

void update_texts(game_t *game)
{
    sfText_setString(
        CAST_PLAYER(game->play->player->data)->inventory.health_text,
        my_int_to_strnum(CAST_PLAYER(game->play->player->data)->health));
    sfText_setString(
        CAST_PLAYER(game->play->player->data)->inventory.attack_text,
        my_int_to_strnum(CAST_PLAYER(game->play->player->data)->attack));
}

void init_texts(game_t *game)
{
    inventory_t *inventory = &CAST_PLAYER(game->play->player->data)->inventory;

    sfVector2f pos = {1185.0, 400.0};
    sfVector2f pos_two = {690.0, 400.0};

    inventory->attack_text = sfText_create();
    sfText_setFont(inventory->attack_text, game->data.retro_font);
    sfText_setScale(inventory->attack_text, (sfVector2f){1.2, 1.2});
    sfText_setFillColor(inventory->attack_text, sfWhite);
    sfText_setPosition(inventory->attack_text, pos);
    sfText_setString(inventory->attack_text, "20");
    inventory->health_text = sfText_create();
    sfText_setFont(inventory->health_text, game->data.retro_font);
    sfText_setScale(inventory->health_text, (sfVector2f){1.2, 1.2});
    sfText_setFillColor(inventory->health_text, sfWhite);
    sfText_setPosition(inventory->health_text, pos_two);
    sfText_setString(inventory->health_text, "20");
}
