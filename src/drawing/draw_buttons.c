/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** draw_buttons.c
*/

#include "rpg.h"
#include "object.h"

static float offset[NB_BUTTONS_START] = {
    0.0, 0.0, 0.0
};

static sfRenderStates create_state_button(float translate, object_t *obj)
{
    sfRenderStates state;
    state.texture = NULL;
    state.blendMode = sfBlendNone;
    state.transform = sfTransform_Identity;
    if (CAST_BUTTON(obj->data)->id_btn < 2)
        sfTransform_translate(&state.transform, translate, 0);
    if (CAST_BUTTON(obj->data)->id_btn == 2)
        sfTransform_translate(&state.transform, 0, translate);
    state.shader = NULL;
    return state;
}

void draw_buttons(game_t *game, object_t *button)
{
    sfRenderStates state =
        create_state_button(offset[CAST_BUTTON(button->data)->id_btn], button);

    if (CAST_BUTTON(button->data)->state == IDLE) {
        if (offset[CAST_BUTTON(button->data)->id_btn] != 0)
            offset[CAST_BUTTON(button->data)->id_btn]--;
        sfRenderWindow_drawSprite(game->window,
                                CAST_BUTTON(button->data)->sprite, &state);
    } else if (CAST_BUTTON(button->data)->state == HOVERED) {
        if (offset[CAST_BUTTON(button->data)->id_btn] < 25)
            offset[CAST_BUTTON(button->data)->id_btn]++;
        sfRenderWindow_drawSprite(game->window,
                                CAST_BUTTON(button->data)->sprite, &state);
    }
}