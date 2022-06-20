/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-minishell2-hugo.eschlimann
** File description:
** checker
*/

#include "lib.h"
#include "minishell.h"

bool checker(mysh_t *mysh)
{
    for (int i = 0; mysh->line[i] != '\0'; i++) {
        if (mysh->line[i] == ';' || mysh->line[i] == '|' ||
        mysh->line[i] == '<' || mysh->line[i] == '>') {
            return true;
        }
    }
    return false;
}
