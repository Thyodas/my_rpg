/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** audio
*/

#ifndef AUDIO_H_
    #define AUDIO_H_

    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>

    typedef struct {
        sfMusic *music;
        sfSound *jump;
        sfSound *player_death;
    } audio_t;

#endif /* !AUDIO_H_ */
