/*
** EPITECH PROJECT, 2021
** Day08 Task01
** File description:
** Allocates memeory and copies string given as argument in it
*/

#include "../include/lib.h"

char *my_strdup(char const *src)
{
    int i = 0;
    char *bd = NULL;

    if (!src)
        return NULL;
    bd = malloc(sizeof(char) * (my_strlen(src) + 1));
    for (;src[i] != '\0'; i++)
        bd[i] = src[i];
    bd[i] = '\0';
    return bd;
}
