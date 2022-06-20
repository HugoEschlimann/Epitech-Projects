/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** my_strlen
*/

#include "../include/lib.h"

int my_strlen(char const *str)
{
    int i = 0;

    if (!str)
        return -1;
    for (;str[i] != '\0'; i++);
    return i;
}
