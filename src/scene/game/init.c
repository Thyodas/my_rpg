/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** init.c
*/

#include "rpg.h"
#include "object.h"
#include "my.h"

void init_all_maps(game_t *game);
particles_emitter_t *init_emitter(void);
object_t *create_player_object(option_t option);
object_t *init_clock_text(game_t *game);

void init_game(game_t *game)
{
    game->play = malloc(sizeof(play_t));
    game->play->view = NULL;
    init_all_maps(game);
    init_all_regions(game);
    game->scene[GAME_SCENE] = malloc(sizeof(scene_t));
    game->scene[GAME_SCENE]->nb_buttons = 0;
    game->scene[GAME_SCENE]->obj = NULL;
    game->scene[GAME_SCENE]->emitter = init_emitter();
    game->scene[GAME_SCENE]->texture_background_saved = NULL;
}

void init_scene_objects(game_t *game)
{
    option_t option = {
        "./assets/spritesheets/character.png",
        (sfVector2f){1.0, 1.0}, (sfVector2f){200, 170},
        (sfIntRect){0, 0, 16, 16}, 16, 16, 96, 96,};
    game->play->player = create_player_object(option);
    my_put_in_list(&game->scene[GAME_SCENE]->obj, game->play->player);
    my_put_in_list(&game->scene[GAME_SCENE]->obj, init_clock_text(game));
}
