/*
** EPITECH PROJECT, 2022
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** restart_clock
*/

int restart_clock(my_time_t *clock)
{
    clock->seconds = 0;
    
    clock->time = sfClock_restart(clock->clock);
    return (0);
}
