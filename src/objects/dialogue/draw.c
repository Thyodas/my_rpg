/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** draw_start.c
*/

#include "game.h"
#include "object.h"
#include "dialogue.h"

static sfSprite *modify_part(sfSprite *part, sfVector2f pos, sfVector2f scale,
float rotation)
{
    sfSprite_setScale(part, scale);
    sfSprite_setPosition(part, pos);
    sfSprite_setRotation(part, rotation);
    return part;
}

static void draw_top_and_right(game_t *game, dialogue_box_t *dlg,
sfFloatRect *rect)
{
    sfVector2f one = {1, 1};
    sfRenderWindow_drawSprite(game->window, modify_part(dlg->box_parts
        [DLG_BOX_CORNER], (sfVector2f){rect->left - 2, rect->top - 2}, one, 0),
        NULL);
    sfRenderWindow_drawSprite(game->window, modify_part(dlg->box_parts
        [DLG_BOX_BORDER], (sfVector2f){rect->left, rect->top - 2},
        (sfVector2f){rect->width, 1}, 0), NULL);
    sfRenderWindow_drawSprite(game->window, modify_part(dlg->box_parts
        [DLG_BOX_CORNER], (sfVector2f){rect->left + rect->width + 2,
        rect->top - 2}, one, 90), NULL);
    sfRenderWindow_drawSprite(game->window, modify_part(dlg->box_parts
        [DLG_BOX_BORDER], (sfVector2f){rect->left + rect->width + 2,
        rect->top}, (sfVector2f){rect->height, 1}, 90), NULL);
}

static void draw_bottom_and_left(game_t *game, dialogue_box_t *dlg,
sfFloatRect *rect)
{
    sfVector2f one = {1, 1};
    sfRenderWindow_drawSprite(game->window, modify_part(dlg->box_parts
        [DLG_BOX_CORNER], (sfVector2f){rect->left + rect->width + 2,
        rect->top + rect->height + 2}, one, 180), NULL);
    sfRenderWindow_drawSprite(game->window, modify_part(dlg->box_parts
        [DLG_BOX_BORDER], (sfVector2f){rect->left + rect->width, rect->top
        + rect->height + 2}, (sfVector2f){rect->width, 1}, 180), NULL);
    sfRenderWindow_drawSprite(game->window, modify_part(dlg->box_parts
        [DLG_BOX_CORNER], (sfVector2f){rect->left - 2,
        rect->top + rect->height + 2}, one, 270), NULL);
    sfRenderWindow_drawSprite(game->window, modify_part(dlg->box_parts
        [DLG_BOX_BORDER], (sfVector2f){rect->left - 2,
        rect->top + rect->height}, (sfVector2f){rect->height, 1}, 270), NULL);
}

static void draw_text_and_background_and_indicator(game_t *game,
dialogue_box_t *dlg, sfFloatRect *rect)
{
    sfRenderWindow_drawSprite(game->window, modify_part(
        dlg->box_parts[DLG_BOX_INDICATOR], dlg->pos, (sfVector2f){1, 1}, 0),
        NULL);
    sfRenderWindow_drawSprite(game->window, modify_part(
        dlg->box_parts[DLG_BOX_BACKGROUND], (sfVector2f){rect->left, rect->top},
        (sfVector2f){rect->width, rect->height}, 0), NULL);
    sfRenderWindow_drawText(game->window, dlg->text, NULL);
}

void draw_dialogue(game_t *game, struct object_s *self)
{
    dialogue_box_t *dlg = self->data;
    sfFloatRect rect = sfText_getGlobalBounds(dlg->text);
    sfText_setPosition(dlg->text, (sfVector2f){dlg->pos.x - rect.width / 2,
        dlg->pos.y - rect.height - 6});
    rect = sfText_getGlobalBounds(dlg->text);
    draw_top_and_right(game, dlg, &rect);
    draw_bottom_and_left(game, dlg, &rect);
    draw_text_and_background_and_indicator(game, dlg, &rect);
}
