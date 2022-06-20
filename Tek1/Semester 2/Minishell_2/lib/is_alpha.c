/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-hugo.eschlimann
** File description:
** is_alpha
*/

#include "../include/lib.h"

int is_alpha(char c)
{
    if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
        return 0;
    return 1;
}
