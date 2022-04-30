/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** button.c
*/

#include "rpg.h"

button_t *init_button(char *path_sprite, sfVector2f pos_btn,
                    void (*ptr_btn)(game_t *), int id)
{
    button_t *button = malloc(sizeof(button_t));
    sfTexture *texture = sfTexture_createFromFile(path_sprite, NULL);

    button->state = IDLE;
    button->id_btn = id;
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, texture, sfFalse);
    sfSprite_setScale(button->sprite, (sfVector2f){5.0, 5.0});
    sfSprite_setPosition(button->sprite, (sfVector2f){pos_btn.x, pos_btn.y});
    button->on_click = ptr_btn;
    return button;
}