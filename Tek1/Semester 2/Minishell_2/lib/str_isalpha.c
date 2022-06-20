/*
** EPITECH PROJECT, 2021
** Lib
** File description:
** isalpha
*/

#include "../include/lib.h"

int str_isalpha(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!(('A' <= str[i] && str[i] <= 'Z') ||
            ('a' <= str[i] && str[i] <= 'z'))) {
            return 1;
        }
    }
    return 0;
}
