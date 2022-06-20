/*
** EPITECH PROJECT, 2021
** Task0
** File description:
** strupcase
*/

#include "../include/lib.h"

char *my_strupcase(char *str)
{
    if (!str)
        return NULL;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
        else
            str[i] = str[i];
    }
    return str;
}
