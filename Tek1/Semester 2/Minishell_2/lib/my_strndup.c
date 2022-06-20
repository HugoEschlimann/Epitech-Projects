/*
** EPITECH PROJECT, 2022
** minishell
** File description:
** my_strndup
*/

#include "../include/lib.h"

char *my_strndup(char *str, int nb)
{
    char *new = malloc(sizeof(char) * (nb + 1));
    int i = 0;

    if (!str || !new)
        return NULL;
    for (; i < nb; i++)
        new[i] = str[i];
    new[i] = '\0';
    return new;
}
