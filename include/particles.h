/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** particules
*/

#ifndef PARTICULES_H_
    #define PARTICULES_H_

    #include <SFML/Graphics.h>
    #include <SFML/System.h>

    enum enum_part {
        SNOW,
        BLOOD,
        NB_PART
    };

    typedef struct particles {
        sfVertex vertex;
        sfVector2f direction;
        int is_alive;
        int updated;
    } particles_t;

    typedef struct particles_emitter {
        particles_t *particles;
        sfClock *particles_clock;
        int is_gen;
        int nb_particles;
        void (*ptr_part)(struct particles_emitter *, int, sfVector2f,
                        sfRenderWindow *);
    } particles_emitter_t;

#endif /* !PARTICULES_H_ */
