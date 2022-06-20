/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-minishell2-hugo.eschlimann
** File description:
** redirection
*/

#include "lib.h"
#include "minishell.h"

void simple_redirection_right(mysh_t *mysh, env_t *env)
{
    char **arr = my_str_to_word_array(mysh->line, ">");
    int fd = open(clear_string(arr[1]), O_CREAT | O_WRONLY | O_TRUNC, 0644);
    char **tmp = NULL;
    pid_t child = 0;

    if (fd == -1) {
        my_printf("%s: No such file or directory.\n", clear_string(arr[1]));
        return;
    }
    child = fork();
    if (child == 0) {
        dup2(fd, STDOUT_FILENO);
        tmp = my_str_to_word_array(arr[0], " ");
        if (parsing_path(mysh->path, tmp[0], mysh) == 1)
            execve(mysh->real_path, tmp, my_env_to_array(&env));
        else
            my_printf("%s: Command not found.\n", tmp[0]);
    } else
        waitpid(child, NULL, WUNTRACED);
    close(fd);
}

void simple_redirection_left(mysh_t *mysh, env_t *env)
{
    char **arr = my_str_to_word_array(mysh->line, "<");
    int fd = open(clear_string(arr[1]), O_RDWR);
    char **tmp = NULL;
    pid_t child = 0;

    if (fd == -1) {
        my_printf("%s: No such file or directory.\n", clear_string(arr[1]));
        return;
    }
    child = fork();
    if (child == 0) {
        dup2(fd, STDIN_FILENO);
        tmp = my_str_to_word_array(arr[0], " ");
        if (parsing_path(mysh->path, tmp[0], mysh) == 1)
            execve(mysh->real_path, tmp, my_env_to_array(&env));
        else
            my_printf("%s: Command not found.\n", tmp[0]);
    } else
        waitpid(child, NULL, WUNTRACED);
    close(fd);
}

void double_redirection_right(mysh_t *mysh, env_t *env)
{
    char **arr = my_str_to_word_array(mysh->line, ">>");
    int fd = open(clear_string(arr[1]), O_CREAT | O_WRONLY, 0644);
    char **tmp = NULL;
    pid_t child = 0;

    if (fd == -1) {
        my_printf("%s: No such file or directory.\n", clear_string(arr[1]));
        return;
    }
    child = fork();
    if (child == 0) {
        dup2(fd, STDOUT_FILENO);
        lseek(fd, 0, SEEK_END);
        tmp = my_str_to_word_array(arr[0], " ");
        if (parsing_path(mysh->path, tmp[0], mysh) == 1)
            execve(mysh->real_path, tmp, my_env_to_array(&env));
        else
            my_printf("%s: Command not found.\n", tmp[0]);
    } else
        waitpid(child, NULL, WUNTRACED);
    close(fd);
}
