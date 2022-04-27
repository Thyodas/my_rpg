/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** option
*/

#ifndef OPTION_H_
    #define OPTION_H_

    #include <SFML/Graphics.h>

    typedef struct option_s {
        char *path;
        sfVector2f scale;
        sfVector2f pos;
        sfIntRect int_rect;
        int rect;
        int spritesheet_width;
    } option_t;

#endif /* !OPTION_H_ */
