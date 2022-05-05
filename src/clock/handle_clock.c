/*
** EPITECH PROJECT, 2022
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** restart_clock
*/

#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/System/Vector2.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/PrimitiveType.h>
#include <SFML/Graphics/RenderStates.h>
#include <SFML/Graphics/Vertex.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/VideoMode.h>
#include <SFML/Window/WindowHandle.h>
#include <SFML/Window/Window.h>
#include <SFML/System/Vector2.h>
#include <stddef.h>
#include <stddef.h>
#include "game.h"
#include "my.h"

#define FONT_PATH "assets/fonts/retro.ttf"

sfText *init_clock_text(void)
{
    sfText *clock_txt = sfText_create();

    sfText_setFont(clock_txt, sfFont_createFromFile(FONT_PATH));
    sfText_setPosition(clock_txt, (sfVector2f){10, 10});
    sfText_setScale(clock_txt, (sfVector2f){1, 1});
    sfText_setColor(clock_txt, sfBlack);
    sfText_setString(clock_txt, "60");
    return clock_txt;
}

//TODO call update_clock_text
void handle_clock_text(game_t *game, my_time_t *clock)
{
    sfText_setString(clock->clock_txt, my_int_to_strnum((int)clock->seconds));
    sfRenderWindow_drawText(game->window, clock->clock_txt, NULL);
}

int restart_clock(my_time_t *clock)
{
    clock->seconds = 0;
    clock->time = sfClock_restart(clock->clock);
    return 0;
}
