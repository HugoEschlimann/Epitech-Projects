/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-hugo.eschlimann
** File description:
** n_word
*/

#include "../include/lib.h"

int check_non_alpha(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (' ' < str[i] && str[i] < '0')
            return 0;
    }
    return 1;
}
