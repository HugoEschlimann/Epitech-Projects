/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-minishell2-hugo.eschlimann
** File description:
** my_printf
*/

#include "../include/lib.h"

int my_printf(char *str, ...)
{
    va_list ap;
    va_start(ap, str);

    if (!str)
        return -1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '%')
            check_arg(str, ap, i++);
        else
            my_putchar(str[i]);
    }
    va_end(ap);
    return 0;
}

void check_arg(char *str, va_list ap, int i)
{
    if (str[i + 1] == 'd')
        my_put_nbr(va_arg(ap, int));
    if (str[i + 1] == 'c')
        my_putchar((char)va_arg(ap, int));
    if (str[i + 1] == 's')
        my_putstr(va_arg(ap, char *));
}
