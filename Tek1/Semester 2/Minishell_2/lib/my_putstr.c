/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** my_putstr
*/

#include "../include/lib.h"

int my_putstr(char const *str)
{
    if (!str)
        return -1;
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
    return 0;
}
