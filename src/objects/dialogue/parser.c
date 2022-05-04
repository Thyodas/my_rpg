/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** parser.c
*/

#include "rpg.h"
#include "object.h"
#include "my.h"
#include "dialogue.h"

dialogue_box_t *create_dialogue_data(game_t *game);
void dialogue_handler(game_t *game, struct object_s *self);
void draw_dialogue(game_t *game, struct object_s *self);
object_t *create_object(enum id_object_type id, void *data, void (*handler)(),
void (*draw)());

char *replace_char_by_char(char *str, char c1, char c2)
{
    for (int i = 0; str[i] != '\0'; ++i)
        if (str[i] == c1)
            str[i] = c2;
    return str;
}

void parse_dialogue_box(game_t *game, region_t *region, char **argv)
{
    int argc = 0;
    for (; argv[argc] != NULL; ++argc);
    if (argc != 3)
        return;
    dialogue_box_t *dialogue = create_dialogue_data(game);
    dialogue->pos.x = my_getnbr(argv[0]);
    dialogue->pos.y = my_getnbr(argv[1]);
    dialogue->content = my_strdup(argv[2]);
    object_t *object = create_object(DIALOGUE_OBJ, dialogue,
        &dialogue_handler, &draw_dialogue);
    sfText_setString(dialogue->text,
        replace_char_by_char(dialogue->content, '|', '\n'));
    my_put_in_list(&region->objects, object);
}
