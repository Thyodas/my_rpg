/*
** EPITECH PROJECT, 2021
** my_delete_nodes
** File description:
** my_delete_nodes
*/

#include "../../../include/mylist.h"

int my_delete_nodes(linked_list_t **begin , void const *data_ref, int (*cmp)())
{
    struct linked_list * actual = *begin;

    while (actual != NULL) {
        if (actual != NULL & (*cmp)((actual)->data, data_ref) == 0) {
            *begin = NULL;
        }
        actual = actual->next;
    }
    return (0);
}
