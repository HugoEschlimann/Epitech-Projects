/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-minishell2-hugo.eschlimann
** File description:
** pipe
*/

#include "lib.h"
#include "minishell.h"

void pipe_1(mysh_t *mysh, env_t *env)
{
    pid_t child = fork();
    int status = 0;

    if (child == 0)
        pipe_redirection(mysh, env);
    else
        waitpid(child, &status, WUNTRACED);
}

void pipe_redirection(mysh_t *mysh, env_t *env)
{
    int fd[2];
    char **tmp = NULL;
    char **arr = my_str_to_word_array(mysh->line, "|");
    pid_t pid = 0;

    pipe(fd);
    pid = fork();
    if (pid == 0) {
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        tmp = my_str_to_word_array(arr[0], " ");
        if (parsing_path(mysh->path, tmp[0], mysh) == 1)
            execve(mysh->real_path, tmp, my_env_to_array(&env));
    } else {
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        tmp = my_str_to_word_array(arr[1], " ");
        if (parsing_path(mysh->path, tmp[0], mysh) == 1)
            execve(mysh->real_path, tmp, my_env_to_array(&env));
    }
}
