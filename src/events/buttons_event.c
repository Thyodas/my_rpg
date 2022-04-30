/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** buttons_event.c
*/

#include "rpg.h"
#include "object.h"

void handle_button_event(game_t *game, object_t *button)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    sfFloatRect rect_text =
        sfSprite_getGlobalBounds(CAST_BUTTON(button->data)->sprite);
    sfBool contained = sfFloatRect_contains(&rect_text, mouse_pos.x, mouse_pos.y);

    if (contained == sfTrue && sfMouse_isButtonPressed(sfMouseLeft)) {
        CAST_BUTTON(button->data)->state = CLICKED;
        CAST_BUTTON(button->data)->on_click(game);
    } else if (contained == sfTrue)
        CAST_BUTTON(button->data)->state = HOVERED;
    else
        CAST_BUTTON(button->data)->state = IDLE;
}
