/*
** EPITECH PROJECT, 2021
** Lib
** File description:
** Function that concatenates two strings
*/

#include "../include/lib.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    char *str = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));

    for (int i = 0; i < (my_strlen(dest) + my_strlen(src)); i++)
        str[i] = '\0';

    if (!dest || !src)
        return NULL;
    for (; dest[i] != '\0'; i++)
        str[i] = dest[i];
    for (int j = 0; src[j] != '\0'; j++)
        str[i++] = src[j];
    str[i] = '\0';
    return str;
}
