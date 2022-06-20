/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-hugo.eschlimann
** File description:
** str_non_alpha
*/

#include "../include/lib.h"

int str_non_alpha(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str_isalpha(str) == 1 && str_isnum(str) == 1)
            return 0;
    }
    return 1;
}
