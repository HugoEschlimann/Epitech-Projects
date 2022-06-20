/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-minishell2-hugo.eschlimann
** File description:
** mini_clear_string
*/

#include "../include/lib.h"
#include "../include/minishell.h"

char *mini_clear(char *str)
{
    int i = 0;
    char *new_str = malloc(sizeof(char) * 100 + 1);

    if (str[0] == ' ')
        i++;
    for (int j = 0; str[i]; i++) {
        if (str[i] == ' ' && str[i + 1] == '\0')
            break;
        new_str[j] = str[i];
        j++;
    }
    new_str[100] = '\0';
    return new_str;
}
