/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** display.c
*/

#include "rpg.h"

void event_handler_death_scene(game_t *game);
void handle_object(game_t *game);
void draw_scene(game_t *game);
void draw_cursor(sfRenderWindow *window, cursor_t *cursor);

static void draw_background(game_t *game)
{
    static sfColor color = {255, 255, 255, 255};
    sfSprite *sprite_background = sfSprite_create();

    sfSprite_setTexture(sprite_background,
                game->scene[DEATH_SCENE]->texture_background_saved, sfFalse);
    sfSprite_setColor(sprite_background, color);
    sfRenderWindow_drawSprite(game->window, sprite_background, NULL);
    color.a -= 1;
}

void death_scene(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    event_handler_death_scene(game);
    handle_object(game);
    if (game->current_scene != DEATH_SCENE)
        return;
    draw_background(game);
    draw_scene(game);
    draw_cursor(game->window, game->cursor);
    sfRenderWindow_display(game->window);
}