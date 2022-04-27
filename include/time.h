/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** time
*/

#ifndef TIME_H_
    #define TIME_H_

    #include <SFML/System.h>

    typedef struct my_time_s {
        sfTime time;
        float seconds;
        sfClock *clock;
        float prev_time;
    } my_time_t;

#endif /* !TIME_H_ */
