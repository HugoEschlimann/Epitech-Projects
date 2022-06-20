/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-minishell2-hugo.eschlimann
** File description:
** clear_string
*/

#include "../include/lib.h"

char *clear_string(char *str)
{
    if (str[0] == ' ') {
        str++;
        return str;
    }
    return str;
}
