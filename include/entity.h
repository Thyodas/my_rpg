/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** entity
*/

#ifndef ENTITY_H_
    #define ENTITY_H_

    #include "mylist.h"

    typedef struct entity_s {
        sfSprite *sprite;
        sfTexture **textures;
        sfTexture *texture;
        sfIntRect rect;
        int health;
        int textures_amount;
        int spritesheet_rect; // Décalage d'image sur spritesheet par pixel (spritesheet horizontal)
        int spritesheet_width; // total image width (in pixels)
    } entity_t;

#endif /* !ENTITY_H_ */