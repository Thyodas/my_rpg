/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** start_menu.c
*/

#include "rpg.h"
#include "object.h"
#include <stdio.h>
#include "my.h"

particles_emitter_t *init_emitter(void);
char **cut_str(char *str, char *delim);
void parse_button(game_t *game, char **args, int nb_buttons);

static void (* const PARSE_OBJ_SCENE[])(game_t *, char **, int) = {
    NULL,
    &parse_button
};

static void parse_objects_start_menu(game_t *game)
{
    char *line = NULL;
    char **args = NULL;
    size_t size = 0;
    int object_id = -1;
    FILE *fp = fopen("data/start_menu/start_menu.scene", "r");

    if (fp == NULL)
        return;
    while (getline(&line, &size, fp) != -1) {
        args = cut_str(line, " ");
        if (args == NULL || args[0] == NULL || !my_str_isnum(args[0]))
            continue;
        object_id = my_getnbr(args[0]);
        if (object_id < 0 || object_id >= OBJECT_NB)
            continue;
        PARSE_OBJ_SCENE[object_id](game, args, NB_BUTTONS_START);
    }
    fclose(fp);
    free(line);
}

void init_start_menu(game_t *game)
{
    game->clock = init_clock();
    game->start_menu = malloc(sizeof(start_menu_t));
    game->start_menu->objects = NULL;
    game->start_menu->emitter = init_emitter();
    parse_objects_start_menu(game);
}