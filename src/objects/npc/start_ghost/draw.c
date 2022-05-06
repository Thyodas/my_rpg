/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** draw.c
*/

#include "rpg.h"
#include "npc.h"
#include "my.h"

void draw_dialogue_box(game_t *game, dialogue_box_t *dlg);

void draw_npc_start_ghost(game_t *game, object_t *self)
{
    npc_t *npc = CAST_NPC(self->data);
    sfRenderWindow_drawSprite(game->window, npc->entity.sprite, NULL);
    draw_dialogue_box(game, npc->dialogue);
    if (!game->debug_mode)
        return;
    static sfRectangleShape *shape = NULL;
    if (shape == NULL) {
        shape = sfRectangleShape_create();
        sfRectangleShape_setFillColor(shape, (sfColor){61, 70, 242, 100});
        sfRectangleShape_setOutlineColor(shape, (sfColor){61, 70, 242, 200});
    }
    sfFloatRect rect = sfSprite_getGlobalBounds(npc->entity.sprite);
    sfRectangleShape_setSize(shape, (sfVector2f){rect.width,
        rect.height});
    sfRectangleShape_setPosition(shape, (sfVector2f){rect.left,
        rect.top});
    sfRenderWindow_drawRectangleShape(game->window, shape, NULL);
}
