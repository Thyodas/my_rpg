/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** region
*/

#ifndef REGION_H_
    #define REGION_H_

    #include "entity.h"
    #include "mylist.h"

    typedef struct regions_s {
        int x;
        int y;
        entity_t *background;
        entity_t *foreground;
        entity_t *collision;
    } region_t;

#endif /* !REGION_H_ */
