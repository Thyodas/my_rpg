/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** settings_menu.c
*/

#include "rpg.h"
#include "settings.h"
#include <stdio.h>
#include "my.h"

particles_emitter_t *init_emitter(void);
void parse_button(game_t *game, char **args, int start_btn, int end_btn);
char **cut_str(char *str, char *delim);

static void (* const PARSE_OBJ_SCENE[])(game_t *, char **, int, int) = {
    NULL,
    &parse_button
};


static void parse_objects_settings_menu(game_t *game)
{
    char *line = NULL;
    char **args = NULL;
    size_t size = 0;
    int object_id = -1;
    FILE *fp = fopen("data/scene/settings.scene", "r");

    if (fp == NULL)
        return;
    while (getline(&line, &size, fp) != -1) {
        args = cut_str(line, " ");
        if (args == NULL || args[0] == NULL || !my_str_isnum(args[0]))
            continue;
        object_id = my_getnbr(args[0]);
        if (object_id < 0 || object_id >= OBJECT_NB)
            continue;
        PARSE_OBJ_SCENE[object_id](game, args, BTN_VOLUME_MUSIC, NB_BUTTONS);
    }
    fclose(fp);
    free(line);
}

void init_settings_menu(game_t *game)
{
    game->settings_menu = malloc(sizeof(settings_scene_t));
    game->settings_menu->obj = NULL;
    game->settings_menu->emitter = init_emitter();
    parse_objects_settings_menu(game);
}