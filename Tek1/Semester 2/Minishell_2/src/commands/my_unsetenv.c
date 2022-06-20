/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-hugo.eschlimann
** File description:
** my_unsetenv
*/

#include "minishell.h"
#include "lib.h"

void my_unsetenv(mysh_t *mysh, env_t *t_env)
{
    if (mysh->params[1] == NULL) {
        my_printf("%s: Too few arguments.\n", mysh->params[0]);
        return;
    }
    while (t_env != NULL) {
        if (t_env->next != NULL &&
        my_strcmp(t_env->next->key, mysh->params[1]) == 0) {
            t_env->next = t_env->next->next;
            break;
        }
        t_env = t_env->next;
    }
}
