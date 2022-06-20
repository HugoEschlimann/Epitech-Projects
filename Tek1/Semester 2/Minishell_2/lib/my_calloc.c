/*
** EPITECH PROJECT, 2022
** minishell
** File description:
** my_calloc
*/

#include "../include/lib.h"

char *my_calloc(char *str, size_t size)
{
    str = malloc(sizeof(char) * (size + 1));
    size_t i = 0;

    if (!str)
        return NULL;
    for (; i != size; i++)
        str[i] = '0';
    str[i] = '\0';
    return str;
}
