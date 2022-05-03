/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** dialogue
*/

#ifndef DIALOGUE_H_
    #define DIALOGUE_H_

    #include <SFML/Graphics.h>
    #include <SFML/System.h>

    /*enum {
        DLG_TL_CORNER,
        DLG_TR_CORNER,
        DLG_BR_CORNER,
        DLG_BL_CORNER,
        DLG_TOP_BORDER,
        DLG_RIGHT_BORDER,
        DLG_BOTTOM_BORDER,
        DLG_LEFT_BORDER,
        DLG_BACKGROUND,
        DLG_INDICATOR, // arrow above NPC's head
        DLG_BOX_PART_NB
    };*/

    enum {
        DLG_BOX_CORNER,
        DLG_BOX_BORDER,
        DLG_BOX_BACKGROUND,
        DLG_BOX_INDICATOR,  // arrow above NPC's head
        DLG_BOX_PART_NB
    };

    typedef struct {
        sfSprite *box_parts[DLG_BOX_PART_NB];
        sfText *text;
        char *content;
        sfVector2f pos;
    } dialogue_box_t;

    #define DLG_BOX_PATH "assets/spritesheets/dialogue.png"

#endif /* !DIALOGUE_H_ */
