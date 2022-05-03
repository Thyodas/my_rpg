/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** parser.c
*/

#include "rpg.h"
#include "object.h"
#include "my.h"

void exit_game(game_t *game);
void set_game_scene(game_t *game);
void set_settings_scene(game_t *game);
void set_menu_scene(game_t *game);
button_t *init_button(char *path_sprite, sfVector2f pos_btn,
                    void (*ptr_btn)(game_t *), int id);
void draw_buttons_start(game_t *game, object_t *button);
void handle_button_event_start(game_t *game, object_t *button);
object_t *create_object(enum id_object_type id, void *data, void (*handler)(),
void (*draw)());

static void (*ptr_btn[])(game_t *) = {
    &set_game_scene,
    &exit_game,
    &exit_game,
    &set_settings_scene,
    &exit_game,
    &exit_game,
    &exit_game,
    &set_menu_scene,
    &exit_game,
};

static void (*ptr_handler[])(game_t *, object_t *) = {
    &handle_button_event_start,
    NULL,
    &handle_button_event_start
};

static void (*ptr_draw[])(game_t *, object_t *) = {
    &draw_buttons_start,
    NULL,
    &draw_buttons_start
};

void parse_button(game_t *game, char **args, int id, int scene)
{
    int argc = 0;
    int btn_id = -1;
    int ptr = -1;

    for(; args[argc] != NULL; ++argc);
    if (argc != NB_ARGS_BUTTON)
        return;
    btn_id = my_getnbr(args[1]);
    ptr = my_getnbr(args[5]);
    if (btn_id < 0 || btn_id >= game->scene[scene]->nb_buttons || ptr < 0 ||
        ptr > NB_BUTTONS)
        return;
    button_t *button = init_button(args[2],
                                    (sfVector2f){(float)my_getnbr(args[3]),
                                    (float)my_getnbr(args[4])},
                                    ptr_btn[ptr], btn_id);
    if (button == NULL)
        return;
    object_t *object = create_object(BUTTON_OBJ, button,
            ptr_handler[scene], ptr_draw[scene]);
    my_put_in_list(&game->scene[scene]->obj, object);
}