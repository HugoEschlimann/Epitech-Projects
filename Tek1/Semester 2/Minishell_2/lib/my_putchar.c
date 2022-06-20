/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** my_putchar
*/

#include "../include/lib.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
