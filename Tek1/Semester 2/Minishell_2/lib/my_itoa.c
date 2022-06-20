/*
** EPITECH PROJECT, 2022
** my_runner
** File description:
** my_itoa
*/

#include "../include/lib.h"

char *my_itoa(int nb)
{
    int	len = my_intlen(nb);
    char *str = malloc(sizeof(char) * (len + 1));

    str[len--] = '\0';
    if (nb == 0) {
        str[0] = 48;
        return str;
    }
    if (nb < 0) {
        str[0] = '-';
        nb *= -1;
    }
    while (nb > 0) {
        str[len] = 48 + (nb % 10);
        nb = nb / 10, len--;
    }
    return str;
}
