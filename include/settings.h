/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** settings.h
*/

#ifndef SETTINGS_H
    #define SETTINGS_H

    #include "particles.h"

    typedef struct settings {
        int volume_music;
        int general_volume;
    } settings_t;

    typedef struct settings_scene {
        linked_list_t *obj;
        particles_emitter_t *emitter;
    } settings_scene_t;

#endif