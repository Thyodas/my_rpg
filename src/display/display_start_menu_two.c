/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** start_menu
*/

#include "rpg.h"
#include "stdio.h"

static void init_waves_start_menu_two(game_t *game, option_t option)
{
    my_put_in_list(game->start_menu->waves, init_entity(option));
    option.pos = (sfVector2f){1600.0, 250.0};
    my_put_in_list(game->start_menu->waves, init_entity(option));
}

void init_waves_start_menu(game_t *game, option_t option)
{
    game->start_menu->waves = malloc(sizeof(linked_list_t));
    *(game->start_menu->waves) = NULL;

    my_put_in_list(game->start_menu->waves, init_entity(option));
    option.pos = (sfVector2f){300.0, 150.0};
    my_put_in_list(game->start_menu->waves, init_entity(option));
    option.pos = (sfVector2f){90.0, 50.0};
    my_put_in_list(game->start_menu->waves, init_entity(option));
    option.pos = (sfVector2f){1000.0, 400.0};
    my_put_in_list(game->start_menu->waves, init_entity(option));
    option.pos = (sfVector2f){1650.0, 750.0};
    my_put_in_list(game->start_menu->waves, init_entity(option));
    option.pos = (sfVector2f){900.0, 800.0};
    init_waves_start_menu_two(game, option);
}
