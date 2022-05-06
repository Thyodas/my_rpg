/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** handler
*/

#include "rpg.h"

void init_texts(game_t *game);

void set_inventory_data(game_t *game, void *data, int n)
{
    player_t *player = ((player_t *)(game->play->player->data));

    player->inventory.items[n]->data = data;
}

void append_inventory_data(game_t *game, void *data)
{
    player_t *player = ((player_t *)(game->play->player->data));

    set_inventory_data(game, data, player->inventory.nb_items++);
}

item_t *get_inventory_data(game_t *game, int n)
{
    player_t *player = ((player_t *)(game->play->player->data));

    if (player->inventory.items[n]->data == NULL)
        return (NULL);
    return player->inventory.items[n]->data;
}

void init_inventory(game_t *game)
{
    option_t option = {
            "./assets/spritesheets/items.png",
            (sfVector2f) {1.2, 1.2},
            (sfVector2f){69.5, 488.0},
            (sfIntRect) {2, 16, 10, 16},
            15.6666666667,
            17.6666666667,
            47,
            53,
            180.0,
            "Sword"
    };
    init_texts(game);
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        ((player_t *)(game->play->player->data))->inventory.items[i] = malloc(sizeof(object_t));
        ((player_t *)(game->play->player->data))->inventory.items[i]->data = NULL;
    }
    ((player_t *)(game->play->player->data))->inventory.nb_items = 0;
    ((player_t *)(game->play->player->data))->inventory.selected_item = 0;
    set_inventory_data(game, create_items_object(option, 0), 0);
}
