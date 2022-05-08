/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** events_handler.c
*/

#include "rpg.h"
#include "my.h"

void check_mouse_movement(game_t *game);
void set_game_scene(game_t *game);
object_t *create_object(enum id_object_type id, void *data, void (*handler)(),
void (*draw)());
void exit_game(game_t *game);

void events_handler_inventory_scene(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            exit_game(game);
        check_mouse_movement(game);
        if (game->event.type == sfEvtKeyReleased &&
            (game->event.key.code == sfKeyI ||
                game->event.key.code == sfKeyEscape))
            set_game_scene(game);
    }
}

void draw_inventory_ui_object(game_t *game, object_t *self)
{
    sfSprite *sprite = self->data;
    sfRenderWindow_drawSprite(game->window, sprite, NULL);
}

void handler_inventory_ui_object(game_t *game, object_t *self)
{
    return;
}

object_t *init_inventory_ui_object(game_t *game)
{
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite,
        sfTexture_createFromFile("assets/images/inventory_ui.png", NULL), sfFalse);
    return create_object(BACKGROUND_UI_OBJ, sprite,
                    &handler_inventory_ui_object, &draw_inventory_ui_object);
}
