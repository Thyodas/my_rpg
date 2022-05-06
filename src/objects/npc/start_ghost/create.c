/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_player
*/

#include "rpg.h"
#include "object.h"
#include "npc.h"
#include "my.h"
#include "dialogue.h"

dialogue_box_t *create_dialogue_data(game_t *game);
void draw_npc_start_ghost(game_t *game, object_t *self);
void npc_start_ghost_handler(game_t *game, object_t *self);

static void init_npc_start_ghost_entity(npc_t *npc, entity_t *entity)
{
    entity->sprite = sfSprite_create();
    entity->texture = sfTexture_createFromFile(GHOST_PATH, NULL);
    entity->rect = (sfIntRect){0, 0, 20, 18};
    sfSprite_setTexture(entity->sprite, entity->texture, sfTrue);
    sfSprite_setPosition(entity->sprite, npc->start_pos);
    sfSprite_setTextureRect(entity->sprite, entity->rect);
    sfSprite_setOrigin(entity->sprite, (sfVector2f){entity->rect.width / 2,
        entity->rect.height / 2});
    entity->animation_state = IDLE_STATE;
    entity->spritesheet_rect_x = 20;
    entity->spritesheet_rect_y = 18;
    entity->spritesheet_width = 80;
    entity->spritesheet_height = 36;
}

static void init_npc_start_ghost_dialogue(npc_t *npc, dialogue_box_t *dialogue)
{
    dialogue->pos.x = npc->start_pos.x;
    dialogue->pos.y = npc->start_pos.y - npc->entity.spritesheet_rect_y;
    dialogue->content = "Hello world!.... bzzz \n... Hey";
    dialogue->content_stripped = my_strdup(dialogue->content);
    dialogue->max_index = my_strlen(dialogue->content);
    dialogue->delay = 0.2;
}

void create_npc_start_ghost(game_t *game, object_t *self)
{
    npc_t *npc = self->data;
    npc->dialogue = create_dialogue_data(game);
    init_npc_start_ghost_entity(npc, &npc->entity);
    init_npc_start_ghost_dialogue(npc, npc->dialogue);
    self->draw = &draw_npc_start_ghost;
    self->handler = &npc_start_ghost_handler;
    return;
}
