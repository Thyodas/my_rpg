/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** rpg
*/

#ifndef RPG_H_
    #define RPG_H_

    #include <stdlib.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>
    #include <time.h>
    #include "mylist.h"

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

    typedef struct my_time_s {
        sfTime time;
        float seconds;
        sfClock *clock;
        float prev_time;
    } my_time_t;

    typedef struct option_s {
        char *path;
        sfVector2f scale;
        sfVector2f pos;
        sfIntRect int_rect;
        int rect;
    } option_t;

    typedef struct entity_s {
        sfSprite *sprite;
        sfTexture *texture;
        sfIntRect rect;
        int spritesheet_rect; // Décalage d'image sur spritesheet par pixel (spritesheet horizontal)
    } entity_t;

    typedef struct cursor_s {
        sfTexture *texture;
        sfSprite *sprite;
        sfIntRect rect;
        sfVector2f pos;
    } cursor_t;

    typedef struct start_menu_s {
        linked_list_t **waves;
        entity_t *new_game;
        entity_t *play;
        entity_t *exit;
        entity_t *help; // TODO when clicked -> help_clicked = 1;
        int help_clicked; // TODO 1 ? draw help_menu : remove from screen;
        entity_t *help_menu; // TODO design help menu;
        particles_emitter_t *emitter;
    } start_menu_t;

    typedef struct game_s {
        int current_scene;
        sfRenderWindow *window;
        my_time_t *clock;
        cursor_t *cursor;
        start_menu_t *start_menu;
    } game_t;

    my_time_t *init_clock(void);

    /* Drawing */
    void draw_list_entity(game_t *game, linked_list_t **list);
    void draw_entity(game_t *game, entity_t *entity);

    /* Init */
    entity_t *init_entity(option_t option);

    /* Interactions */
    int is_hit(entity_t *entity, cursor_t *cursor,
                                                float width, float height);

#endif /* !RPG_H_ */
