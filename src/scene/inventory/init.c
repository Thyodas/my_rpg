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

const static sfIntRect rect[INVENTORY_SIZE] = {
        {644,  612, 506, 78},
        {780,  612, 506, 78},
        {918,  612, 506, 78},
        {1024, 612, 506, 78},
        {1194, 612, 506, 78},
        {644,  758, 506, 78},
        {780,  758, 506, 78},
        {918,  758, 506, 78},
        {1024, 758, 506, 78},
        {1194, 758, 506, 78},
};

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

void drag_drop_interaction(game_t *game, inventory_t *inventory)
{
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        int check = game->cursor->pos.x >= rect[i].left &&
                    game->cursor->pos.x <= rect[i].left + rect[i].width;
        int check_two = game->cursor->pos.y >= rect[i].top &&
                        game->cursor->pos.y <= rect[i].top + rect[i].height;
        if (!check || !check_two || inventory->items[i] == NULL)
            return;
    }
}
