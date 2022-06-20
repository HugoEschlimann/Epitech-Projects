/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** my_put_nbr
*/

#include "../include/lib.h"

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    } else
        my_putchar(nb + '0');
    return 0;
}
