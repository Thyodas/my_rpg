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

    #include "entity.h"
    #include "time.h"
    #include "ui.h"
    #include "particles.h"
    #include "option.h"
    #include "region.h"
    #include "game.h"

    my_time_t *init_clock(void);

    /* Drawing */
    void draw_list_entity(game_t *game, linked_list_t **list);
    void draw_entity(game_t *game, entity_t *entity);

    /* Init */
    entity_t *init_entity(option_t option);

    /* Interactions */
    int is_hit(entity_t *entity, cursor_t *cursor, float width, float height);

    /* Manipulation */
    sfVector2f move_coords(sfVector2f pos, float x, float y);
    int set_text_from_textures(entity_t *entity, int n);

    /* Animation */
    void check_mouse_movement(game_t *game, sfEvent event);
    void play_animate_sprites(game_t *game);
    void rect_animation(game_t *game, entity_t *entity);
    void rect_list_animation(game_t *game, linked_list_t **list);

#endif /* !RPG_H_ */
