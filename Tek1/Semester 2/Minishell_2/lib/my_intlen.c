/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** my_intlen
*/

#include "../include/lib.h"

int my_intlen(int nb)
{
    int i;
    int count;

    for (i = 10, count = 0; ; i *= 10, count++) {
        if (nb / i == 0)
            break;
    }
    return count + 1;
}
