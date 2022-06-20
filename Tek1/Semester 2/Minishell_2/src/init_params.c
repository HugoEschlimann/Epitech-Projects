/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-hugo.eschlimann
** File description:
** init_params
*/

#include "minishell.h"

mysh_t init_params(char **env)
{
    mysh_t mysh;

    mysh.line = NULL;
    mysh.real_path = NULL;
    mysh.len = 0;
    mysh.path = find_command_path(create_linked_list(env));
    mysh.node = create_linked_list(env);
    mysh.env_line = NULL;
    return mysh;
}
