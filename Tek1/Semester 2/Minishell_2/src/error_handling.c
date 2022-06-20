/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-hugo.eschlimann
** File description:
** error_handling
*/

#include "minishell.h"

int error_handling(int ac)
{
    if (ac != 1)
        return 84;
    return 0;
}
