/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** button
*/

#include "rpg.h"

button_t *init_button(char *path, sfVector2f pos,
                        sfIntRect rect)
{
    button_t *button = malloc(sizeof(button_t));

    button->sprite = sfSprite_create();
    button->texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(button->sprite, button->texture, sfTrue);
    sfSprite_setPosition(button->sprite, pos);
    if (rect.width != -1) {
        button->rect = rect;
        sfSprite_setTextureRect(button->sprite, rect);
    }
    return (button);
}
