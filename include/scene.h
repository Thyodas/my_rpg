/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** scene.h
*/

#ifndef SCENE_H
    #define SCENE_H

    #include "particles.h"
    #include "mylist.h"
    #include "object.h"

    enum scenes {
        START_SCENE,
        GAME_SCENE,
        SETTINGS_SCENE,
        NB_SCENE
    };

    typedef struct scene {
        linked_list_t *obj;
        int nb_buttons;
        particles_emitter_t *emitter;
    } scene_t;

#endif