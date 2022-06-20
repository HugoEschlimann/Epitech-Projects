/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-minishell2-hugo.eschlimann
** File description:
** execute_command
*/

#include "lib.h"
#include "minishell.h"

void execute_command(mysh_t *mysh, env_t *env)
{
    for (int i = 0; mysh->line[i]; i++) {
        if (mysh->line[i] == ';') {
            separator(mysh, env);
            return;
        }
        if (mysh->line[i] == '|') {
            pipe_1(mysh, env);
            return;
        }
        execute_command_2(mysh, env, i);
    }
}

void execute_command_2(mysh_t *mysh, env_t *env, int i)
{
    if (mysh->line[i] == '>' && mysh->line[i + 1] != '>') {
        simple_redirection_right(mysh, env);
        return;
    }
    if (mysh->line[i] == '<' && mysh->line[i + 1] != '<') {
        simple_redirection_left(mysh, env);
        return;
    }
    if (mysh->line[i] == '>' && mysh->line[i + 1] == '>') {
        double_redirection_right(mysh, env);
        return;
    }
}
