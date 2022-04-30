/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** start_menu.c
*/

#include "rpg.h"
#include "object.h"

void exit_game(game_t *game);
void set_game_scene(game_t *game);
button_t *init_button(char *path_sprite, sfVector2f pos_btn,
                    void (*ptr_btn)(game_t *), int id);
object_t *create_object(enum id_object_type id, void *data, void (*handler)(),
                        void (*draw)());
void handle_button_event(game_t *game, object_t *button);
void draw_buttons(game_t *game, object_t *button);
particles_emitter_t *init_emitter(void);

static char *paths_button[3] = {
    "assets/images/new_game.png", "assets/images/exit.png",
    "assets/images/help.png"
};

static sfVector2f pos_buttons[3] = {
    (sfVector2f){800.0, 350.0},
    (sfVector2f){800.0, 650.0},
    (sfVector2f){1800.0, 35.0}
};

static void (*ptr_btn[3])(game_t *) = {
    &set_game_scene,
    &exit_game,
    NULL
};

void init_start_menu(game_t *game)
{
    game->clock = init_clock();
    game->start_menu = malloc(sizeof(start_menu_t));
    game->start_menu->objects = NULL;
    for (int i = 0; i < NB_BUTTONS_START; ++i) {
        button_t *button = init_button(paths_button[i], pos_buttons[i],
                                        ptr_btn[i], i);
        object_t *new_button = create_object(BUTTON_OBJ, button,
                                &handle_button_event, &draw_buttons);
        my_put_in_list(&game->start_menu->objects, new_button);
    }
    game->start_menu->emitter = init_emitter();
}