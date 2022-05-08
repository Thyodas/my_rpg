/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** reset_game.c
*/

#include "rpg.h"

void set_game_scene(game_t *game);
void load_region(game_t *game, region_t *region);

void reset_game(game_t *game)
{
    for (int i = 0; i < REGION_NB; ++i) {
        game->play->region_list[i]->is_loaded = 0;
        game->play->region_list[i]->objects = NULL;
    }
    CAST_PLAYER(game->play->player->data)->emitters = NULL;
    CAST_PLAYER(game->play->player->data)->health = 3;
    sfSprite_setPosition(CAST_PLAYER(game->play->player->data)->entity.sprite,
        (sfVector2f){REGION_SIZE_X * game->play->current_region_pos.x +
        240, REGION_SIZE_Y * game->play->current_region_pos.y + 130});
    game->play->current_region = game->play->start_region;
    load_region(game, game->play->current_region);
    if (game->current_scene == DEATH_SCENE)
        set_game_scene(game);
}