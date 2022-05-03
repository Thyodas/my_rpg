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
    sfFloatRect rect = sfSprite_getLocalBounds(part);
    sfSprite_setOrigin(part, (sfVector2f){rect.width / 2, rect.height / 2});
    sfSprite_setRotation(part, rotation);
    //sfSprite_setOrigin(part, (sfVector2f){0, 0});
    return part;
}

void draw_dialogue(game_t *game, struct object_s *self)
{
    dialogue_box_t *dlg = self->data;
    sfVector2f null_vector = {0, 0};
    sfRenderWindow_drawSprite(game->window, modify_part(
        dlg->box_parts[DLG_BOX_INDICATOR], dlg->pos, (sfVector2f){1, 1}, 90),
        NULL);
    sfText_setPosition(dlg->text, dlg->pos);
    sfRenderWindow_drawText(game->window, dlg->text, NULL);
}
