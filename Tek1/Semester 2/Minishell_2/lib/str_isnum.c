/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-hugo.eschlimann
** File description:
** str_isnum
*/

#include "../include/lib.h"

int str_isnum(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ('0' <= str[i] && str[i] <= '9')
            return 0;
    }
    return 1;
}
