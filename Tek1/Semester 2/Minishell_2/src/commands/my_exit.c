/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-hugo.eschlimann
** File description:
** my_exit
*/

#include "minishell.h"
#include "lib.h"

void my_exit(mysh_t *mysh)
{
    if (mysh->params[1] != NULL && str_isalpha(mysh->params[1]) == 0) {
        my_printf("%s: Expression Syntax.\n", mysh->params[0]);
    } else if (mysh->params[1] != NULL && str_isnum(mysh->params[1]) == 0)
        my_printf("%s: Badly formed number.\n", mysh->params[0]);
    else {
        my_printf("exit\n");
        exit(0);
    }
}
