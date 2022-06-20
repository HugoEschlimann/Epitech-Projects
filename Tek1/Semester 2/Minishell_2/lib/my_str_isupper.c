/*
** EPITECH PROJECT, 2021
** Lib
** File description:
** isupper
*/

#include "../include/lib.h"

int my_str_isupper(char const *str)
{
    if (!str)
        return -1;
    for (int i = 0; str[i] != '\0';) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            i++;
        else
            return 0;
    }
    return 1;
}
