/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-hugo.eschlimann
** File description:
** is_num
*/

#include "../include/lib.h"

int is_num(char c)
{
    if ('0' <= c && c <= '9')
        return 0;
    return 1;
}
