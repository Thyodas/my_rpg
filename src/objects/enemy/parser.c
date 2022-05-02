/*
** EPITECH PROJECT, 2022
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** parser
*/

#include <stdio.h>
#include "my.h"
#include "game.h"
#include "region.h"
#include "object.h"
#include "mylist.h"

enemy_t create_enemy(sfVector2i *pos, option_t option, stats_t stats);
void enemy_handler(game_t *game, object_t *self);
void draw_enemy(game_t *game, object_t *self);
stats_t skeleton_stats(void);
stats_t slime_stats(void);


static option_t get_option(char **argv, int id)
{
    option_t option;
    char *paths[2] = {SLIME_PATH, SKELETON_PATH};
    option.path = paths[id];
    return option;
}

static sfVector2i *get_pos(char **arg)
{
    sfVector2i *pos = malloc(sizeof(sfVector2i) * 2);

    pos[0] = (sfVector2i){my_getnbr(arg[1]), my_getnbr(arg[2])};
    pos[1] = (sfVector2i){my_getnbr(arg[3]), my_getnbr(arg[4])};
    return pos;
}

//[ID], [POSX1], [POSY1], [POSX2], [POSY2]
void parse_enemy(game_t *game, region_t *region, char **argv)
{
    stats_t (stats_enemy[2]) = {&slime_stats, &skeleton_stats};
    int argc = 0;
    for (; argv[argc] != NULL; ++argc);
    if (argc != 5)
        return;
    int id = my_getnbr(argv[0]);
    if (id < 0 || id >= ENEMY_NB)
        return;
    enemy_t enemy = create_enemy(get_pos(argv), get_option(argv, id),
                                                        stats_enemy[id]);
    object_t *object = create_object(ENEMY_OBJ, enemy,
                                                &enemy_handler, &draw_enemy);
    my_put_in_list(&region->objects, object);
}
