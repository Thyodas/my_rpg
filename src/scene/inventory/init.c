/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** init.c
*/

#include "rpg.h"

particles_emitter_t *init_emitter(void);
void parse_objects_scene(game_t *game, int scene, char *path);
object_t *init_inventory_ui_object(game_t *game);

const static sfIntRect rect[INVENTORY_SIZE] = {
        {644, 612, 80, 80},
        {780, 612, 80, 80},
        {920, 612, 80, 80},
        {1058, 612, 80, 80},
        {1196, 612, 80, 80},
        {644, 758, 80, 80},
        {780, 758, 80, 80},
        {920, 758, 80, 80},
        {1058, 758, 80, 80},
        {1196, 758, 80, 80},
};

void init_inventory_menu(game_t *game)
{
    game->scene[INVENTORY_SCENE] = malloc(sizeof(scene_t));
    game->scene[INVENTORY_SCENE]->obj = NULL;
    game->scene[INVENTORY_SCENE]->emitter = init_emitter();
    game->scene[INVENTORY_SCENE]->nb_buttons = 0;
    game->scene[INVENTORY_SCENE]->texture_background_saved = NULL;
}

void drag_drop_intention(game_t *game, inventory_t *inventory)
{
    object_t *object = NULL;
    int i = 0;

    for (; i < INVENTORY_SIZE; i++) {
        int check = game->cursor->pos.x >= rect[i].left &&
                    game->cursor->pos.x <= rect[i].left + rect[i].width;
        int check_two = game->cursor->pos.y >= rect[i].top &&
                        game->cursor->pos.y <= rect[i].top + rect[i].height;
        if (check && check_two) {
            object = inventory->items[i];
            break;
        }
    }
    if (object == NULL)
        return;
    game->cursor->item_selected_index = i;
}

void drag_drop_deplacement(game_t *game, inventory_t *inventory)
{
    object_t *object = NULL;
    int tmp = 0;
    int i = 0;

    if (game->cursor->item_selected_index == -1)
        return;
    for (; i < INVENTORY_SIZE - 1; i++) {
        int check = game->cursor->pos.x >= rect[i].left &&
                    game->cursor->pos.x <= rect[i].left + rect[i].width;
        int check_two = game->cursor->pos.y >= rect[i].top &&
                        game->cursor->pos.y <= rect[i].top + rect[i].height;
        if (check && check_two) {
            object = inventory->items[i];
            tmp++;
            break;
        }
    }
    if (i == game->cursor->item_selected_index || tmp != 0)
        return;
    if (object == NULL) {
        inventory->items[i] = inventory->items[game->cursor->item_selected_index];
        inventory->items[game->cursor->item_selected_index] = NULL;
    } else {
        object_t *item_temp = inventory->items[game->cursor->item_selected_index];
        inventory->items[game->cursor->item_selected_index] = inventory->items[i];
        inventory->items[i] = item_temp;
    }
    game->cursor->item_selected_index = -1;
}
