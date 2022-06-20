/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-hugo.eschlimann
** File description:
** is_non_alpha
*/

#include "../include/lib.h"

int is_non_alpha(char c)
{
    if (is_alpha(c) == 1 && is_num(c) == 1)
        return 0;
    return 1;
}
