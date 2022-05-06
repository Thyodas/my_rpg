/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** calc_dist
*/

#include <math.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>

float calc_distance(sfVector2f point1, sfVector2f point2)
{
    return sqrt(pow(point2.x - point1.x, 2) + pow(point2.y - point1.y, 2));
}
