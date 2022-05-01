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

static stats_t skeleton_stats(void)
{
    stats_t stats;

    stats.damage = 2;
    stats.life_points = 2;
    return stats;
}

static stats_t slime_stats(void)
{
    stats_t stats;

    stats.damage = 1;
    stats.life_points = 1;
    return stats;
}
//[ID], [POSX1], [POSY1], [POSX2], [POSY2]
void parse_enemy(game_t *game, char **argv)
{
    stats_t (*stats_enemy[2]) = {&slime_stats, &skeleton_stats};
    int argc = 0;
    for (; argv[argc] != NULL; ++argc);
    if (argc != 6)
        return;
    int region_id = my_getnbr(argv[0]);
    if (region_id < 0 || region_id >= REGION_NB)
        return;
    enemy_t *enemy = create_enemy((sfVector2i *){(sfVector2i){my_getnbr(argv[1]), my_getnbr(argv[2])}, (sfVector2i){my_getnbr(argv[3]), my_getnbr(argv[4])}}, (stats_enemy)(my_getnbr(argv[0])));
    object_t *object = create_object(ENEMY_OBJ, enemy,
        &enemy_handler, &draw_enemy);
    my_put_in_list(&region->objects, object);
}
