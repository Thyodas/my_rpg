/*
** EPITECH PROJECT, 2021
** B-CPE-200-STG-2-1-dante-selim-han.kirac
** File description:
** main.c
*/

#include "my.h"
#include "rpg.h"

void init_data(game_t *data);

void init_game(game_t *game);
void init_start_menu(game_t *game);
void start_menu(game_t *game);
void game(game_t *game);

void (* const scene[])(game_t *game) = {
        &start_menu,
        &game,
};

static void start_game(game_t *game)
{
    init_start_menu(game);
    init_game(game);
    while (sfRenderWindow_isOpen(game->window))
        scene[game->current_scene](game);
}

static void error_handler(int argc, char **argv)
{
    // TODO check si y'a pas d'entré
}

int main(int argc, char **argv)
{
    game_t game;

    if (argc != 1) {
        my_put_err("Usage : ./my_rpg\n");
        return (84);
    }
    init_data(&game);
    start_game(&game);
    return (0);
}
