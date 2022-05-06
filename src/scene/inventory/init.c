/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** init.c
*/

#include "rpg.h"

particles_emitter_t *init_emitter(void);
void parse_objects_scene(game_t *game, int scene, char *path);;
object_t *init_inventory_ui_object(game_t *game);

void init_inventory_menu(game_t *game)
{
    game->scene[INVENTORY_SCENE] = malloc(sizeof(scene_t));
    game->scene[INVENTORY_SCENE]->obj = NULL;
    game->scene[INVENTORY_SCENE]->emitter = init_emitter();
    game->scene[INVENTORY_SCENE]->nb_buttons = 0;
    game->scene[INVENTORY_SCENE]->texture_background_saved = NULL;
    parse_objects_scene(game, INVENTORY_SCENE, "data/scene/inventory.scene");
    my_put_in_list(&game->scene[INVENTORY_SCENE]->obj,
        init_inventory_ui_object(game));
}
