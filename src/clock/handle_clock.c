/*
** EPITECH PROJECT, 2022
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** restart_clock
*/

#include <stddef.h>
#include <stddef.h>
#include "game.h"
#include "my.h"

#define FONT_PATH "assets/fonts/retro.ttf"
int my_put_in_list(struct linked_list **list, void *data);
object_t *create_object(enum id_object_type id, void *data, void (*handler)(),
void (*draw)());

void draw_clock_text(game_t *game, object_t *self)
{
    sfText *clock_txt = self->data;
    sfRenderWindow_drawText(game->window, clock_txt, NULL);
}

void handler_clock_text(game_t *game, object_t *self)
{
    sfText *clock_txt = self->data;
    sfText_setPosition(clock_txt, (sfVector2f){10, 282});
    sfText_setString(clock_txt, my_int_to_strnum((int)game->clock->seconds));
}

object_t *init_clock_text(game_t *game)
{
    sfText *clock_txt = sfText_create();
    object_t *object = NULL;

    sfText_setFont(clock_txt, game->data.retro_font);
    sfText_setPosition(clock_txt, (sfVector2f){10, 282});
    sfText_setScale(clock_txt, (sfVector2f){0.5, 0.5});
    sfText_setColor(clock_txt, sfRed);
    sfText_setString(clock_txt, "60");
    object = create_object(CLOCK_OBJ, clock_txt,
                                        &handler_clock_text, &draw_clock_text);
    return object;
}

int restart_clock(my_time_t *clock)
{
    clock->seconds = 0;
    clock->time = sfClock_restart(clock->clock);
    return 0;
}
