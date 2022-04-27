/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-guillaume.hein
** File description:
** utils_particles.c
*/

#include "rpg.h"

float gen_random_in_range(float lower, float upper)
{
    float random = ((float)rand()) / (float)RAND_MAX;
    float diff = upper - lower;
    float r = random * diff;
    return lower + r;
}
